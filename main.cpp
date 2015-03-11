

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    int acceptedValue = 2;
    int rejectedValue = 4;
    std::string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/cancer.txt";

//    int acceptedValue = 1;
//    int rejectedValue = 0;
//    std::string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data.txt";

    Perceptron *perc = new Perceptron(acceptedValue, rejectedValue);

    perc->loadTrainingSetsFromFile(fileName);
    perc->displayTrainingSet();

    perc->learn();

    bool isCorrect = perc->test("6,1,1,1,2,1,3,1,1", 2);
    std::cout << "is correct: " << isCorrect << std::endl;

//    bool isCorrect = perc->test("1, 0, 1", 0);
//    std::cout << "is correct: " << isCorrect << std::endl;

    return 0;
}

/*
 * pytania:
 * - inicjalizacja:
 * threshold = ?
 * weights = ?
 * learning rate = ?
 */