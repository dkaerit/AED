HDIR =./include
ODIR =./tmp
SDIR =./src
LDIR =./lib

# Macros
CC=g++
CFLAGS=-I$(HDIR) -std=c++11 -g

LIBS=-lm

_OBJ = main_sparse_matrix_t.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Reglas explícitas
all: main

# Reglas implícitas
$(ODIR)/main_sparse_matrix_t.o: $(SDIR)/main_sparse_matrix_t.cpp $(HDIR)/dll_node_t.hpp $(HDIR)/dll_t.hpp $(HDIR)/pair_t.hpp $(HDIR)/matrix_t.hpp $(HDIR)/pair_t.hpp $(HDIR)/sparse_matrix_t.hpp $(HDIR)/sparse_vector_t.hpp $(HDIR)/vector_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	clear
	./main < data_sparse_matrix_t.txt

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
