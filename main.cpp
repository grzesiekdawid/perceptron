
#include "TestRunner.h"

int main(int argc, const char * argv[]) {

//    int acceptedValue = 2;
//    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/cancer.txt";
//    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/xyk.txt";
    string testValues = "1, 0, 1";
    vector<int> classes = {1};
    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/data.txt";

    TestRunner testRunner(classes, fileName);
    testRunner.run();
    testRunner.test(testValues);

    return 0;
}
