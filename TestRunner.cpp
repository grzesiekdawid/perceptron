
#include "TestRunner.h"

TestRunner::TestRunner(vector<int> classes, string dataFileName) {
    for (auto acceptedValue : classes) {
        Perceptron *perc = new Perceptron(acceptedValue);
        perc->loadTrainingSetsFromFile(dataFileName);
        neurons.push_back(*perc);
    }
}

void TestRunner::run() {
//    neurons.front().displayTrainingSet();
    for (auto &perc : neurons) {
        perc.learn();
    }
    for (auto &perc : neurons) {
        cout<<"Accepted v: "<<perc.getAcceptedValue()<<" | weights: ";
        perc.printWeights();
    }
    cout<<endl;
}

void TestRunner::test(string values) {
    double sigmoid = -1;
    for (auto perc : neurons) {
        sigmoid = perc.calculateSigmoid(values);
        cout<<"Class: k"<<perc.getAcceptedValue()<<" | sigmoid: "<<sigmoid<<endl;
    }
    cout<<endl;
}