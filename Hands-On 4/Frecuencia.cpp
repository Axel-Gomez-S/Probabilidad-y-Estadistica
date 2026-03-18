#include "Frecuencia.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm> 

Analizar::Analizar(const std::vector<double>& entrada_datos) {
    datos = entrada_datos;
    total_datos = datos.size();
    std::sort(datos.begin(), datos.end());
}

void Analizar::generarTabla() {
    
    numClases = 6; 
    
    double min = datos[0];
    double max = datos[total_datos - 1];
    double rango = max - min;
    
    anchoClase = (rango + 1) / numClases;

    double inferiorActual = min;
    int acumuladoFa = 0;
    double acumuladoFra = 0.0;

    for (int i = 1; i <= numClases; i++) {
        FilaTabla fila;
        fila.numeroClase = i;
        fila.limiteInferior = inferiorActual;
        fila.limiteSuperior = inferiorActual + anchoClase - 1;
    
        fila.puntoMedio = (fila.limiteInferior + fila.limiteSuperior) / 2.0;

        int contador = 0;
        for (double d : datos) {
            if (d >= fila.limiteInferior && d <= fila.limiteSuperior) {
                contador++;
            }
        }
        
        fila.f_absoluta = contador;
        acumuladoFa += contador;
        fila.f_acumulada = acumuladoFa;

        fila.f_relativa = (double)contador / total_datos;
        acumuladoFra += fila.f_relativa;
        fila.fr_acumulada = acumuladoFra;

        fila.porcentaje = fila.f_relativa * 100;

        tabla.push_back(fila);
        
        inferiorActual = fila.limiteSuperior + 1;
    }
}

void Analizar::mostrarResultados() {
    std::cout << std::left << std::setw(6)  << "Clase" 
              << std::setw(15) << "Limites" 
              << std::setw(6)  << "f" 
              << std::setw(8)  << "Xc" 
              << std::setw(6)  << "Fa" 
              << std::setw(8)  << "fr" 
              << std::setw(8)  << "fra" 
              << "%" << std::endl;

    for (const auto& f : tabla) {
        std::cout << std::left << std::setw(6) << f.numeroClase;
        
        
        std::cout << std::fixed << std::setprecision(0) 
                  << f.limiteInferior << "-" << std::setw(10) << f.limiteSuperior;
        
        std::cout << std::setw(6) << f.f_absoluta
                  << std::setprecision(1) << std::setw(8) << f.puntoMedio
                  << std::setw(6) << f.f_acumulada
                  << std::setprecision(2) << std::setw(8) << f.f_relativa
                  << std::setw(8) << f.fr_acumulada
                  << std::setprecision(0) << f.porcentaje << "%" << std::endl;
    }
    
    std::cout << "TOTAL: n = " << total_datos << std::endl;
}