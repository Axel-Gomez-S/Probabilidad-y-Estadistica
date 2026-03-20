#ifndef Regresion_Hpp
#define Regresion_Hpp
#include <vector>
#include <string>

class Regresion {
private:
    double b0;
    double b1; 

public:
    Regresion();
    
    void calcularCoeficientes(const std::vector<double>& x, const std::vector<double>& y);
    
    double predecir(double x);
    
    std::string obtenerEcuacion();
};

#endif
