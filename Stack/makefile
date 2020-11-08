Objects = Stack.o Functions.o
cc = gcc

all 		: Stack.o Functions.o output clean execute
output 		: $(Objects)
				$(cc) $(Objects) -o $(out)
Stack.o 	: Stack.c Stack.h
		  		$(cc) -c Stack.c
Functions.o : Functions.c Stack.h
				$(cc) -c Functions.c
clean 		: 
				rm -f *.o
execute		:	
				./$(out)								