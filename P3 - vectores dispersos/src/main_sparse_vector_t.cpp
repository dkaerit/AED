// AUTOR: Diego Vázquez Campos
// FECHA: 01-04-2020
// EMAIL: alu0101014326@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g main_vector_t.cpp -o main_vector_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// pauta de estilo [41]: ficheros de cabecera agrupados y separados

#include <iostream>
#include <cmath>

#include "../include/vector_t.hpp"
#include "../include/sparse_vector_t.hpp"


using namespace std;

#define COLOR "\x1b[33m"
#define UNDO "\x1b[0m"

int main()
{
  vector_t<double> v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  cout << "v1 = " << v1;
  cout << "v2 = " << v2;
  cout << "v3 = " << v3;
  cout << endl;
  
  sparse_vector_t sv1(v1), sv2(v2), sv3(v3);
  cout << "sv1 = " << sv1;
  cout << "sv2 = " << sv2;
  cout << "sv3 = " << sv3;
  cout << endl;
  
  cout << "sv3 * v1 = " << COLOR << sv3.scal_prod(v1) << UNDO << endl;
  cout << "sv3 * sv2 = " << COLOR << sv3.scal_prod(sv2) << UNDO << endl;
  
  return 0;
}