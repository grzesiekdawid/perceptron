
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
    double weights[3] = {1, 1, 1};
    int weightsAmount = 3;
    
//    int training_set[2][3]; // 0 - dog, 1 - cat
//    int answers[2];
    
//    int trainingSetSize = 2;
    std::list<std::vector<int>> trainingSet;
    std::vector<int> answers;
    
public:
    
    Perceptron();
    
    void learn();
    
    double getWeightedSum(int values[], double weights[], int weightsAmount);
    
    void incWeights(int values[], double weights[], double learning_rate, int weightsAmount);
    
    void decWeights(int values[], double weights[], double learning_rate, int weightsAmount);
    
    void printWeights(double weights[], int weightsAmount);
    
    void parseData(std::list<std::vector<int>> &vectors);
    
    void loadTrainingSetsFromFile();
    
    void displayTrainingSet();
    
    std::vector<int> stringToVec(std::string string);
};