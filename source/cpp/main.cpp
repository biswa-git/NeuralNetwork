#include<NeuralNetwork.hpp>
#include<Sequential.hpp>

int main()
{
	Model* model = new Sequential();
	model->add(new Input(1));
	model->add(new Dense(4, "relu"));
	model->add(new Output(5, "linear"));

	model->compile();

	Eigen::VectorXd x_train(1), y_train(1);

	for (int i = -20; i < 21; i++)
	{
		double x = i / 1.0;
		x_train << x;
		y_train << x*x;
		model->fit(x_train, y_train);
	}
	

	

	//NeuralNetwork nn;
	//nn.set_model(model);

	return 0;
}