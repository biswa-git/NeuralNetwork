#pragma once
#include<Layer.hpp>
#include<Eigen/Core>
#include<vector>

class Dense: public Layer
{
public:
	Dense(const int& = 0, const std::string& = "gelu");
	~Dense();
	int get_number_of_neurons();
	std::string get_activaton_type();
private:
	int m_number_of_neurons;
	std::string m_activation_function;
};
