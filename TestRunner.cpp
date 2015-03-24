
#include "TestRunner.h"

TestRunner::TestRunner(vector<int> classes, string dataFileName) {
    for (auto acceptedValue : classes) {
        Perceptron *perc = new Perceptron(acceptedValue);
        perc->loadTrainingSetsFromFile(dataFileName);
        neurons.push_back(*perc);
    }
}

void TestRunner::run() {
    neurons.front().displayTrainingSet();
    for (auto &perc : neurons) {
        perc.learn();
    }
}

void TestRunner::test(string values) {
    double sigmoid = -1;
    for (auto perc : neurons) {
        sigmoid = perc.calculateSigmoid(values);
        cout<<"sigmoid: "<<sigmoid<<" | accepted v: "<<perc.getAcceptedValue()<<endl<<endl;
    }
}