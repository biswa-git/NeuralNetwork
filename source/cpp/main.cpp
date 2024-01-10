#include<NeuralNetwork.hpp>
#include<Sequential.hpp>

int main()
{
	Model* model = new Sequential();
	model->add(new Input(1));
	model->add(new Dense(10, "relu"));
	model->add(new Dense(10, "relu"));
	model->add(new Dense(10, "sigmoid"));
	model->add(new Output(1));

	model->compile();

	Eigen::VectorXd x_train(4), y_train(4);
	x_train << 1, 2, 3, 4;
	y_train << 1, 4, 9, 16;

	model->fit(x_train, y_train);

	NeuralNetwork nn;
	nn.set_model(model);

	return 0;
}