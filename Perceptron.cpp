
#include "Perceptron.h"


Perceptron::Perceptron() {
//    training_set[0][0] = 1;
//    training_set[0][1] = 1;
//    training_set[0][2] = 0;
//    answers[0] = 1; // correct
//    
//    training_set[1][0] = 1;
//    training_set[1][1] = 0;
//    training_set[1][2] = 1;
//    answers[1] = 0; // incorrect
}

void Perceptron::learn() {
//    bool error;
//    do {
//        error = false;
//        for (int i = 0; i < trainingSetSize; i++) {
//            
//            if ( (getWeightedSum(training_set[i], weights, trainingSetSize) < threshold) && (answers[i] == 1) ) {
//                error = true;
//                incWeights(training_set[i], weights, learning_rate, weightsAmount);
//            } else if ( (getWeightedSum(training_set[i], weights, weightsAmount) >= threshold) && (answers[i] == 0) ) {
//                error = true;
//                decWeights(training_set[i], weights, learning_rate, weightsAmount);
//            }
//            printWeights(weights, weightsAmount);
//        }
//        
//    } while (error == true);
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

void displayVector(std::vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n" << std::endl;
}


void Perceptron::displayTrainingSet() {
    for(auto vec : trainingSet) {
        for(int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }
}

std::vector<int> Perceptron::stringToVec(std::string string) {
    std::vector<int> vect;
    std::stringstream stream(string);
    
    int i;
    while (stream >> i) {
        vect.push_back(i);
        if (stream.peek() == ',') {
            stream.ignore();
        }
    }
    return vect;
}

void Perceptron::loadTrainingSetsFromFile() {
    std::ifstream file("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data.txt");
    std::list<std::vector<int>> vectors;
    
    while( file.good() ) {
        std::string value;
        getline ( file, value, '\n' );
        vectors.push_back(stringToVec(value));
    }
    this->trainingSet = vectors;
}








