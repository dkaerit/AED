// AUTOR:       Diego Vázquez Campos
// FECHA:       21/04/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION:     2.0
// ASIGNATURA:  Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// pauta de estilo [41]: ficheros de cabecera agrupados y separados

#include <iostream>
#include <cmath>


#include "../include/vector_t.hpp"
#include "../include/matrix_t.hpp"
#include "../include/sparse_vector_t.hpp"
#include "../include/sparse_matrix_t.hpp"


using namespace std;

#define COLOR "\x1b[33m"
#define UNDO "\x1b[0m"

int main()
{
  AED::vector_t<double> v1;
  cin >> v1;
  cout << "v1 = " << v1;
  cout << endl;
  
  AED::sparse_vector_t sv1(v1);
  cout << "sv1 = " << sv1;
  cout << endl;
  
  AED::matrix_t<double> M1, M2, M3, M4;
  cin >> M1 >> M2;
  cout << "M1 = " << M1;
  cout << "M2 = " << M2;
  
  // FASE I
  AED::sparse_matrix_t SM1(M1, false);
  cout << "SM1 = " << SM1;
  cout << endl;

  // FASE II
  cout << "sv1 * M1(·, 1) = " << COLOR << sv1.scal_prod(M1, 1) << UNDO << endl;
  cout << "sv1 * M1(·, 2) = " << COLOR << sv1.scal_prod(M1, 2) << UNDO << endl;
  cout << endl;

  AED::sparse_matrix_t SM2(M2);
  cout << "SM2 = " << SM2;
  cout << endl;

  // FASE III
  SM2.multiply(M1, M3);
  cout << "M3 = SM2 * M1" << endl;
  cout << M3;

  // MODIFICACIÓN
  SM2.add(M1, M4);
  cout << "M3 = SM2 + M1" << endl;
  cout << M4;
  
  return 0;
}