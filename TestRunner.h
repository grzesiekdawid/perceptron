
#include <stdio.h>
#include "Perceptron.h"

using namespace std;

class TestRunner {

public:

    TestRunner(vector<int> classes, string dataFileName);

    void run();

    void test(string values);

private:

    list<Perceptron> neurons;
    
};
