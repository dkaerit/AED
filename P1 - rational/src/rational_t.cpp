// AUTOR:       Diego Vázquez Campos 
// FECHA:       20/02/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION:     1.0
// ASIGNATURA:  Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// pauta de estilo [87]: 3 líneas de separación entre métodos
// pauta de estilo [83]: tipo retornado en línea anterior al método

#include "rational_t.hpp"

// Constructor
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);  // controla que el denominador no es cero
  num_ = n,        // asigna el numerador pasado por parametro al atributo numerador de la clase
  den_ = d;        // asigna el denominador pasado por parametro al atributo denominador de la clase 
}



// Getters
int 
rational_t::get_num() const { return num_;}  // obtener el valor del numerador de la clase 



int 
rational_t::get_den() const { return den_;}  // obtener el valor del denominador de la clase



// Setters
void 
rational_t::set_num(const int n) { num_ = n; }  // actualizar el numerador con el parametro recibido 



void 
rational_t::set_den(const int d)                // actualizar el denominador con el parámetro
{
  assert(d != 0);                                     // controla que el denominador no sea cero
  den_ = d;                                           // asigna el denominador pasado por parametro al atributo denominador
}



// Devolver el valor de la división
double 
rational_t::value() const { 
  return double(get_num()) / get_den(); // retorna el resultado (numero real) de dividir el numerador de la clase con el denominador de la clase
}



// comparaciones
bool 
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return (fabs(value() - r.value()) < precision); // |a-b| > eps
} 



bool 
rational_t::is_greater(const rational_t& r, const double precision) const
{ 
  return ((value() - r.value()) > precision);  // a-b > eps
}



bool 
rational_t::is_less(const rational_t& r, const double precision) const
{
  return ((r.value() - value()) > precision); // b-a > eps
}



bool 
rational_t::is_zero(const int& a, const double precision) const
{
  return (fabs(a) < precision); // |a| < eps
}



// operaciones
rational_t 
rational_t::add(const rational_t& r)
{
  // siendo a/b los valores del objeto this
  // siendo c/d los valores del objeto recibido
  if(r.get_den() == get_den()) // comprobar que los denominadores son iguales
  {
    rational_t c(get_num() + r.get_num(), get_den()); // (a - c) / (b=d)
    return c;
  } 
  else 
  {
    rational_t c(
      (get_num() * r.get_den()) + (r.get_num() * get_den()),  // a*d + b*c
      (get_den() * r.get_den()) // b*d
    ); 
    return c;
  }
}



rational_t 
rational_t::substract(const rational_t& r)
{
  if(r.get_den() == get_den()) // comprobar que los denominadores son iguales
  {
    // siendo a/b los valores del objeto this
    // siendo c/d los valores del objeto recibido
    rational_t c(get_num() - r.get_num(), get_den());  // a*d - b*c
    return c;
  } 
  else 
  {
    rational_t c(
      (get_num() * r.get_den()) - (r.get_num() * get_den()),  // a*d + b*c
      (get_den() * r.get_den()) // b*d
    ); 
    return c;
  }
}



rational_t 
rational_t::multiply(const rational_t& r)
{
  rational_t c(
    (get_num() * r.get_num()), // a*c
    (get_den() * r.get_den())  // b*d
  );
  return c;
}



rational_t 
rational_t::divide(const rational_t& r)
{
  rational_t c(
    (get_num() * r.get_den()), // a*d
    (get_den() * r.get_num())  // b*c
  );
  return c;
}



bool
rational_t::is_reciprocal(const rational_t& r)
{
  return (get_num() == r.get_den()) && 
         (get_den() == r.get_num());
} 

// E/S
void
rational_t::write(ostream& os) const
{
  os << "\x1b[36m"; // envolura de color
  os << get_num() << "/" << get_den() << " = " << value() << endl;  // impresión a/b = valor
  os << "\x1b[0m"; // default color
}



void  
rational_t::read(istream& is)
{
  cout << "\nNumerador? ";
  is >> num_;                 // Asigna la cantidad recibida por la entrada estandar al numerador
  cout << "Denominador? ";
  is >> den_;                 // Asigna la cantidad recibida por la entrada estandar al denominador
  assert(den_ != 0);          // compruea que el denominador no sea cero
}
