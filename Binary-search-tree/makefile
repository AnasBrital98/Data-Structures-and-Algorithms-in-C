Objects = Functions.o BST.o
cc = gcc

all			: Functions.o BST.o output clean execute

Functions.o : Functions.c BST.h
				$(cc) -c Functions.c

BST.o		: BST.c BST.h
				$(cc) -c BST.c

output 		: $(Objects)
				$(cc) $(Objects) -o $(out) -lm

clean		: 
				rm -f *.o

execute 	:
				./$(out)								