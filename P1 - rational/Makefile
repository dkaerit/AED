HDIR =./include
ODIR =./tmp
SDIR =./src
LDIR =./lib

# Macros
CC=g++
CFLAGS=-I$(HDIR) -std=c++11 -g

LIBS=-lm

_OBJ = rational_t.o main_rational_t.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Reglas explícitas
all: main_rational_t

# Reglas implícitas
$(ODIR)/main_rational_t.o: $(SDIR)/main_rational_t.cpp $(HDIR)/rational_t.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/rational_t.o: $(SDIR)/rational_t.cpp $(HDIR)/rational_t.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)	

main_rational_t: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
