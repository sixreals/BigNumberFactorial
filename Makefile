CC = gcc
CFLAGS = -ansi -Werror -Wall -pedantic
OBJ = bigFactorial.o
EXEC = bigFactorial

default: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

bigFactorial.o: bigFactorial.c
	$(CC) $(CFLAGS) bigFactorial.c -c

clean:
	rm -f *.o
	rm -f $(EXEC)
