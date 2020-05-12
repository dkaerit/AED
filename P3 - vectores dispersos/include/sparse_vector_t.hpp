// AUTOR: Diego Vázquez Campos
// FECHA: 01-04-2020
// EMAIL: alu0101014326@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

#include "./vector_t.hpp"
#include "./pair_t.hpp"

using namespace std;

#define EPS 1e-9

typedef vector_t<pair_t<double>> pair_vector_t;

class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t();
  
  // getters
   int get_nz(void) const;
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);
   double average_non0(void);
  
   // E/S
   void write(ostream& = cout) const;

private:
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original
  
  bool is_not_zero(double, double = 1e-6) const;
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(),
nz_(0),
n_(v.get_size())
{
  int tmp = 0; 
  for(int i = 0; i < get_n(); i++) {
    if(v[i] != 0) tmp++;
  }

  cout << endl;
  nz_ = tmp;
  pv_.resize(get_nz());

  tmp = 0; 
  for(int i = 0; i < get_n(); i++) { 
    if(v[i] != 0) {
      pv_.set_val(tmp, pair_t<double>(v[i], i));
      tmp++;
    }
  }
}



// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}



sparse_vector_t::~sparse_vector_t()
{}



inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}



void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << (i == 0 ? setw(1) : setw(4))  << pv_[i] << " ";
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}



bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  double s = 0;

  assert(get_n() == v.get_size());
  for(int i = 0; i < v.get_size(); i++) {
    for(int j = 0; j < get_nz(); j++) {
      if((i == pv_[j].get_inx()) && (is_not_zero(v[i], EPS))) {
        s += v[i] * pv_[j].get_val();
      }
    }
  }

  return s;
}



/// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  double s = 0;
  
  for(int i = 0; i < get_nz(); i++) {
    for(int j = 0; j < sv.get_nz(); j++) {
      if(pv_[i].get_inx() == sv.pv_[j].get_inx()) {
        s += (pv_[i].get_val() * sv.pv_[j].get_val());
      }
    }
  }

  return s;
}

double 
sparse_vector_t::average_non0(void) {
  double s = 0;

  for(int i = 0; i < get_nz(); i++) {
    s += pv_[i].get_val();
  }

  return (s / get_nz());
}
