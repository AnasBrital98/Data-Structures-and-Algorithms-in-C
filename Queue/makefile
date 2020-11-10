Objects = Queue.o Functions.o
cc = gcc

all : Functions.o Queue.o output clean execute

Queue.o  	:  Queue.c Queue.h
				$(cc) -c Queue.c
Functions.o :  Functions.c Queue.h
				$(cc) -c Functions.c
output      :  $(Objects)
				$(cc) $(Objects) -o $(out)
clean		: 
				rm -f *.o
execute 	: 
				./$(out)															