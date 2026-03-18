#include "Frecuencia.hpp"
#include <iostream>
#include <iomanip>

Analizar::Analizar(const std::vector<double>& entrada_datos) {
    datos = entrada_datos;
    total_datos = datos.size();
}

void Analizar::generarTabla() {

    std::map<double, int> conteo;
    for (double x : datos) {
        conteo[x]++;
    }

    for (auto const& [valor, frecuencia] : conteo) {
        FilaTabla fila;
        fila.categoria = std::to_string(valor);
        fila.f_absoluta = frecuencia;
        fila.f_relativa = (double)frecuencia / total_datos;
        fila.porcentaje = fila.f_relativa * 100;
        
        tabla.push_back(fila);
    }
}

void Analizar::mostrarResultados() {
    std::cout << "\n--TABLA DE FRECUENCIAS--" << std::endl;
   
    std::cout << std::left << std::setw(15) << "Clase" 
              << std::setw(8) << "f" 
              << std::setw(15) << "fr" 
              << "%" << std::endl;
   

    for (const auto& fila : tabla) {
        std::cout << std::left << std::setw(15) << fila.categoria 
                  << std::setw(8) << fila.f_absoluta 
                  << std::setw(15) << std::fixed << std::setprecision(2) << fila.f_relativa 
                  << fila.porcentaje << "%" << std::endl;
    }
    
    std::cout << "Total: " << total_datos << " datos procesados." << std::endl;
}