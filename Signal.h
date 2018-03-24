//
// Created by victor on 24/03/18.
//

#ifndef VOICERECOGNITION_SIGNAL_H
#define VOICERECOGNITION_SIGNAL_H
#define TWO_PI 6.28318530718

#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
#include<vector>

using namespace std::complex_literals;

class Signal {
private:
    std::vector<std::complex<double>> values;
public:
    Signal(std::vector<std::complex<double>> values);
    ~Signal();
    std::vector<double> getModule();
    std::vector<double> getPhase();
    Signal getNDFT(int N);
    unsigned long getSize();
    std::string toString();
    Signal operator+(Signal a);
    Signal operator-(Signal a);
    Signal operator*(Signal a);
    Signal operator/(Signal a);
};


#endif //VOICERECOGNITION_SIGNAL_H
