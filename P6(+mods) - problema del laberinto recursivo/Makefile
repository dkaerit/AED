# Variables.
HDIR = ./include
SDIR = ./src
ODIR = ./tmp

# Macros
OUTPUT = main_maze_t # Nombre del fichero ejecutable.
CFLAGS = -std=c++11 -I$(HDIR) # Flags para el compilador.
CC     = g++ -Ofast # Definición del compilador.
SRC    = $(SDIR)/main_maze_t.cpp $(SDIR)/maze_t.cpp # Definición de ficheros fuente.

# Orden por defecto
all: clean $(OUTPUT) 

# Regla de compilación.
$(OUTPUT):
	clear && $(CC) -o $@ $(CFLAGS) $(SRC)

# Regla para limpiar ficheros.
.PHONY: clean
clean:
	@rm  -f $(OUTPUT)

# Regla para compilar y ejecutar
run:
	@make && $(OUTPUT)
