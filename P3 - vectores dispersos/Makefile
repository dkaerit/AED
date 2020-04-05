HDIR =./include
ODIR =./tmp
SDIR =./src
LDIR =./lib

# Macros
CC=g++
CFLAGS=-I$(HDIR) -std=c++11 -g

LIBS=-lm

_OBJ = main_sparse_vector_t.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Reglas explícitas
all: main_sparse_vector_t

# Reglas implícitas
$(ODIR)/main_sparse_vector_t.o: $(SDIR)/main_sparse_vector_t.cpp $(HDIR)/sparse_vector_t.hpp $(HDIR)/vector_t.hpp  $(HDIR)/pair_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/sparse_vector_t.o: $(HDIR)/vector_t.hpp  $(HDIR)/pair_t.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

main_sparse_vector_t: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	clear
	./main_sparse_vector_t < data_sparse_vector_t.txt

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
