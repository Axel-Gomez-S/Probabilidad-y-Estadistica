#ifndef Frecuencia_hpp
#define Frecuencia_hpp

#include <vector>
#include <string>

struct FilaTabla {
    int numeroClase;
    double limiteInferior;
    double limiteSuperior;
    int f_absoluta;     
    double puntoMedio;  
    int f_acumulada;    
    double f_relativa;  
    double fr_acumulada; 
    double porcentaje;  
};

class Analizar {
private:
    std::vector<double> datos;
    std::vector<FilaTabla> tabla;
    int total_datos;
    
    int numClases;
    double anchoClase;

public:
    Analizar(const std::vector<double>& entrada_datos);
    void generarTabla();
    void mostrarResultados();
};

#endif