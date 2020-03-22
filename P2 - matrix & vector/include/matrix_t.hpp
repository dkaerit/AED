// AUTOR: Diego Vázquez Campos
// FECHA: 12/03/2020
// EMAIL: alu0101014326@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0); // Constructor por defecto (m x n)
  ~matrix_t();                            // Destructor
  
  void resize(const int, const int);      // Registra los nuevos valores m y n y el vector de long (m x n)
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  int m_, n_;       // m_ filas y n_ columnas
  vector_t<T> v_;   // vector de longitud (m x n)
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;             // Almacena las filas
  n_ = n;             // Almacena las columnas
  v_.resize(m_ * n_); // Llamada al metodo encargado de redimensionar el atributo vector
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0); // Comprueba que la dimensión no sea 0
  m_ = m;                 // almacena las filas
  n_ = n;                 // Almacena las columnas
  v_.resize(m_ * n_);     // Crea el objeto vector de longitud (m x n)
}



template<class T>
inline int
matrix_t<T>::get_m() const // Devuelve el numero de filas
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const // Devuelve el numero de columnas
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)  // Devuelve el valor almacenado en la posición (i,j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j) // Operador () que se encarga de asumir la llamada a at()
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const 
// función miembro de clase constante, y a su vez, sobrecarga de at()
// No modifica el objeto para el que se le llama
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << setw(5) << at(i, j);
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_n() == B.get_m()); // Comprobar que son multiplicables
  
  resize(A.get_m(), B.get_n());
  T sp;
  
  for(int i = 1; i <= A.get_m(); ++i) {
    for(int j = 1; j <= B.get_n(); ++j) {
      sp = 0.0; // producto escalar
      for(int k = 1; k <= A.get_n(); ++k)
        sp = sp + (A(i,k)*B(k,j));

      at(i,j) = sp;
    }
  }
}
