
#include "Perceptron.h"

Perceptron::Perceptron(int acceptedValue) {
    this->bias = 2;
    this->learningRate = 0.1;//0.001;
    this->acceptedValue = acceptedValue;
    clearResultsFile();
}

void Perceptron::clearResultsFile() {
    ofstream ofs;
    ofs.open("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/results.txt", ofstream::out | ofstream::trunc);
    ofs.close();
}

void Perceptron::learn() {
    bool error;
    int step = 0;
    do {
        error = false;
        int i = 0;
        for (auto values : trainingSet) {
            if ( (sigmoid(values) <= 0.5) && (answers[i] == acceptedValue) ) {
                error = true;
                incWeights(values);
            } else if ( (sigmoid(values) > 0.5) && (answers[i] != acceptedValue) ) {
                error = true;
                decWeights(values);
            }
            printWeights();
            cout<<"step: "<<++step<<" | sig: "<<sigmoid(values)<<" | ans: "<<answers[i]<<" | accepted v: "<<acceptedValue<<endl<<endl;
            i++;
        }
        
    } while (error == true);
}

double Perceptron::sigmoid(vector<int> values) {
    double sum = getWeightedSum(values) + bias;
    return 1/(1 + exp(-sum));
}

double Perceptron::getWeightedSum(vector<int> values) {
    return inner_product(weights.begin(), weights.end(), values.begin(), 0);
}

void Perceptron::incWeights(vector<int> values) {
    for (int i = 0; i < weights.size(); i++) {
        weights[i] += learningRate * values[i];
    }
}

void Perceptron::decWeights(vector<int> values) {
    for (int i = 0; i < weights.size(); i++) {
        weights[i] += learningRate * values[i] * -1;
    }
}

void Perceptron::appendToFile(string line) {
    ofstream file;
    file.open ("/Users/grzegorzdawidko/projects/Perceptron/Perceptron/results.txt", ofstream::out | ofstream::app);
    file << line << "\n";
    file.close();
}

void Perceptron::printWeights() {
    string line;
    for (auto w : weights) {
        line += to_string(w) + ", ";
    }
    cout << line << "\n";
    appendToFile(line);
}

void displayVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n" << endl;
}


void Perceptron::displayTrainingSet() {
    for (auto vec : trainingSet) {
        for (auto value : vec) {
            cout << value << " ";
        }
        cout << "\n" << endl;
    }
    
    cout << "Answers: \n" << endl;
    for (auto answer : answers) {
        cout << answer << endl << endl;
    }
}

vector<int> Perceptron::stringToVec(string string) {
    vector<int> vect;
    stringstream stream(string);
    
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
//        weights.push_back(0.001);
    }
}

void Perceptron::parseData() {
    setAnswers();
    setWeights();
}

void Perceptron::loadTrainingSetsFromFile(string path) {
    ifstream file(path);
    list<vector<int>> vectors;
    
    while( file.good() ) {
        string value;
        getline ( file, value, '\n' );
        vectors.push_back(stringToVec(value));
    }
    trainingSet = vectors;
    parseData();
}

double Perceptron::calculateSigmoid(string values) {
    return sigmoid(stringToVec(values));
}

int Perceptron::getAcceptedValue() {
    return acceptedValue;
}







