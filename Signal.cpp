//
// Created by victor on 24/03/18.
//

#include "Signal.h"


Signal::Signal(std::vector<std::complex<double>> values){
    this->values = values;
}

Signal::~Signal() {
    this->values.clear();
}

std::vector<double> Signal::getModule(){
    std::vector<double> aux (getSize());
    std::vector<std::complex<double>>::iterator it;
    int i=0;
    for(it=this->values.begin(); it!=this->values.end(); ++it, i++){
        aux[i] = std::abs(*it);
    }

    return aux;
}

std::vector<double> Signal::getPhase(){
    std::vector<double> aux (getSize());
    std::vector<std::complex<double>>::iterator it;
    int i=0;
    for(it=this->values.begin(); it!=this->values.end(); ++it, i++){
        aux[i] = std::arg(*it);
    }

    return aux;
}

Signal Signal::getNDFT(int N){
    using namespace std::complex_literals;

    int k;
    unsigned long L = getSize();
    std::vector<std::complex<double>> aux;
    std::complex<double> c_aux_sum, c_aux_exp;

    for(k=0; k<N; k++){
        for(int n=0; n<N; n++){
            if(n<L){
                c_aux_exp = 1.0i*TWO_PI*(double)n*(double)k/(double)N;
                c_aux_sum += this->values[n] * std::exp(c_aux_exp);
            }
        }
        aux.push_back(c_aux_sum);
        c_aux_sum = 0.0 + 0.0i;
    }

    return Signal(aux);
}

std::string Signal::toString(){
    std::string aux = "[ ";
    std::vector<std::complex<double>>::iterator it;

    for(it=this->values.begin(); it!=this->values.end(); it++){
        aux += "(" + std::to_string((*it).real()) + " " + std::to_string((*it).imag()) + "i) ";
    }
    aux += "]";
    return aux;
}

unsigned long Signal::getSize(){
    return values.size();
}

Signal Signal::operator+(Signal a){
    if(this->getSize() != a.getSize()) throw std::runtime_error("Dimensions differ");
    std::vector<std::complex<double>> aux;
    std::vector<std::complex<double>>::iterator ita, itb;
    itb = this->values.begin();
    for(ita=a.values.begin(); ita!=a.values.end(); ++ita, ++itb){
        aux.push_back(((std::complex<double>)(*ita)) + ((std::complex<double>)(*itb)));
    }

    return Signal(aux);
}

Signal Signal::operator-(Signal a){
    if(this->getSize() != a.getSize()) throw std::runtime_error("Dimensions differ");
    std::vector<std::complex<double>> aux;
    std::vector<std::complex<double>>::iterator ita, itb;
    itb = this->values.begin();
    for(ita=a.values.begin(); ita!=a.values.end(); ++ita, ++itb){
        aux.push_back(((std::complex<double>)(*ita)) - ((std::complex<double>)(*itb)));
    }

    return Signal(aux);
}

Signal Signal::operator*(Signal a){
    if(this->getSize() != a.getSize()) throw std::runtime_error("Dimensions differ");
    std::vector<std::complex<double>> aux;
    std::vector<std::complex<double>>::iterator ita, itb;
    itb = this->values.begin();
    for(ita=a.values.begin(); ita!=a.values.end(); ++ita, ++itb){
        aux.push_back(((std::complex<double>)(*ita)) * ((std::complex<double>)(*itb)));
    }

    return Signal(aux);
}

Signal Signal::operator/(Signal a){
    if(this->getSize() != a.getSize()) throw std::runtime_error("Dimensions differ");
    std::vector<std::complex<double>> aux;
    std::vector<std::complex<double>>::iterator ita, itb;
    itb = this->values.begin();
    for(ita=a.values.begin(); ita!=a.values.end(); ++ita, ++itb){
        aux.push_back(((std::complex<double>)(*ita)) / ((std::complex<double>)(*itb)));
    }

    return Signal(aux);
}
