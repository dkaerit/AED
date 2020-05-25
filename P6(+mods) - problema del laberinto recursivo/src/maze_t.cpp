// AUTOR:       Diego Vázquez Campos
// FECHA:       22/05/2020
// EMAIL:       alu0101014326@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "../include/maze_t.hpp"


// constructor
maze_t::maze_t():
matrix_(),
visited_(), 
i_start_(-1),
j_start_(-1), 
i_end_(-1),
j_end_(-1)
{}


// destructor
maze_t::~maze_t()
{}



// método que resuelve el laberinto invocando al método recursivo
bool
maze_t::solve()
{
  int count = 0;
  bool aux = solve_(i_start_, j_start_, count);
  cout << "Se ha llamado a la función "<< count <<" veces"<< endl;
  return aux;
}



// lee el laberinto en forma de matriz desde la entrada
istream&
maze_t::read(istream& is)
{ 
  int m, n; // fila m x columna n
  is >> m >> n; // recibo los valores de m y n del fichero
  assert(m > 0 && n > 0); // no pueden ser 0
  
  matrix_.resize(m, n); // creo la matriz laberinto de la clase
  visited_.resize(m, n); // creo la matriz de nodos visitados
  deadends_.resize(m, n);
  
  for (int i = 1; i <= m; i++) // recorro en columnas la dimensión de la matriz
  {
    for (int j = 1; j <= n; j++) // por cada columna salto en filas
    {
      short s; // creo una variable que será la que contenga el bit a analizar
      is >> s; // lo almaceno
      
      // si el dato es un START_ID -> entrada al laberinto
      if (s == START_ID) // chequeo que el bit es 8
      {
        i_start_ = i;
        j_start_ = j;
      }
      // si el dato es un END_ID -> salida al laberinto
      else if (s == END_ID) // chequeo que el bit es 9
      {
        i_end_ = i;
        j_end_   = j;
      }
      
      matrix_(i, j) = s; // en cualquier caso (sea START, END, MURO) siempre lo vamos a al macenar en la matriz
    }
  }

  // comprobamos que se han leído correctamente la entrada y la salida  
  assert (i_start_ != -1 && j_start_ != -1 && i_end_ != -1 && j_end_ != -1); // Siempre debe haber un comienzo y un final

  return is;
}



// muestra el laberinto por pantalla
ostream&
maze_t::write(ostream& os) const
{
  os << matrix_.get_m() << "x" << matrix_.get_n() << endl;
  for (int i = 1; i <= matrix_.get_m(); i++)
  {
    for (int j = 1; j <= matrix_.get_n(); j++)
      switch (matrix_(i, j))
      { 
        case START_ID: os << START_CHR; break;
        case END_ID:   os << END_CHR;   break;
        case WALL_ID:  os << WALL_CHR;  break;
        case PASS_ID:  os << PASS_CHR;  break;
        case PATH_ID:  os << PATH_CHR;  break;
      }

    os << endl;
  }
  
  return os; 
}

void
maze_t::print_sol(ostream& os) 
{
  os << "(columna:fila): ";
  sol_.write();
  deadends_.write();
}



// FASE I
// comprueba que la fila i y columna j son válidas antes de pasar a ellas
bool
maze_t::is_ok_(const int i, const int j) const
{ 
  // retornar true si se cumplen TODAS estas condiciones:
  // - fila i y la columna j están dentro de los límites del laberinto,
  // - la celda en (i, j) no puede ser un muro,
  // - la celda (i, j) no puede haber sido visitada antes.
  if(i > 0 && j > 0 && i <= matrix_.get_m() && j <= matrix_.get_n()) {
      if(matrix_(i,j) != 1 && visited_(i,j) == 0) return true;
      else                                        return false;
  } else return false;
    
}



// FASE II y FASE III
// método recursivo que resuelve el laberinto
bool
maze_t::solve_(const int i, const int j, int &count)
{
  ++count;
  // CASO BASE:
  // retornar 'true' si 'i' y 'j' han llegado a la salida
    if(
    i == i_end_ &&
    j == j_end_) {
      
      return true;
    }

  // marcamos la celda como visitada
  visited_(i, j) = true; 
  
  // CASO GENERAL:
  // para cada una de las 4 posibles direcciones (N, E, S, W) ver si es posible
  // el desplazamiento (is_ok_) y, en ese caso, intentar resolver el laberinto
  // llamando recursivamente a 'solve'. 
  // Si la llamada devuelve 'true', poner en la celda el valor PATH_ID, y
  // propagarla retornando también 'true'

  for(int k = 0; k < 4; k++) {

    int mv_i = i + i_d[k];
    int mv_j = j + j_d[k];

    //cout << "(" <<  i << ", "  << j << ")"; // posición actual
    //cout << "(" <<  mv_i << ", "  << mv_j << ")" << endl; // coordenada a evaluar 

    if(is_ok_(mv_i, mv_j)) {
      // cout << "\t-> solucion" << endl; 
      if(solve_(mv_i, mv_j, count)) { // N, E, S, W
        if(mv_i == i_end_ && mv_j == j_end_) cout << "";
        else matrix_(mv_i, mv_j) = PATH_ID;

        sol_.push(pair_t<short>(mv_i, mv_j));
        return true;
      } else {
        deadends_(i,j) = 1;
      }
    }  
  } 
  // desmarcamos la celda como visitada (denominado "backtracking") y
  // retornamos 'false'
  visited_(i, j) = false;
  return false;
}



// operador de entrada sobrecargado
istream&
operator>>(istream& is, maze_t& M)
{
  return M.read(is);
}



// operador de salida sobrecargado
ostream&
operator<<(ostream& os, const maze_t& M)
{
  return M.write(os);
}



int
maze_t::contar_muros(void)
{
  int count = 0;
  for(int i = 1; i <= matrix_.get_m(); i++) {
    for(int j = 1; j <= matrix_.get_n(); j++) {
      if(matrix_(i,j) == 1) count++;
    }
  }
  return count;
}


void
maze_t::centrar(void) {

  matrix_(i_start_,j_start_) = 1;
  j_start_ = matrix_.get_n()/2;
  matrix_(i_start_,j_start_) = 8;

  matrix_(i_end_,j_end_) = 1;
  j_end_ = matrix_.get_n()/2;
  matrix_(i_end_,j_end_) = 9;

}
