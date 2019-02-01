#include <stdio.h>
#include <stdlib.h>

/*
	Takes an input of two characters representing the card and returns the value
	of the card such that:

	11 represents an ace
	10 represents a face card
	1-10 represents the corresponding number card (including the number 1)
	0 represents a card that does not exist

	If the card is one that does not exist, put "I don't understand that value"
*/
int card_value(char card_name[2])
{
	int val = 0;

	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			return 10;
		break;
		case 'A':
			return 11;
		break;
		case 'X':
			return 0;
		default:
			val = atoi(card_name);

			if ((val < 1) || (val > 10)) {
				puts("I don't understand that value");
				return 0;
			}

			return val;
	}
}

/*
	Returns the change in the count variable depending on the input card. The
	change is made according to these metrics:

	+1: The card is greater than 2 and less than 7
	0: The card is not between 2 and 7, and is not a face card
	-1: The card is a face card
*/
int update_count(int val)
{
	if ((val > 2) && (val < 7)) {
		return 1;
	} else if (val == 10) {
		return -1;
	}

	return 0;
}

/*
	Runs the main loop of the program. On every iteration, the user is asked
	to input a card. The count variable will keep track of the score of all
	of the previously played cards and is updated every iteration.
*/
int main()
{
	char card_name[3];
	int count = 0;
	do {
		// Asks user to input the card
		puts("Enter the card_name: ");
		scanf("%2s", card_name);

		// Updates the count depending on the value of the card
		count += update_count(card_value(card_name));

		// Print current count
		printf("Current count: %i\n", count);
	} while (card_name[0] != 'X');
	return 0;
}