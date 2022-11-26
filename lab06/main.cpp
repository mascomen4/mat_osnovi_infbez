#include <iostream>
#include "src/NumberDecompositionHelper.h"
#include <GCDHelder.h>

using namespace std;

int main() {
    int a = NumberDecompositionHelper::pPollardMethod(1359331, 1);
    cout << a;
    return 0;
}
