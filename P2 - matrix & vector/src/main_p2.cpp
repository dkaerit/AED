// AUTOR: Diego Vázquez Campos
// FECHA: 12/03/2020
// EMAIL: alu0101014326@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// pauta de estilo [41]: ficheros de cabecera agrupados y separados

#include <iostream>
#include <cmath>


#include "../include/rational_t.hpp"
#include "../include/vector_t.hpp"
#include "../include/matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  system("clear");
  cout << endl << "a: \t"; a.write();
  cout << "b: \t"; b.write();
  cout << endl;

  cout << "a + b: "; (a+b).write(); 
  cout << "b - a: "; (b-a).write(); 
  cout << "a * b: "; (a*b).write(); 
  cout << "a / b: "; (a/b).write(); 
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "\nProducto escalar de vector_t<double>: " << "\x1b[33m" << scal_prod(v, w) << "\x1b[0m" << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << "\x1b[33m" << scal_prod(x, y) << "\x1b[0m" << endl << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  // MODIFICACIÓN
  (v+w).write();
  
  return 0;
}