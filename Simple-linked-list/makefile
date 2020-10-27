Objects = Simple-linked-list.o functions.o
cc = gcc

all : Simple-linked-list.o functions.o output clear execute

output : $(Objects)
		 $(cc) $(Objects) -o $(out)
Simple-linked-list.o : Simple-linked-list.c	Simple-linked-list.h
		 $(cc) -c Simple-linked-list.c
functions.o : functions.c Simple-linked-list.h
		 $(cc) -c functions.c
clear :
		 rm -f *.o	
execute : 
		 ./$(out)		 	  