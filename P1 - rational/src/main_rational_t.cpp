// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

using namespace std;

int main()
{
  // creación de los objetos racionales a, b, c
  rational_t 
    a(1, 2), 
    b(3), 
    c;

  // mostrar los valores de la división de los racionales creados
  cout << "a.value()= " << a.value() << endl;
  cout << "b.value()= " << b.value() << endl;
  // al principio "c" será cero, ya que al no recibir valores se llama al constructor por defecto
  cout << "c.value()= " << c.value() << endl; 
  cout << "-------------------------------" << endl;

  // Imprimir el racional (a) y (b) por línea de comandos
  cout << "\x1b[33m" << "\na: "; 
  a.write();  // imprimo la traza del racional a
  cout << "\x1b[33m" << "b: "; 
  b.write();  // imprimo la traza del racional b

  // FASE III
  // Imprimir el racional (a) y (b) por línea de comandos
  cout << endl;
  cout << "a + b: ";
  a.add(b).write(); // imprimir la traza del resultado de sumar "a" y "b"
  
   cout << "b - a: ";
   b.substract(a).write(); // imprimir el resultado de restarle "b" a "a"

   cout << "a * b: ";
   a.multiply(b).write(); // imprimir el resultado de de multiplicar a y b
  
   cout << "a / b: ";
   a.divide(b).write(); // imprimir el resultado de sividir a y b
 
  // FASE II
  cout << "-------------------------------" << endl;
   rational_t x(1, 3), y(2, 3); // Creo los racionales x e y

   cout << "\x1b[33m" << "\nx: "; 
   x.write();   // imprimo la traza de x
   cout << "\x1b[33m" << "y: "; 
   y.write();   // imprimo la traza de y

   cout << "\nx == y? " << (x.is_equal(y) ? "true" : "false") << endl;
   cout << "x <  y? " << (x.is_greater(y) ? "true" : "false") << endl;
   cout << "x >  y? " << (x.is_less(y) ? "true" : "false") << endl << endl;

  cout << "-------------------------------" << endl;
  // Pedir el racional c por línea de comandos
  c.read();  // pido valores de c
  cout << "\x1b[33m" << "\nc: "; 
  c.write(); // imprimo la traza de c
  cout << endl;

  cout << "\nMODIFICACIÓN: \nc recip x? " << (c.is_reciprocal(x) ? "true" : "false") << endl;
  
  
  return 0;
}