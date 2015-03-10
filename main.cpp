

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    double threshold = 2;
    double learningRate = 0.1;
    std::vector<double> weights = {1, 1, 1};
    Perceptron *perc = new Perceptron(threshold, learningRate, weights);

    perc->loadTrainingSetsFromFile();
    perc->displayTrainingSet();

    perc->learn();

    return 0;
}


