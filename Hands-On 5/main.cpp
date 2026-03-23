#include <vector>
#include "Tendencia.hpp"

int main() {
    std::vector<double> Datos = {
        25, 28, 30, 31, 35, 38, 40, 42, 43, 44, 
        45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 
        56, 58, 60, 61, 62, 65, 68, 69, 70, 75, 78
    };

    Analizar datos(Datos);
    datos.generarTabla();
    datos.mostrarResultados();

    return 0;
}