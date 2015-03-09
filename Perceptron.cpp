
#include "Perceptron.h"


Perceptron::Perceptron() {
    training_set[0][0] = 1;
    training_set[0][1] = 1;
    training_set[0][2] = 0;
    answers[0] = 1; // correct
    
    training_set[1][0] = 1;
    training_set[1][1] = 0;
    training_set[1][2] = 1;
    answers[1] = 0; // incorrect
}

void Perceptron::learn() {
    bool error;
    do {
        error = false;
        for (int i = 0; i < trainingSetSize; i++) {
            
            if ( (getWeightedSum(training_set[i], weights, trainingSetSize) < threshold) && (answers[i] == 1) ) {
                error = true;
                incWeights(training_set[i], weights, learning_rate, weightsAmount);
            } else if ( (getWeightedSum(training_set[i], weights, weightsAmount) >= threshold) && (answers[i] == 0) ) {
                error = true;
                decWeights(training_set[i], weights, learning_rate, weightsAmount);
            }
            printWeights(weights, weightsAmount);
        }
        
    } while (error == true);
}

double Perceptron::getWeightedSum(int values[], double weights[], int weightsAmount) {
    double sum = 0;
    for (int i = 0; i < weightsAmount; i++) {
        sum += weights[i] * values[i];
    }
    return sum;
}

void Perceptron::incWeights(int values[], double weights[], double learning_rate, int weightsAmount) {
    for (int i = 0; i < weightsAmount; i++) {
        weights[i] += weights[i] * learning_rate * values[i];
    }
}

void Perceptron::decWeights(int values[], double weights[], double learning_rate, int weightsAmount) {
    for (int i = 0; i < weightsAmount; i++) {
        weights[i] -= weights[i] * learning_rate * values[i];
    }
}

void Perceptron::printWeights(double weights[], int weightsAmount) {
    for (int i = 0; i < weightsAmount; i++) {
        std::cout << weights[i] << ", ";
    }
    std::cout << "\n";
}


//    void loadTrainingSetsFromFile();
