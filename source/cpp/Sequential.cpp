#include<Sequential.hpp>
#include<iostream>
#include<fstream>

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
	std::cout << "input neurons -> " << m_layers[0]->get_number_of_neurons() << std::endl;
	data.emplace_back(Eigen::VectorXd(m_layers[0]->get_number_of_neurons()));
	weight.emplace_back(Eigen::MatrixXd());
	bias.emplace_back(Eigen::VectorXd());

	for (size_t i = 1; i < m_layers.size(); i++)
	{
		std::cout << "layer"<<std::to_string(i) << "neurons -> " << m_layers[0]->get_number_of_neurons() << std::endl;
		data.emplace_back(Eigen::VectorXd(m_layers[i]->get_number_of_neurons()));
		//weigh bias has random intialization. Need to add other types
		weight.emplace_back(Eigen::MatrixXd::Random(m_layers[i]->get_number_of_neurons(), m_layers[i-1]->get_number_of_neurons()));
		bias.emplace_back(Eigen::VectorXd::Random(m_layers[i]->get_number_of_neurons()));
	}

	for (size_t i = 0; i < m_layers.size(); i++)
	{//replace by CASE struct
		if (m_layers[i]->get_activaton_type() == "")
		{
			activation.emplace_back(new UnitActivation());
		}
		if (m_layers[i]->get_activaton_type() == "relu")
		{
			activation.emplace_back(new ReLUActivation());
		}
		if (m_layers[i]->get_activaton_type() == "gelu")
		{
			activation.emplace_back(new GELUActivation());
		}
		if (m_layers[i]->get_activaton_type() == "linear")
		{
			activation.emplace_back(new LinearActivation());
		}
		if (m_layers[i]->get_activaton_type() == "softmax")
		{
			activation.emplace_back(new SoftmaxActivation());
		}
	}
	//TO BE DONE :
	// based on intializer, change the initial bias etc.
}

void Sequential::fit(Eigen::VectorXd& x_train, Eigen::VectorXd& y_train)
{
	data[0] = x_train;
	m_y_train = y_train;
	forward_propagation();
}

void Sequential::forward_propagation()
{
	//Activation activation;
	for (size_t i = 1; i < m_layers.size(); i++)
	{
		std::cout << "weight: " << weight[i] << std::endl;
		data[i] = activation[i]->activate((weight[i] * data[i - 1] + bias[i]));

#ifdef DEBUG
		std::cout << "input: \n" << data[i - 1] << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "output: \n" << data[i] << std::endl;
		std::cout << "-------------------------------------" << std::endl;
#endif // DEBUG

		
	std::ofstream myfile;
	for (size_t i = 0; i < m_layers.size(); i++)
	{
		for (size_t j = 0; j < data[i].size(); j++)
		{
			myfile.open("layer_" + std::to_string(i) + "_neuron_" + std::to_string(j) + ".txt", std::ios::out | std::ios::app);
			myfile << data[0][0] << " " << data[i][j] << std::endl;
			myfile.close();
		}
	}
}

void Sequential::write_to_file()
{

}