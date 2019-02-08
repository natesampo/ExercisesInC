/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5


/*
    This funciton initializes and fills an array of size 5
    with the integer 42 and returns a pointer to the head
    of that array. It also prints the address in memory
    of that array.
*/
int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

/*
    This funciton initializes and fills an array of size 5
    with an integer equal to the corresponding index and
    does not have a return value.
*/
void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

/*
    The main function runs both foo() and bar(), assigning
    the return value of foo() to an array named 'array'.
    It then iterates through the array and prints the value
    of each element.

    When compiling, I received an error:
    "function returns address of local variable"

    When running the compiled program, both print statements
    work (one for each of foo() and bar()), then I receive
    a segfault when trying to index array[i] on the first pass
    of the for loop in main().

    I believe these issues are caused by the fact that when
    a function returns, its stack frame and memory contained
    within is deallocated. This is why both foo() and bar()
    print the same memory address, foo() first writes to that
    memory address, then its stack frame is deallocated. bar()
    is then added to the stack in the same location as foo()
    previously was, so it writes to the same memory address.
    However, when bar() is deallocated following the return,
    our pointer is pointing to a deallocated and now illegal
    memory address, so we receive a segfault.
*/
int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
