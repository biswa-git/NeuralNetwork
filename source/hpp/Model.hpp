#pragma once
#include<Layer.hpp>
#include<Eigen/Core>

class Model
{
public:
	Model();
	~Model();
	virtual void add(Layer*) = 0;
	virtual void compile() = 0;
	virtual void fit(Eigen::VectorXd&, Eigen::VectorXd&) = 0;
private:
};
