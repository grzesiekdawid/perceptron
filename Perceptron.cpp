
#include "Perceptron.h"


class Perceptron {
    
private:
    
    double threshold = 2;
    double learning_rate = 0.1;
    double weights[3] = {1, 1, 1};
    int weightsAmount = 3;
    
    int training_set[2][3]; // 0 - dog, 1 - cat
    int answers[2];
    
    int trainingSetSize = 2;
    
public:
    
    Perceptron() {
        training_set[0][0] = 1;
        training_set[0][1] = 1;
        training_set[0][2] = 0;
        answers[0] = 1; // correct
        
        training_set[1][0] = 1;
        training_set[1][1] = 0;
        training_set[1][2] = 1;
        answers[1] = 0; // incorrect
    }
    
    void learn() {
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
    
    double getWeightedSum(int values[], double weights[], int weightsAmount) {
        double sum = 0;
        for (int i = 0; i < weightsAmount; i++) {
            sum += weights[i] * values[i];
        }
        return sum;
    }
    
    void incWeights(int values[], double weights[], double learning_rate, int weightsAmount) {
        for (int i = 0; i < weightsAmount; i++) {
            weights[i] += weights[i] * learning_rate * values[i];
        }
    }
    
    void decWeights(int values[], double weights[], double learning_rate, int weightsAmount) {
        for (int i = 0; i < weightsAmount; i++) {
            weights[i] -= weights[i] * learning_rate * values[i];
        }
    }
    
    void printWeights(double weights[], int weightsAmount) {
        for (int i = 0; i < weightsAmount; i++) {
            std::cout << weights[i] << ", ";
        }
        std::cout << "\n";
    }

    
//    void loadTrainingSetsFromFile();
};