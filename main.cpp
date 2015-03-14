

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    int acceptedValue = 2;
    int rejectedValue = 4;
    std::string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/cancer.txt";

    Perceptron *perc = new Perceptron(acceptedValue, rejectedValue);

    perc->loadTrainingSetsFromFile(fileName);
    perc->displayTrainingSet();

    perc->learn();

    bool isCorrect = perc->test("6,8,7,8,6,8,8,9,1", 4);
    std::cout << "is correct: " << isCorrect << std::endl;

    return 0;
}
