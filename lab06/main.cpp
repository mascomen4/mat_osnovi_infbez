#include <iostream>
#include "src/NumberDecompositionHelper.h"
#include <GCDHelder.h>

using namespace std;

int main() {
    int a = NumberDecompositionHelper::pPollardMethod(1359331, 1);
    cout << a << endl;
    cout << 1359331. / a;
    return 0;
}
