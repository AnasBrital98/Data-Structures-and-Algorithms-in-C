Objects = Doubly-linked-list.o functions.o
cc = gcc

all : Doubly-linked-list.o functions.o output clear execute

output :	$(Objects)
		$(cc) $(Objects) -o $(out)

Doubly-linked-list.o : Doubly-linked-list.c Doubly-linked-list.h
		$(cc) -c Doubly-linked-list.c
functions.o : functions.c Doubly-linked-list.h
		$(cc) -c functions.c				
clear :
		rm -f *.o
execute : 
		./$(out)		