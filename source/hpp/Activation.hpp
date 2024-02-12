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
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;

    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

// Derived class for the ReLU activation function
class ReLUActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;
    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

// Derived class for the Linear activation function
class LinearActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;
    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

// Derived class for the GELU activation function
class GELUActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;
    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

// Derived class for the Unit activation function
class UnitActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;
    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

// Derived class for the SoftMax activation function
class SoftmaxActivation : public ActivationFunction {
public:
    Eigen::VectorXd activate(const Eigen::VectorXd& input) const override;
    Eigen::VectorXd derivative(const Eigen::VectorXd& input) const override;
};

