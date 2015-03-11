
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>

class Perceptron {
    
private:
    
    double threshold;
    double learningRate;
    int acceptedValue;
    int rejectedValue;
    std::vector<long double> weights;
    
    std::list<std::vector<int>> trainingSet;
    std::vector<int> answers;
    
    double getWeightedSum(std::vector<int> values);
    
    void incWeights(std::vector<int> values);
    
    void decWeights(std::vector<int> values);

    void parseData();

    void setAnswers();

    void setWeights();

    void appendToFile(std::string line);

    void clearResultsFile();

    std::vector<int> stringToVec(std::string string);
    
public:
    
    Perceptron(int acceptedValue, int rejectedValue);

    void learn();

    void printWeights();

    void loadTrainingSetsFromFile(std::string path);

    void displayTrainingSet();
    
    bool test(std::string values, int answer);
    
};