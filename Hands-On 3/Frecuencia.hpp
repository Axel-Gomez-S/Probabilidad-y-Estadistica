#ifndef Frecuencia_hpp
#define Frecuencia_hpp

#include <vector>
#include <string>
#include <map>

struct FilaTabla {
    std::string categoria;
    int f_absoluta;     // f
    double f_relativa;  // fr
    double porcentaje;  // %
};

class Analizar {
private:
    std::vector<double> datos;
    std::vector<FilaTabla> tabla;
    int total_datos;

public:
    Analizar(const std::vector<double>& entrada_datos);
    
    void generarTabla();
    
    void mostrarResultados();
};

#endif