#include "Regresion.hpp"
#include <iostream>

Regresion::Regresion() {
    b0 = 0;
    b1 = 0;
}

void Regresion::calcularCoeficientes(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    double suma_x = 0, suma_y = 0, suma_xy = 0, suma_x_cuadrado = 0;

    // Calculamos las sumatorias necesarias para la fórmula de mínimos cuadrados
    for (int i = 0; i < n; i++) {
        suma_x += x[i];
        suma_y += y[i];
        suma_xy += x[i] * y[i];
        suma_x_cuadrado += x[i] * x[i];
    }

    // b1
    double numerador_b1 = (n * suma_xy) - (suma_x * suma_y);
    double denominador_b1 = (n * suma_x_cuadrado) - (suma_x * suma_x);
    b1 = numerador_b1 / denominador_b1;

    // b0
    b0 = (suma_y - (b1 * suma_x)) / n;
}

double Regresion::predecir(double x) {
    return b0 + (b1 * x);
}

std::string Regresion::obtenerEcuacion() {
    return "y = " + std::to_string(b0) + " + " + std::to_string(b1) + " * x";
}