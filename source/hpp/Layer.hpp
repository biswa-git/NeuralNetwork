#pragma once
#include<string>
#include<map>

enum class ACTIVATION_TYPE
{
	LINEAR_ACTIVATION,
	RELU_ACTIVATION,
	GELU_ACTIVATION,
	SIGMOID_ACTIVATION,
	N_ACTIVATION_TYPE
};

class Layer
{
public:
	Layer();
	~Layer();

	static std::map<std::string, ACTIVATION_TYPE> activation_type_map;
	virtual int get_number_of_neurons() = 0;
private:
};
