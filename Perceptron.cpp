
#include "Perceptron.h"


Perceptron::Perceptron() {}

void Perceptron::learn() {
    bool error;
    do {
        error = false;
        int i = 0;
        for (auto values : trainingSet) {
            if ( (getWeightedSum(values) < threshold) && (answers[i] == 1) ) {
                error = true;
                incWeights(values);
            } else if ( (getWeightedSum(values) >= threshold) && (answers[i] == 0) ) {
                error = true;
                decWeights(values);
            }
            printWeights();
            i++;
        }
        
    } while (error == true);
}

double Perceptron::getWeightedSum(std::vector<int> values) {
    double sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        sum += weights[i] * values[i];
    }
    return sum;
}

void Perceptron::incWeights(std::vector<int> values) {
    for (int i = 0; i < weights.size(); i++) {
        if (values[i] != 0) {
            weights[i] += weights[i] * learning_rate;
        }
    }
}

void Perceptron::decWeights(std::vector<int> values) {
    for (int i = 0; i < weights.size(); i++) {
        if (values[i] != 0) {
            weights[i] -= weights[i] * learning_rate;
        }
    }
}

void Perceptron::printWeights() {
    for (auto w : weights) {
        std::cout << w << ", ";
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
    for (auto vec : trainingSet) {
        for (auto value : vec) {
            std::cout << value << " ";
        }
        std::cout << "\n" << std::endl;
    }
    
    std::cout << "Answers: \n" << std::endl;
    for (auto answer : answers) {
        std::cout << answer << std::endl << std::endl;
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

void Perceptron::parseData(std::list<std::vector<int>> &vectors) {
    for(auto &vec : vectors) {
        answers.push_back(vec.back());
        vec.pop_back();
    }
    trainingSet = vectors;

}

void Perceptron::loadTrainingSetsFromFile() {
    std::ifstream file("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data.txt");
    std::list<std::vector<int>> vectors;
    
    while( file.good() ) {
        std::string value;
        getline ( file, value, '\n' );
        vectors.push_back(stringToVec(value));
    }
    parseData(vectors);
}









