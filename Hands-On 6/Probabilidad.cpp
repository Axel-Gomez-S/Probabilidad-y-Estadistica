#include "Probabilidad.hpp"
#include <iostream>
#include <iomanip>

Probabilidad::Probabilidad() {
    // Fila 0: Llueve {Nublado, No nublado}
    dataset[0][0] = 7.0; 
    dataset[0][1] = 3.0;
    
    // Fila 1: No llueve {Nublado, No nublado}
    dataset[1][0] = 2.0; 
    dataset[1][1] = 6.0;

    eventosA[0] = "Nublado (A)";
    eventosA[1] = "No nublado (A')";
    eventosB[0] = "Llueve (B)";
    eventosB[1] = "No llueve (B')";

    totalA[0] = totalA[1] = 0.0;
    totalB[0] = totalB[1] = 0.0;
    granTotal = 0.0;

    calcularTotales();
}

void Probabilidad::calcularTotales() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            totalB[i] += dataset[i][j];
            totalA[j] += dataset[i][j];
            granTotal += dataset[i][j];
        }
    }
}

void Probabilidad::mostrarMarginales() const {
    std::cout << "1. Probabilididades Marginales:\n";
    std::cout << "-----------------------------------------\n";
    for (int j = 0; j < 2; ++j) {
        std::cout << "P(" << eventosA[j] << ") = " << totalA[j] << " / " << granTotal 
                  << " = " << (totalA[j] / granTotal) << "\n";
    }
    for (int i = 0; i < 2; ++i) {
        std::cout << "P(" << eventosB[i] << ") = " << totalB[i] << " / " << granTotal 
                  << " = " << (totalB[i] / granTotal) << "\n";
    }
    std::cout << "\n";
}

void Probabilidad::mostrarConjuntas() const {
    std::cout << "2. Probabilidades Conjuntas:\n";
    std::cout << "-----------------------------------------\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "P(" << eventosA[j] << " y " << eventosB[i] << ") = " 
                      << dataset[i][j] << " / " << granTotal 
                      << " = " << (dataset[i][j] / granTotal) << "\n";
        }
    }
    std::cout << "\n";
}

void Probabilidad::mostrarCondicionales() const {
    std::cout << "3. Probabilidades Condicionales:\n";
    std::cout << "-----------------------------------------\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            // P(A|B) = Intersección / Total Fila B
            double pAdadoB = dataset[i][j] / totalB[i];
            std::cout << "P(" << eventosA[j] << " | " << eventosB[i] << ") = " 
                      << dataset[i][j] << " / " << totalB[i] << " = " << pAdadoB << "\n";
            
            // P(B|A) = Intersección / Total Columna A
            double pBdadoA = dataset[i][j] / totalA[j];
            std::cout << "P(" << eventosB[i] << " | " << eventosA[j] << ") = " 
                      << dataset[i][j] << " / " << totalA[j] << " = " << pBdadoA << "\n";
        }
    }
}

void Probabilidad::Resultados() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "--- Resultados ---\n";
    mostrarMarginales() ;
    mostrarConjuntas() ;
    mostrarCondicionales() ;
}