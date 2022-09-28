uwu: main.o prueba.o
	gcc -o uwu main.o prueba.o

main.o: main.c
	gcc -c main.c

prueba.o: prueba.c prueba.h
	gcc -c prueba.c

clean:
	rm *.o uwu
