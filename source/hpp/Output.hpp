#pragma once
#include<Layer.hpp>

class Output : public Layer
{
public:
	Output(const int& number_of_neurons = 0, const std::string& activation_function = "linear");
	~Output();
	int get_number_of_neurons();
	std::string get_activaton_type();
private:
	int m_number_of_neurons;
	std::string m_activation_function;
};
