#include<Layer.hpp>

std::map<std::string, ACTIVATION_TYPE> Layer::activation_type_map =
{
	{"linear", ACTIVATION_TYPE::LINEAR_ACTIVATION},
	{"relu", ACTIVATION_TYPE::RELU_ACTIVATION},
	{"gelu", ACTIVATION_TYPE::GELU_ACTIVATION},
	{"sigmoid", ACTIVATION_TYPE::SIGMOID_ACTIVATION}
};

Layer::Layer()
{
}

Layer::~Layer()
{
}