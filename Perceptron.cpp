
#include "Perceptron.h"


Perceptron::Perceptron(int acceptedValue, int rejectedValue) {
    this->threshold = 2;
    this->learningRate = 0.1;
    this->acceptedValue = acceptedValue;
    this->rejectedValue = rejectedValue;
    clearResultsFile();
}

void Perceptron::clearResultsFile() {
    std::ofstream ofs;
    ofs.open("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/results.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void Perceptron::learn() {
    bool error;
    do {
        error = false;
        int i = 0;
        for (auto values : trainingSet) {
            if ( (getWeightedSum(values) < threshold) && (answers[i] == acceptedValue) ) {
                error = true;
                incWeights(values);
            } else if ( (getWeightedSum(values) >= threshold) && (answers[i] == rejectedValue) ) {
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
        weights[i] += learningRate * values[i];
//        weights[i] = floor(weights[i] * 1000 + 0.5) / 1000;
    }
}

void Perceptron::decWeights(std::vector<int> values) {
    for (int i = 0; i < weights.size(); i++) {
        weights[i] += learningRate * values[i] * -1;
//        weights[i] = floor(weights[i] * 1000 + 0.5) / 1000;
    }
}

void Perceptron::appendToFile(std::string line) {
    std::ofstream file;
    file.open ("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/results.txt", std::ofstream::out | std::ofstream::app);
    file << line << "\n";
    file.close();
}

void Perceptron::printWeights() {
    std::string line;
    for (auto w : weights) {
        line += std::to_string(w) + ", ";
    }
    std::cout << line << "\n";
    appendToFile(line);
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

void Perceptron::setAnswers() {
    for(auto &vec : trainingSet) {
        answers.push_back(vec.back());
        vec.pop_back();
    }
}

void Perceptron::setWeights() {
    int weightsAmount = (int) trainingSet.front().size();
    for (int i = 0; i < weightsAmount; i++) {
        weights.push_back(0.01);
    }
}

void Perceptron::parseData() {
    setAnswers();
    setWeights();
}

void Perceptron::loadTrainingSetsFromFile(std::string path) {
    std::ifstream file(path);
    std::list<std::vector<int>> vectors;
    
    while( file.good() ) {
        std::string value;
        getline ( file, value, '\n' );
        vectors.push_back(stringToVec(value));
    }
    trainingSet = vectors;
    parseData();
}

bool Perceptron::test(std::string values, int answer) {
    bool isClassifiedCorrect = false;
    double sum = getWeightedSum(stringToVec(values));
    if ( ((sum < threshold) && (answer == rejectedValue)) || ((sum >= threshold) && (answer == acceptedValue)) ) {
        isClassifiedCorrect = true;
    }
    return isClassifiedCorrect;
}









