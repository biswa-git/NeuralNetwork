#include<Sequential.hpp>
#include<iostream>

Sequential::Sequential()
{
}

Sequential::~Sequential()
{
}

void Sequential::add(Layer* layer)
{
	m_layers.push_back(layer);
}

void Sequential::compile()
{
	//std::vector<Eigen::VectorXd> data;
	//std::vector<Eigen::MatrixXd> weight;
	//std::vector<Eigen::VectorXd> bias;

	//dummy weight bias for input layer
	data.emplace_back(Eigen::VectorXd(m_layers[0]->get_number_of_neurons()));
	weight.emplace_back(Eigen::MatrixXd());
	bias.emplace_back(Eigen::VectorXd());

	for (size_t i = 1; i < m_layers.size(); i++)
	{
		data.emplace_back(Eigen::VectorXd(m_layers[i]->get_number_of_neurons()));
		//weight init with value 1
		weight.emplace_back(Eigen::MatrixXd(m_layers[i]->get_number_of_neurons(), m_layers[i-1]->get_number_of_neurons(), 1));
		bias.emplace_back(Eigen::VectorXd(m_layers[i]->get_number_of_neurons()));
	}
}

void Sequential::fit(Eigen::VectorXd& x_train, Eigen::VectorXd& y_train)
{
	data[0] = x_train;
	forward_propagation();
}

void Sequential::forward_propagation()
{
	//Activation activation;
	for (size_t i = 1; i < m_layers.size(); i++)
	{
		data[i] = weight[i] * data[i - 1] + bias[i];
		std::cout << "input: \n" << data[i - 1] << std::endl;
		std::cout << "output: \n" << data[i] << std::endl;
		//m_layer[i].ApplyActivation();
		//std::cout << "output after activation: \n" << m_layer[i].GetData() << std::endl;
	}
}
