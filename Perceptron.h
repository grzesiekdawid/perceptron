
//#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>

class Perceptron {
    
private:
    
    double threshold = 2;
    double learning_rate = 0.1;
    std::vector<double> weights = {1, 1, 1};
    
    std::list<std::vector<int>> trainingSet;
    std::vector<int> answers;
    
public:
    
    Perceptron();
    
    void learn();
    
    double getWeightedSum(std::vector<int> values);
    
    void incWeights(std::vector<int> values);
    
    void decWeights(std::vector<int> values);
    
    void printWeights();
    
    void parseData(std::list<std::vector<int>> &vectors);
    
    void loadTrainingSetsFromFile();
    
    void displayTrainingSet();
    
    std::vector<int> stringToVec(std::string string);
};