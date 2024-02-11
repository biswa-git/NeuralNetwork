#include<iostream>
#include<Eigen/Core>
#include <cmath>
#include <algorithm>
#define M_PI 3.14159265359
// Base class for activation functions
class ActivationFunction {
public:
    virtual Eigen::VectorXd activate(const Eigen::VectorXd& input) const = 0;
    virtual Eigen::VectorXd derivative(const Eigen::VectorXd& input) const = 0;
    virtual ~ActivationFunction() {}
};

// Derived class for the sigmoid activation function
class SigmoidActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        return 1.0 / (1.0 + (-input.array()).exp());
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        Eigen::VectorXd sigmoid = activate(input);
        return sigmoid.array() * (1.0 - sigmoid.array());
    }
};

// Derived class for the ReLU activation function
class ReLUActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        return input.cwiseMax(0.0);
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        return (input.array() > 0.0).select(Eigen::VectorXd::Ones(input.size()), 0.0);
    }
};

// Derived class for the Linear activation function
class LinearActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        return input;
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        return Eigen::VectorXd::Ones(input.size());
    }
};

// Derived class for the GELU activation function
class GELUActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        return 0.5 * input.array() * (1.0 + tanh(sqrt(2.0 / M_PI) * (input.array() + 0.044715 * input.array().pow(3))));
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        Eigen::VectorXd cdf = 0.5 * (1.0 + tanh(sqrt(2.0 / M_PI) * (input.array() + 0.044715 * input.array().pow(3))));
        return 0.5 + 0.5 * cdf.array() * (1.0 - cdf.array());
    }
};

// Derived class for the GELU activation function
class UnitActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        return Eigen::VectorXd::Ones(input.size());
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        return Eigen::VectorXd::Zero(input.size());
    }
};

class SoftmaxActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override {
        Eigen::VectorXd expInput = input.array().exp();
        return expInput / expInput.sum();
    }

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override {
        // Derivative of softmax is not implemented, as it requires Jacobian matrix
        throw std::runtime_error("Softmax derivative is not directly implemented. Use softmax with cross-entropy loss for training.");
    }
};

