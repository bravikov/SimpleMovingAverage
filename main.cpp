// Пример работы фильтра скользящего среднего

#include "SimpleMovingAverage.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    SimpleMovingAverage<5, double> sma;
    SimpleMovingAverage<10, double> sma2;
    SimpleMovingAverage<15, double> sma3(1.1);

    for (int i = 0; i < 15; i++) {
        cout << "sma:  " << i << ": " << sma.average(i)  << endl;
        cout << "sma2: " << i << ": " << sma2.average(i) << endl;
        cout << "sma3: " << i << ": " << sma3.average(i) << endl;
    }

    sma2.reset(2.2);
    sma3.reset();

    for (int i = 0; i < 20; i++) {
        cout << "sma:  " << i << ": " << sma.average(i)  << endl;
        cout << "sma2: " << i << ": " << sma2.average(i) << endl;
        cout << "sma3: " << i << ": " << sma3.average(i) << endl;
    }

    return 0;
}
