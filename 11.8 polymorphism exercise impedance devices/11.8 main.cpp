#include <iostream>
#include <vector>
#include <complex>

class ImpedanceDevice{
public: 

    virtual std::complex<double> get_impedance(double omega) const = 0;

    // this is a pure virtual function
    // classes which inherit from this class will have
    // an overriding method with the specific formula for that device

    virtual ~ImpedanceDevice(){}

};

class Resistor : public ImpedanceDevice{
public: 

    Resistor(double r) : resistance(r) {}

    std::complex<double> get_impedance(double omega) const{

        std::complex<double> impedance(resistance);
        return impedance;

    }

private: 

    double resistance;

};

class Capacitor : public ImpedanceDevice{
public:

    Capacitor(double c) : capacitance(c) {};

    std::complex<double> get_impedance(double omega) const{

        std::complex<double> impedance(0, (-1)/(omega * capacitance));
        return impedance;

    }

private:

    double capacitance;

};

class Inductor : public ImpedanceDevice{
public:

    Inductor(double l) : inductance(l) {};

    std::complex<double> get_impedance(double omega) const{

        std::complex<double> impedance(0, omega * inductance);
        return impedance;

    }

private:

    double inductance;

};

int main(){
    
}