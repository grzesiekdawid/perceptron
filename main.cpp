

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    int rejectedValue = 0;//4;
    int acceptedValue = 1;//2;
//    std::string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/cancer.txt";
    std::string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data.txt";

    Perceptron *perc = new Perceptron(acceptedValue, rejectedValue);

    perc->loadTrainingSetsFromFile(fileName);
    perc->displayTrainingSet();

    perc->learn();

//    bool isCorrect = perc->test("6,8,7,8,6,8,8,9,1", 4);
//    std::cout << "is correct: " << isCorrect << std::endl;

    return 0;
}
