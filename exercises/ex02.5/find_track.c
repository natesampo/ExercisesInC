/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    regex_t regex;

    // Check if the user input can be translated to a regular
    // expression. If so, store the regular expression into
    // the variable 'regex'. If not, print "Invalid regex" and
    // return.
    if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        puts("Invalid regex");
        return;
    }

    // Iterate through all of the tracks and check each one
    // for a match with the regular expression stored in
    // 'regex'. If we encounter a match, print it and
    // continue.
    for (int i=0; i<NUM_TRACKS; i++) {
        if (regexec(&regex, tracks[i], 0, NULL, 0) == 0) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }

    // Free the memory allocated to the 'regex' variable.
    regfree(&regex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
