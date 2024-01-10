#include<Input.hpp>

Input::Input(const int& number_of_neurons) : m_number_of_neurons(number_of_neurons)
{
}

Input::~Input()
{
}

int Input::get_number_of_neurons()
{
	return m_number_of_neurons;
}
