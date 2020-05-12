// AUTOR:       Diego Vázquez Campos
// FECHA:       8/05/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION:     1.0
// ASIGNATURA:  Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include "queue_l_t.hpp"

#define YELL "\x1b[33m"
#define LRED "\x1b[91m"
#define CYAN "\x1b[96m"
#define UNDO "\x1b[0m"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << CYAN << "Sale de la cola un: " <<  UNDO << setw(2) << c;

		if (isdigit(c))
		{
		  int i = c - '0';
		  // poner código
		  cout << YELL << " (dígito)" << UNDO;
		  cout << CYAN << "    → Lo metemos en la pila..." << UNDO << endl;
		  stack_.push(i);
		}
		else {
		  cout << LRED << " (operador)" << UNDO << endl;
		  // poner código
		  operate_(c);
		}
	}

	// poner código
	return stack_.top();;
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  int p, q;

  bool a2 = (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); // FASE I y II
  bool a1 = (c == 'r' || c == 'l' || c == 'c'); 						// FASE II y III

  assert( a1 || a2 );
  if(a2) { // FASE I y II
    p = stack_.top(); stack_.pop();
    q = stack_.top(); stack_.pop();
	cout << "\t⤷ Sacamos : " << setw(2) << p << endl;
	cout << "\t⤷ Sacamos : " << setw(2) << q << endl;
    cout << "\t⤷ Operamos: " << setw(2) << q << "  " <<  c  << " " << setw(2) << p  << " = ";
  }
  else if(a1) { // FASE II y III
	p = stack_.top(); stack_.pop();
	cout << "   Sacamos de la pila un operando: " << p;
  }
  
	switch (c)
	{
	  // FASE I
	  case '+': stack_.push(q+p); break;
	  case '-': stack_.push(q-p); break;
	  case '*': stack_.push(q*p); break;
	  case '/': stack_.push(q/p); break;
	  // FASE II 
	  case '^': stack_.push(pow(q,p)); break; 
	  case 'r': stack_.push(sqrt(p)); break;  
	  // FASE III
	  case 'l': stack_.push(log2(p)); break;  
	  case 'c': stack_.push(pow(p,2)); break; 
	}

	// código
	cout << setw(2) << stack_.top() << CYAN  << "  → Lo metemos en la pila... " << endl;
}

}
