#include "Tendencia.hpp"
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
    
    anchoClase = (rango + 1) / (double)numClases;

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

double Analizar::calcularMedia() {
    double suma = 0;
    for (const auto& f : tabla) {
        suma += (f.puntoMedio * f.f_absoluta);
    }
    return suma / total_datos;
}

double Analizar::calcularMediana() {
    double mitad = total_datos / 2.0;
    for (int i = 0; i < (int)tabla.size(); i++) {
        if (tabla[i].f_acumulada >= mitad) {
            double Li = tabla[i].limiteInferior;
            double Fi_ant = (i == 0) ? 0 : tabla[i-1].f_acumulada;
            double fi = tabla[i].f_absoluta;
            return Li + ((mitad - Fi_ant) / fi) * anchoClase;
        }
    }
    return tabla.back().puntoMedio; 
}

double Analizar::calcularModa() {
    int maxFi = -1;
    int idx = 0;
    for (int i = 0; i < (int)tabla.size(); i++) {
        if (tabla[i].f_absoluta > maxFi) {
            maxFi = tabla[i].f_absoluta;
            idx = i;
        }
    }
    double Li = tabla[idx].limiteInferior;
    double fi = tabla[idx].f_absoluta;
    double fi_ant = (idx == 0) ? 0 : tabla[idx-1].f_absoluta;
    double fi_sig = (idx == (int)tabla.size() - 1) ? 0 : tabla[idx+1].f_absoluta;

    double d1 = fi - fi_ant;
    double d2 = fi - fi_sig;
    
    if ((d1 + d2) == 0) return tabla[idx].puntoMedio;
    return Li + (d1 / (d1 + d2)) * anchoClase;
}

void Analizar::mostrarResultados() {
    std::cout << std::left << std::setw(6) << "Clase" << std::setw(15) << "Limites" 
              << std::setw(6) << "f" << std::setw(8) << "Xc" << std::setw(6) << "Fa" 
              << std::setw(8) << "fr" << std::setw(8) << "fra" << "%" << std::endl;

    for (const auto& f : tabla) {
        std::cout << std::left << std::setw(6) << f.numeroClase;
        std::cout << std::fixed << std::setprecision(0) << f.limiteInferior << " - " 
                  << std::setw(10) << f.limiteSuperior;
        std::cout << std::setw(6) << f.f_absoluta << std::setprecision(1) << std::setw(8) 
                  << f.puntoMedio << std::setw(6) << f.f_acumulada << std::setprecision(2) 
                  << std::setw(8) << f.f_relativa << std::setw(8) << f.fr_acumulada 
                  << std::setprecision(0) << f.porcentaje << "%" << std::endl;
    }

    std::cout << "\nTOTAL: n = " << total_datos << std::endl;
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "MEDIDAS DE TENDENCIA CENTRAL" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Media:   " << calcularMedia() << std::endl;
    std::cout << "Mediana: " << calcularMediana() << std::endl;
    std::cout << "Moda:    " << calcularModa() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}