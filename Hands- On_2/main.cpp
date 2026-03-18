#include <iostream>
#include <vector>
#include <iomanip>
#include "Regresion.hpp"

int main() {
    // Datos del Caso Benetton
    std::vector<double> publicidad = {43.60, 50.44, 59.01, 66.30, 82.36, 92.15, 100.51, 110.06, 111.51};
    std::vector<double> ventas = {1261.08, 1475.28, 1657.52, 2059.05, 2303.76, 2512.64, 2751.46, 2787.67, 2939.13};

    Regresion Modelo;

    Modelo.calcularCoeficientes(publicidad, ventas);

    std::cout << "--- Resultado del Analisis ---" << std::endl;
    std::cout << "Ecuacion de Regresion: " << Modelo.obtenerEcuacion() << std::endl;
    
    std::vector<double> nuevosValores = {40.0, 75.0, 120.0, 130.0, 150.0};

    std::cout << "\nPredicciones de Ventas segun la inversion en Publicidad:" << std::endl;
    for (double p : nuevosValores) {
        double resultado = Modelo.predecir(p);
        std::cout << "Si inviertes " << p << " en publicidad, las ventas serian: " << std::fixed << std::setprecision(2) << resultado << std::endl;

        
    }
    return 0;
}