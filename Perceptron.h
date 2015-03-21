
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>
#include <numeric>

using namespace std;

class Perceptron {

public:

    Perceptron(int acceptedValue);

    void learn();

    void printWeights();

    void loadTrainingSetsFromFile(string path);

    void displayTrainingSet();

    double calculateSigmoid(string values);

    int getAcceptedValue();

private:
    
    double bias;
    double learningRate;
    int acceptedValue;
    vector<long double> weights;
    
    list<vector<int>> trainingSet;
    vector<int> answers;

    double sigmoid(vector<int> values);

    double getWeightedSum(vector<int> values);
    
    void incWeights(vector<int> values);
    
    void decWeights(vector<int> values);

    void parseData();

    void setAnswers();

    void setWeights();

    void appendToFile(string line);

    void clearResultsFile();

    vector<int> stringToVec(string string);

};