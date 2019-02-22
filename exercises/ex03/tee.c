/*
	Implementation of the tee command in C for Software Systems 2019.

	Example output can be found in the files 'fortune.txt', 'cowsay_fortune.txt',
	'teepipe1.txt', and 'teepipe2.txt'.

	'fortune.txt' was created using by piping output from the fortune program
	into this program: '$ fortune | ./tee fortune.txt'.

	'cowsay_fortune.txt' was created by piping fortune into cowsay and piping that
	into tee: '$ fortune | cowsay | ./tee cowsay_fortune.txt'.

	The two teepipes where created by piping the output from using the help option
	in this program into itself: '$ ./tee -h | ./tee teepipe1.txt teepipe2.txt'.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX_BUFFER 64

int main(int argc, char *argv[]) {
	FILE *output_file;
	char input_buffer[MAX_BUFFER];
	int i, append = FALSE;

	// Handle all options
	// Was originally written as a switch statement, however you cannot use strings in switches

	// Arguments can be passed in any order and you can add more than one option flag, so check
	// all arguments for options.
	for(i=1; i<argc; i++) {

		// Believe me, this looked a LOT more elegant as a switch with nice fall-through cases
		// and a default, but alas now it looks like this :(

		// Basically just handle every case that begins with '-'. If its a case we don't
		// recognize, say that it is an invalid option.
		if(argv[i][0] == '-') {

			if (strcmp(argv[i], "--append") == 0 || strcmp(argv[i], "-a") == 0) {

				append = TRUE;

			} else if(strcmp(argv[i], "--ignore-interrupts") == 0 || strcmp(argv[i], "-i") == 0) {

				puts("Not implemented");
				return 1;

			} else if(strcmp(argv[i], "-p") == 0) {

				puts("Not implemented");
				return 1;

			} else if(strcmp(argv[i], "--output-error") == 0) {

				puts("Not implemented");
				return 1;

			} else if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {

				puts("Use the '-a' argument to enter append mode. Default mode is overwrite.");
				puts("'-i', '-ignore-interrupts', '-p', and '--output-error' were not implemented, but are checked for.");
				puts("You just did it, but '-h' and '--help' open the help menu.");
				puts("Use '-v' or '--version' to find the version number.");
				return 1;

			} else if(strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0) {

				puts("Version 1.0.0. Last updated 2/22/2019 by Nate Sampo.");
				return 1;

			} else {

				printf("Invalid option: %s\n", argv[i]);
				return 1;

			}
		}
	}

	// If we reach this point, one of two things has happened
	// Either we got only an append flag, or we didn't get any flags

	// Here continue looping and writing user input to the files specified
	while (fgets(input_buffer, MAX_BUFFER, stdin)) {

		// Go through all arguments to find all files we are writing to
		for(i=1; i<argc; i++) {

			// Make sure the argument we're currently looking at is not an option flag
			if(argv[i][0] != '-') {

				// Open the file to either append or overwrite
				if (append) {

					output_file = fopen(argv[i], "a");

				} else {

					output_file = fopen(argv[i], "w");

				}

				// Add the user input to the current file, print that we did it,
				// then close the file.
				fputs(input_buffer, output_file);

				printf("Successfully wrote to: %s\n", argv[i]);

				fclose(output_file);

			}
		}

		// After one iteration, we want to begin appending to all files, since we
		// cleared them earlier. If we did not do this, we would constantly clear
		// the files every time the user gave input, rather than clearing at first
		// and appending all user input as expected.
		append = TRUE;
	}

	return 1;
}

// Reflection:
// I saw getopt a lot when browsing Stack Overflow to help me here. I wanted to
// try an implementation by just parsing the actual strings, but getopt is
// definitely the superior option here, and I probably should have used it.
// Another big time sink was forgetting that you can't compare strings in
// C, because it only compares the addresses of the strings. I wrote out the
// entire program using a switch statement, only to realize that you can't do
// that because you can't compare strings in that way.

// Comparison:
// The first thing I noticed is that there are no comments and their code is
// difficult to parse, whereas I hope mine is relatively easy to sift through.
// They used getopt, as I probably should have. They also used pointers much more
// than I did, especially when iterating over the argument list:

// (exitval = 0; *argv; ++argv)

// They do more error checking and use exits when encountering bad user input,
// whereas I print a message and return. Also they used structs, which we
// haven't covered yet, so I'm going to assume I'm ok there.