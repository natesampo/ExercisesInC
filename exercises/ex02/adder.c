/*
	This file contains the code written for Exercise 2 of Software Systems 2019.

	In particular, this file is an adder where the user inputs a list of numbers to
	be summed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Takes two arguments:
	int *numbers: the list of numbers that the user input
	int size: the populated size of the array. Elements past this integer were not
	input by the user and are dangerous territory.

	This function iterates through every element of the numbers array and adds
	that element to a running total, called sum. We only iterate up to the second
	argument, size, because the user only input data up this number, and all
	data past this point was allocated but not written to.
*/
int add_array(int *numbers, int size)
{
	int i;
	int sum = 0;

	for(i = 0; i < size; i++){
		sum += numbers[i];
	}

	return sum;
}

/*
	The main function runs the while loop that continually prompts the user to
	input numbers to be added together. The maximum number of numbers is 20,
	and after this point the loop will be broken and whatever the current sum
	is will be printed.
*/
int main(){
	int i = 0;
	int numbers[20];
	char input_buffer[8];

	puts("Enter the numbers to be summed:");
	while(fgets(input_buffer, sizeof(input_buffer), stdin))
	{

		// atoi returns 0 when the user input characters instead of numbers,
		// or they input 0, which is irrelevant when adding numbers together.
		if (atoi(input_buffer) == 0)
		{
			puts("Input is non-integer or zero!");
		}

		// If there is no newline character (\n), we know that the user input
		// too many digits, so let them know that they exceeded our input
		// buffer.
		else if (strchr(input_buffer, '\n') == NULL)
		{
			puts("Input is too large!");
		}

		// If we make it here, the user has input a correctly sized integer,
		// so add it to the numbers array and iterate by one.
		else
		{
			numbers[i] = atoi(input_buffer);
			i++;
		}

		// If this is the 20th input, break the loop as our array is only
		// of size 20 and can't hold any more numbers
		if (i == 20) {
			break;
		}
	}

	int sum = add_array(numbers, i);

	printf("Total sum: %d\n", sum);

	return 0;
}