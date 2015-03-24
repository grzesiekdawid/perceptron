
#include "TestRunner.h"

int main(int argc, const char * argv[]) {

//    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/cancer.txt";
//    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/data.txt";

    string fileName = "/Users/grzegorzdawidko/projects/Perceptron/Perceptron/data/xyk.txt";
    vector<int> classes = {1,2,3};
    TestRunner testRunner(classes, fileName);
    testRunner.run();

    string testValues = "3,0";
    testRunner.test(testValues);

    return 0;
}
