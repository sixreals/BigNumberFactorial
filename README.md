# BigNumberFactorial
A program which can calculate the factorials of very large integers.
Potential for updates could be to use linked lists for the digit array and create a GUI for user convenience.

PURPOSE:
Program can successfully calculate the factorial of a number up to 50 000. Larger numbers have been attempted.
BE WARNED! This can take quite some time

METHOD:
The program works by using arrays instead of long long longs.
Each index of the array represents a digit of the factorial.
For each iteration of the factorial, each index of the array is multiplied by the current number of the factorial.
This is kind of like primary school arithmetic where you multiply each digit and find the remainder.
The program then takes the modulus of 10 of the number and passes everything that is not the first digit to the index above it.
The process then repeats for the above index.

LIMITATIONS:
It can become very slow for large numbers
The array must be initialised to be very large. WOuld be better to implement a linked list.
