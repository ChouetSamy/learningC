Partie en question :
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Explication pas à pas :

$(TARGET) → c’est ton exécutable final (app dans ton cas)

$(OBJS) → ce sont tous les fichiers objets générés à partir des sources .c

La ligne juste en dessous (la commande) :

$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(CC) → gcc (le compilateur)

$(CFLAGS) → options de compilation (-Wall -Wextra -g)

-o $(TARGET) → crée un exécutable avec le nom TARGET

$(OBJS) → tous les objets à lier ensemble pour faire l’exécutable

En clair :

Si tu modifies un fichier .c, make va d’abord compiler ce fichier en .o (objet), puis il va lier tous les .o pour créer l’exécutable app.

Ligne suivante :
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c → règle générique : pour tout .c, on peut créer un .o correspondant

$< → le premier "prérequis", ici le fichier .c

$@ → la cible, ici le fichier .o

Donc si tu as dynamicArray.c, cette règle fait :

gcc -Wall -Wextra -g -c dynamicArray.c -o dynamicArray.o

Exactement ce qu’il faut pour créer les fichiers objets avant le linking.

Résumé du flux

make regarde si l’exécutable existe.

Si non, il regarde les fichiers .o.

Pour chaque .c qui a changé, il fait :

gcc -c fichier.c -o fichier.o

Ensuite il fait le linking de tous les .o pour créer l’exécutable :

gcc -o app file1.o file2.o ...

✅ Avec ça, ton projet multi-fichier compile correctement et proprement, et tu peux modifier un seul fichier .c sans recompiler tout le projet si tu veux gagner du temps.

autre exemple de makefile
app: main.o decoupe.o
	gcc main.o decoupe.o -o app

main.o: main.c
	gcc -c main.c

decoupe.o: decoupe.c
	gcc -c decoupe.c