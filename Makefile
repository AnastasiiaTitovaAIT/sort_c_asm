program : main.o functions.o
	gcc -march=i386 -o program functions.o main.o -m32
main.o : main.c
	gcc -std=c99 -c -o main.o main.c -m32
functions.o : functions.asm
	nasm -f elf32 -o functions.o functions.asm
clean :
	rm program main.o functions.o
