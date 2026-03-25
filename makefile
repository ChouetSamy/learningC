#exemple de makefile pour un projet avec un fichier source principal 
#et un module dynamique (dynamicArray)
.PHONY: all clean 
#indique que les cibles all et clean ne sont pas des fichiers
CC = gcc #compilateur
CFLAGS = -Wall -Wextra -g 
#options de compilation : -Wall pour les warnings, 
#-Wextra pour les warnings supplémentaires, -g pour le debug

# fichiers source
SRCS = callDynamicArray.c dynamicArray/dynamicArray.c
# fichiers objets
#OBJS = callDynamicArray.o dynamicArray/dynamicArray.o
OBJS = $(SRCS:.c=.o)
# exécutable final
TARGET = app

all: $(TARGET)

# règle pour construire l'exécutable à partir des objets
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

# usage make       # compile tout et crée app
#./app      # lance l'exécutable
#make clean # supprime objets et exécutable