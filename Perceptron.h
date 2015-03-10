
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>

class Perceptron {
    
private:
    
    double threshold;
    double learningRate;
    std::vector<double> weights;
    
    std::list<std::vector<int>> trainingSet;
    std::vector<int> answers;
    
    double getWeightedSum(std::vector<int> values);
    
    void incWeights(std::vector<int> values);
    
    void decWeights(std::vector<int> values);

    void parseData(std::list<std::vector<int>> &vectors);
    
    std::vector<int> stringToVec(std::string string);
    
public:
    
    Perceptron(double threshold, double learningRate, std::vector<double> weights);

    void learn();

    void printWeights();

    void loadTrainingSetsFromFile();

    void displayTrainingSet();
    
};