HDIR =./include
ODIR =./tmp
SDIR =./src
LDIR =./lib

# Macros
CC=g++
CFLAGS=-I$(HDIR) -std=c++11 -g

LIBS=-lm

_OBJ = rational_t.o main_p2.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Reglas explícitas
all: main_p2

# Reglas implícitas
$(ODIR)/main_p2.o: $(SDIR)/main_p2.cpp $(HDIR)/rational_t.hpp $(HDIR)/vector_t.hpp $(HDIR)/matrix_t.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/rational_t.o: $(SDIR)/rational_t.cpp $(HDIR)/rational_t.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)	

main_p2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	clear
	./main_p2 < data.txt

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
