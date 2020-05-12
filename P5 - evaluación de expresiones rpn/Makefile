HDIR =./include
ODIR =./tmp
SDIR =./src
LDIR =./lib

# Macros
CC=g++
CFLAGS=-I$(HDIR) -std=c++11 -g

LIBS=-lm

_OBJ = main_rpn_t.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Reglas explícitas
all: main

# Reglas implícitas
$(ODIR)/main_rpn_t.o: $(SDIR)/main_rpn_t.cpp $(HDIR)/dll_node_t.hpp $(HDIR)/dll_t.hpp $(HDIR)/queue_l_t.hpp $(HDIR)/rpn_t.hpp $(HDIR)/stack_l_t.hpp  
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	clear

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
