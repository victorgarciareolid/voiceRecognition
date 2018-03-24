#include <iostream>
#include "Signal.h"

#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include<vector>

using namespace std;
using namespace complex_literals;

int main() {

    vector<complex<double>> hola = {1.0i,-1.0, 1.0, -1.0};
    vector<complex<double>> adios = {0.0i, 2.0, 1.0, -1.0};

    Signal a = Signal(hola);
    Signal b = Signal(adios);

    cout << a.getNDFT(10).toString() << '\n';

    cout << (a+b).toString() << '\n';
    cout << (a*b).toString() << '\n';

    cout << "Finish" << '\n';
    getchar();
    return 0;
}