CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm -lcunit

all: tests ColorFlood jeu


grid_color.o: grid_color.c grid_color.h
	${CC} ${CFLAGS} -c grid_color.c

SDL.o: SDL.c SDL.h grid_color.h
	${CC} ${CFLAGS} -c SDL.c

ColorFlood.o:ColorFlood.c SDL.h grid_color.o solveur_rapide.h
	${CC} ${CFLAGS} -c ColorFlood.c

ColorFlood:grid_color.o SDL.o ColorFlood.o solveur_rapide.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS} -lSDL -lSDL_ttf -lSDL_gfx -lSDL_mixer


loop_game.o: loop_game.c loop_game.h grid_color.h solveur_rapide.h
	${CC} ${CFLAGS}  -c loop_game.c

main_jeu.o: main_jeu.c loop_game.h solveur_rapide.h
	${CC} ${CFLAGS}  -c main_jeu.c

jeu: main_jeu.o loop_game.o grid_color.o solveur_rapide.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

solveur_rapide.o: solveur_rapide.c grid_color.h solveur_rapide.h
	${CC} ${CFLAGS}  -c solveur_rapide.c

exsolveur:solveur.o mainsolveur.o grid_color.o  loop_game.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

unit_test.o:unit_test.c unit_test.h grid_color.h solveur_rapide.h
	${CC} ${CFLAGS}  -c unit_test.c

main_test.o: main_test.c unit_test.h grid_color.h solveur_rapide.h
	${CC} ${CFLAGS}  -c main_test.c

tests: main_test.o unit_test.o grid_color.o solveur_rapide.o
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}

doc: Doxyfile
	doxygen Doxyfile

valgrind:
	valgrind --leak-check=yes ./tests
	valgrind --leak-check=yes ./exsolveur
	valgrind --leak-check=yes ./ColorFlood

clean:
	rm *.o
