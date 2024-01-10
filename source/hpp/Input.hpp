#pragma once
#include<Layer.hpp>

class Input: public Layer
{
public:
	Input(const int& = 0);
	~Input();
	int get_number_of_neurons();
private:
	int m_number_of_neurons;
};
