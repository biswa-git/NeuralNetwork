#pragma once
#include<Model.hpp>
#include<Input.hpp>
#include<Dense.hpp>
#include<Output.hpp>
#include<vector>

class Sequential: public Model
{
public:
	Sequential();
	~Sequential();
	void add(Layer*);
	void compile();
	void fit(Eigen::VectorXd&, Eigen::VectorXd&);
private:
	std::vector<Layer*> m_layers;

	std::vector<Eigen::VectorXd> data;
	std::vector<Eigen::MatrixXd> weight;
	std::vector<Eigen::VectorXd> bias;

	void forward_propagation();
};

