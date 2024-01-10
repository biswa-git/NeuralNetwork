#include<Output.hpp>

Output::Output(const int& number_of_neurons, const std::string& activation_function) : m_number_of_neurons(number_of_neurons), m_activation_function(activation_function)
{
}

Output::~Output()
{
}

int Output::get_number_of_neurons()
{
	return m_number_of_neurons;
}