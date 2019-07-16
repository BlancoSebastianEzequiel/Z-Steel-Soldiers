# Makefile de ejemplo para programa cliente-servidor en C/C++.
# Genera los ejecutables 'client' y 'server' basados en archivos con el
# patrón 'client*.(c|cpp)' y 'server*.(c|cpp)' respectivamente.
# En ambos ejecutables, incluye elementos encontrados en 'common*.(c|cpp)'.
# Creado: 27/04/2007 - Leandro Lucarella
# Modificado: 01/09/2016 - Pablo Roca
# Copyleft 2004 - Leandro Lucarella, Bajo licencia GPL [http://www.gnu.org/]

# CONFIGURACION
################

# Extensión de los archivos a compilar (c para C, cpp o cc o cxx para C++).
ext = cpp

# Archivos con el código fuente que componen el ejecutable. Si no se especifica,
# toma todos los archivos con la extensión mencionada. Para especificar hay que
# descomentar la línea (quitarle el '#' del principio).
# NOTA: No poner cabeceras (.h).
#fuentes_client = entrada.cpp
#fuentes_server = entrada.cpp
#fuentes_common = entrada.cpp

# Si usa funciones de math.h, descomentar (quitar el '#' a) la siguiente línea.
math = si

# Si usa threads, descomentar (quitar el '#' a) la siguiente línea.
threads = si

# Si es un programa GTK+, descomentar (quitar el '#' a) la siguiente línea.
#gtk = si

# Si es un programa gtkmm, descomentar (quitar el '#' a) la siguiente línea.
#gtkmm = si

# Descomentar si se quiere ver como se invoca al compilador
#verbose = si


# CONFIGURACION "AVANZADA"
###########################

# Opciones para el compilador C/C++ para tratamiento de errores y warnings.
CFLAGS = -Wall -Werror -pedantic -pedantic-errors

# Para optimizar el binario resultante lo mejor posible
CFLAGS += -O3

# Para valgrind o debug
CFLAGS += -ggdb -DDEBUG -fno-inline

# Estandar de C a usar
CSTD = c99

# Estandar de C++ a usar
CXXSTD = c++11

# Si se quiere compilar estaticamente, descomentar la siguiente linea
#static = si


# VARIABLES CALCULADAS A PARTIR DE LA CONFIGURACION
####################################################

# Linkea con libm de ser necesario.
ifdef math
LDFLAGS += -lm
endif


# Linkea con threads de ser necesario. Permite el uso de pthread en C y C++.
# Permite el uso de built-in threads en C++.
ifdef threads
LDFLAGS += -pthread
endif

ifdef static
LDFLAGS += -static
endif

#Linkea SDL
LDFLAGS += -lSDLmain
LDFLAGS += -lSDL
LDFLAGS += -lSDL_image

# Se reutilizan los flags de C para C++ también
CXXFLAGS += $(CFLAGS)

# Se usa enlazador de C++ si es código no C.
ifeq ($(ext), c)
CFLAGS += -std=$(CSTD)
LD = $(CC)
else
CXXFLAGS += -std=$(CXXSTD)
LD = $(CXX)
endif

LDFLAGS += $(CXXFLAGS)

# Si no especifica archivos, tomo todos.
fuentes_client ?= $(wildcard client/*.$(ext) client/*/*.$(ext) client/*/*/*.$(ext) client/*/*/*/*.$(ext))
fuentes_server ?= $(wildcard server/*.$(ext) server/*/*.$(ext) server/*/*/*.$(ext))
fuentes_common ?= $(wildcard libs/*.$(ext))
fuentes_libs_test ?= $(wildcard libs/*.$(ext) libs/tests/*.$(ext))
directorios = $(shell find . -type d -regex '.*\w+')

occ := $(CC)
ocxx := $(CXX)
orm := $(RM)
old := $(LD)
ifdef verbose
RM := $(RM) -v
else
CC =  @echo "  CC  $@"; $(occ)
CXX = @echo "  CXX $@"; $(ocxx)
RM =  @echo "  CLEAN"; $(orm)
LD =  @echo "  LD  $@"; $(old)
endif


# REGLAS
#########

.PHONY: all clean

all: client server test

# replace ext of files (.cpp, .h) with the output ext (.o)
o_libs_test_files = $(patsubst %.$(ext),%.o,$(fuentes_libs_test))
o_common_files = $(patsubst %.$(ext),%.o,$(fuentes_common))
o_client_files = $(patsubst client/%,client/%,$(fuentes_client:.$(ext)=.o))
o_server_files = $(patsubst server/%,server/%,$(fuentes_server:.$(ext)=.o))

test: $(o_libs_test_files)
	$(LD) $(o_libs_test_files) -o libs/tests/libs_test $(LDFLAGS)

client: $(o_common_files) $(o_client_files)
	@if [ -z "$(o_client_files)" ]; \
	then \
		echo "No hay archivos de entrada en el directorio actual para el cliente."; \
		if [ -n "$(directorios)" ]; then echo "Directorios encontrados: $(directorios)"; fi; \
		false; \
	fi >&2
	$(LD) $(o_common_files) $(fuentes_client) -o client/client_exe $(LDFLAGS)

server: $(o_common_files) $(o_server_files)
	@if [ -z "$(o_server_files)" ]; \
	then \
		echo "No hay archivos de entrada en el directorio actual para el servidor."; \
		if [ -n "$(directorios)" ]; then echo "Directorios encontrados: $(directorios)"; fi; \
		false; \
	fi >&2
	$(LD) $(o_common_files) $(o_server_files) -o server/server_exe $(LDFLAGS)

clean_client:
	$(RM) -f $(o_client_files) client/client_exe

clean_server:
	$(RM) -f $(o_server_files) server/server_exe

clean_libs:
	$(RM) -f $(o_common_files)

clean_test:
	$(RM) -f $(o_libs_test_files) libs/tests/libs_test

clean:
	$(RM) -f $(o_common_files) $(o_client_files) $(o_server_files) client/client_exe server/server_exe

