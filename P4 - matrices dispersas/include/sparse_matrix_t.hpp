// AUTOR:       Diego Vázquez Campos
// FECHA:       21/04/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION:     2.0
// ASIGNATURA:  Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "pair_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "sparse_vector_t.hpp"

using namespace std;

#define COLOR "\x1b[33m"
#define UNDO "\x1b[0m"

typedef AED::vector_t<AED::sparse_vector_t> vector_sparse_vector_t;

namespace AED
{
  
class sparse_matrix_t
{
public:
  sparse_matrix_t(const matrix_t<double>&, bool = true); // constructor normal
  sparse_matrix_t(const sparse_matrix_t&);  // constructor de copia
  
  sparse_matrix_t& operator=(const sparse_matrix_t&); // operador de asignación

  ~sparse_matrix_t();
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // operaciones
  void multiply(const matrix_t<double>&, matrix_t<double>&);
  void add(const matrix_t<double>&, matrix_t<double>&);

  // E/S
  void write(ostream& = cout) const;

private:
  vector_sparse_vector_t sm_; // vector de vectores dispersos
  int  m_;                    // filas de la matriz original
  int  n_;                    // columnas de la matriz original
  bool by_rows_;              // indica si la matriz se ha creado 
                              // por filas (true) o por columnas (false)
};



sparse_matrix_t::sparse_matrix_t(const matrix_t<double>& M, bool conf):
sm_(),
m_(M.get_m()),
n_(M.get_n()),
by_rows_(conf)
{
  if(by_rows_) {
    sm_.resize(m_);
    for(int i = 1; i <= M.get_m(); ++i) {
      sparse_vector_t sv(M.get_row(i));
      sm_[i - 1] = sv;
    }
  }
  else {
    // FASE I
    sm_.resize(n_); // redimensionar columnas
    for(int j = 1; j <= M.get_n(); ++j) { // recorremos columnas
      sparse_vector_t sv(M.get_col(j)); // en cada iteracion creamos un vector disperso para las columnas
      sm_[j - 1] = sv;
    }
  }
}



sparse_matrix_t::sparse_matrix_t(const sparse_matrix_t& SM)
{
  *this = SM;
}



// operador de asignación
sparse_matrix_t&
sparse_matrix_t::operator=(const sparse_matrix_t& SM)
{
  m_ = SM.get_m();
  n_ = SM.get_n();
  by_rows_ = SM.by_rows_;
  sm_ = SM.sm_;

  return *this;
}



sparse_matrix_t::~sparse_matrix_t()
{}



int
sparse_matrix_t::get_m() const
{
  return m_;
}



int
sparse_matrix_t::get_n() const
{
  return n_;
}



// operaciones
// FASE III
void
sparse_matrix_t::multiply(const matrix_t<double>& A, matrix_t<double>& B)
{
  assert(by_rows_); // solo se multiplica si la configuración es por filas
  assert(get_n() == A.get_m());

  if(get_n() == A.get_m()) {
    B.resize(get_m(), A.get_n());
    for(int i = 1; i <= sm_.get_size(); i++) {
      for(int j = 1; j <= A.get_n(); j++) {
        B(i,j) = sm_[i-1].scal_prod(A.get_col(j));
      }
    }
  }
}




// MODIFICACIÓN
void 
sparse_matrix_t::add(const matrix_t<double>& A, matrix_t<double>& B) 
{
  assert(by_rows_);
  assert(get_n() == A.get_m());

  int lsc, lsr; // limites superiores de columna y fila.
  if(get_n() > A.get_n()) lsc = get_m();
  else lsc = A.get_n();

  if(get_m() > A.get_m()) lsr = get_m();
  else lsr = A.get_m();

  B.resize(lsr, lsc);
  cout << sm_.get_size();
  for(int i = 1; i <= sm_.get_size(); i++) {
    for(int j = 1; j <=  A.get_n(); j++) {
      //for(int k = 1; k <= sm_.get_val(k-1).get_dll().get_size())
      B(i,j) = 0;
      cout << "it(" << i << "," << j << ")" << endl;
      
      //cout << "sm: "<< sm_[i].get_dll().get_head()->get_data() << endl;
        cout << "A: " << A.get_col(j);
        cout << "A: " << A.get_col(j)[i-1] << endl;
        cout << "sm: "<< sm_.get_val(i-1) << endl;
    }
  }



}



void
sparse_matrix_t::write(ostream& os) const
{
	os << m_ << "x" << n_ << endl;
	os << (by_rows_ ? "BY_ROWS" : "BY_COLS") << endl;
	for (int i = 0; i < sm_.get_size(); i++) {
		os << "[" << i << "] -> " << sm_[i];
	}
}



ostream&
operator<<(ostream& os, const sparse_matrix_t& SM)
{
  SM.write(os);
  return os;
}

}
