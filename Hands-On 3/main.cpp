#include <iostream>
#include <vector>
#include "Frecuencia.hpp"

int main() {
    // DataSet
    std::vector<double> Datos = {1.5, 2.3, 1.5, 3.0, 2.3, 1.5, 4.2, 3.0, 1.5, 2.3};

    Analizar Analisis(Datos);

    Analisis.generarTabla();
    
    Analisis.mostrarResultados();

    return 0;
}