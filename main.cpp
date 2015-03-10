

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    Perceptron *perc = new Perceptron();
    perc->loadTrainingSetsFromFile();
    perc->displayTrainingSet();

    perc->learn();
    


    return 0;
}


