store : main.c data.o function.o
	gcc -o store main.c data.o function.o
data.o: data.c data.h
	gcc -c data.c -o data.o
function.o: fuction.c function.h
	gcc -c function.c -o function.o
