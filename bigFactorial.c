/***********************************************************
    NAME:       Big Factorial
    PURPOSE:    To calculate the factorial of a large number
    AUTHOR:     sixreals
    CREATED:	    28/2/19
    LAST MODIFIED:  28/2/19
************************************************************/



#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned long factorial(int n)
{
    unsigned long toler = 0; 
    /* toler is 0 if n == 0; change if n > 0 */
    long ii;

    if( n > 0 )
    {
        toler = 1;

        for( ii=1; ii <= n; ii++ )
        /* multiplies toler up to n, emulating factorial funciton */
        {   
            /* used for loop testing
            printf("%ld", ii);
            printf("\n"); */

            toler *= ii;
        }
    }
    
    return toler;
}

int bigNumberFactorial(int n)
{
    int ii;
    int index;
    int toler = 0;
    int remainderNum = 0;
    int arraySize = 1000000;
    int bigNumber[1000000]; 
    /*largest array size is 32767bytes, short is 4bytes*/
    memset(bigNumber, -1, arraySize);
    /* sets all values of bigNumber to -1, -1 means the end of the array*/

    bigNumber[0] = 1;

    for( ii = 1 ; ii <= n; ii++ )
    {
        /* tells the program how far to go per iteration */

        index = 0;

        do
        {
            /*  THE BRAINS OF THE OPERATION
                adds numbers together like you used to in primary school,
                add each digit one at a time, carry the remainder etc.
                except this uses an array so it can handle huge numbers */

             toler = (bigNumber[index] < 0) ? 0 : ii * bigNumber[ index ];
             bigNumber[ index ] = toler;
             bigNumber[ index ] += remainderNum;
             remainderNum = bigNumber[ index ]/10;
             bigNumber[ index ] %= 10;

            /*** USED FOR ERROR CHECKING
             printf("toler: %d\t", toler);
             printf("remainderNum 2: %d\n", remainderNum);
            ***/

             index++;
        } while( ((remainderNum != 0) || (bigNumber[index] != -1))
             && (index < arraySize) );
    /*will exit if remainder is empty or it has reached the end of the
 * number. This loop cannot continue if it has reached the max array size.*/
        bigNumber[ index ] = -1; /*-1 marks end of array*/
    }

    if (index < arraySize)
    {
        index = 1;
        while ( bigNumber[index] != -1)
        /*index=-0 will have to be printed regardless*/
        {
            index++;
        }
        index--;
        /*index will point to -1 if not decremented*/

        for( ii = index; ii >= 0; ii-- )
        {
            printf( "%d", bigNumber[ii] );

            if( ii%3 == 0)
            /*adds spaces every 3 digits*/
            {
                printf(" ");
            }
        }
    }
    else
    {
        printf("The number you entered is too big! :'(\n");
    }
    
    
    return 0;
}

int main(void)
{
    long number;

    printf("\nFACTORIAL CALCULATOR\nTested up to 50 000!\n\n");
    printf("Enter number for factorial calculation: ");
    scanf("%ld", &number);
    printf("%ld! =\n", number);

    while(number >= 0)
    {
        /* this is a less intensive function on memory
        if(number < 19)
        {
            printf("%lu", factorial( number ));
        }
        else
        { */
        bigNumberFactorial(number);  
     /* } */
        /* I have commented the above out because the latter function
            prints numbers that have spaces every 3 digits. Looks nicer*/
        printf("\n\nEnter number for factorial calculation: "); 
        scanf("%ld", &number);
	printf("%ld! =\n ", number);
        /*rescans so that if number < 0, while loop will pick it up.*/
    }
    
    printf("Number is less than zero!\n\n"); 

    return 0;
}

/*
MIT License

Copyright (c) 2019 sixreals

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
