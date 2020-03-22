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
// pauta de estilo [5]: #define CONSTANTE value
// pauta de estilo [44] y [73]: primero "public" y después "private"
// pauta de estilo [71]: indentación a 2 espacios
// pauta de estilo [11]: nombre de los atributos seguido de "_"

#pragma once  // Evitar errores derivados a leer una misma cabecera dos veces

#include <iostream> // librería de entrada salida 
#include <cassert>  // condiciones 
#include <cmath>    // métodos operacionales (en este caso usamos el valor absoluto)

# define EPSILON 1e-6  // Constante de precisión

using namespace std;   // espacio de nombre automático para las entradas y salidas por línea de comandos

class rational_t  // Definicion de la clase racional
{
  
public:  // componentes públicas
  // Constructor y destructor
  rational_t(const int = 0, const int = 1);  // Constructor por defecto
  ~rational_t() {}                           // Destructor sin implementación

  // getters
  int get_num() const;                       // obtención del numerador
  int get_den() const;                       //  obtención del denominador
  
  // setters
  void set_num(const int);                   // Asignación del numerador
  void set_den(const int);                   // Asignación del denominador

  double value(void) const;                  // Resultado de dividir numerador entre denominador

  // FASE II: Comparaciones
  // Comparaciones de valores entre el racional this y el racional recibido
  bool is_equal(const rational_t&, const double precision = EPSILON) const;   // Igualdad de dos racionales
  bool is_greater(const rational_t&, const double precision = EPSILON) const; // this > r
  bool is_less(const rational_t&, const double precision = EPSILON) const;    // this < r
  bool is_zero(const int&, const double precision = EPSILON) const;           // r.den_ = 0
  
  // FASE III: Operaciones
  // operaciones con this y r
  rational_t add(const rational_t&);        // this + r 
  rational_t substract(const rational_t&);  // this - r 
  rational_t multiply(const rational_t&);   // this * r
  rational_t divide(const rational_t&);     // this / r

  // MODIFICACIÓN
  bool is_reciprocal(const rational_t&);
  
  void write(ostream& = cout) const;        // imprime por salida de comandos una traza 
  void read(istream& = cin);                // pide por linea de comandos numerador y denominador y los asigna
  
private:
  int num_, den_;

};
