

#include "Perceptron.h"


int main(int argc, const char * argv[]) {

    Perceptron *perc = new Perceptron();
//    perc->learn();
    
    perc->loadTrainingSetsFromFile();
    perc->displayTrainingSet();

    return 0;
}


