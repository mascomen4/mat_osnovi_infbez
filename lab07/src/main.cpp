#include <iostream>
#include "../include/DicreteLogarithmHelper.h"

int main()
{
    int a = 10, b = 64, m = 107;
    cout << DicreteLogarithmHelper::discreteLogarithm(a, b, m) << endl;

    a = 3, b = 7, m = 11;
    cout << DicreteLogarithmHelper::discreteLogarithm(a, b, m) << endl;
}
