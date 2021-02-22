notetime : main.o utils.o
		gcc -o notetime main.o utils.o

main.o : main.c utils.h
		gcc -Wall -c main.c
utils.o : utils.c
		gcc -Wall -c utils.c

clean :
		rm notetime main.o utils.o