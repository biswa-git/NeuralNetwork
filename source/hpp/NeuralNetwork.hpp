#pragma once
#include <Model.hpp>

class NeuralNetwork
{
public:
	NeuralNetwork();
	~NeuralNetwork();
	void set_model(Model*);
private:
	Model* m_model;
};
