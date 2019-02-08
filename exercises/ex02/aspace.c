/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    // Second malloc call
    void *q = malloc(128);
    printf ("q points to %p\n", q);

    // Print address of local variable
    int var3 = 10;
    printf ("Address of var3 is %p\n", &var3);

    // Allocate two chunks of size 16
    void *chunk1 = malloc(16);
    void *chunk2 = malloc(16);
    printf ("chunk1 points to %p\n", chunk1);
    printf ("chunk2 points to %p\n", chunk2);

    /*
		The addresses I received for each chunk are:
		chunk1: 0x556c1807b790
		chunk2: 0x556c1807b7b0

		These are 0x20 apart
		In decimal, these addresses are 32 bytes apart

		No matter what size I make each malloc, the 32 byte seperation does not change
    */


    return 0;
}
