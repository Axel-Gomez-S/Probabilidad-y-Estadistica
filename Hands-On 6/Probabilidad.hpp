#ifndef Probabilidad_hpp
#define Probabilidad_hpp

#include <string>

class Probabilidad {
private:
    
    double dataset[2][2];
    
    // Totales marginales y gran total
    double totalA[2];  // Columnas: Nublado, No nublado
    double totalB[2];  // Filas: Llueve, No llueve
    double granTotal;

    std::string eventosA[2];
    std::string eventosB[2];

    void calcularTotales();

public:
    
    Probabilidad();
    void mostrarMarginales() const;
    void mostrarConjuntas() const;
    void mostrarCondicionales() const;
    void Resultados() const;
};

#endif 