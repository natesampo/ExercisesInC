/*
    File created for Software Systems 2019

    This file uses MinUnit to test the icmpcode_v4 function in util.c

    I tested every case, its overkill but whatever
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.c"
#include "minunit.h"

int tests_run = 0;

static char *test0() {
    int res = (strcmp(icmpcode_v4(0), "network unreachable") == 0);
    char *message = "test0 failed: icmpcode_v4(0) should return \"network unreachable\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test1() {
    int res = (strcmp(icmpcode_v4(1), "host unreachable") == 0);
    char *message = "test1 failed: icmpcode_v4(1) should return \"host unreachable\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test2() {
    int res = (strcmp(icmpcode_v4(2), "protocol unreachable") == 0);
    char *message = "test2 failed: icmpcode_v4(2) should return \"protocol unreachable\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test3() {
    int res = (strcmp(icmpcode_v4(3), "port unreachable") == 0);
    char *message = "test3 failed: icmpcode_v4(3) should return \"port unreachable\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test4() {
    int res = (strcmp(icmpcode_v4(4), "fragmentation required but DF bit set") == 0);
    char *message = "test4 failed: icmpcode_v4(4) should return \"fragmentation required but DF bit set\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test5() {
    int res = (strcmp(icmpcode_v4(5), "source route failed") == 0);
    char *message = "test5 failed: icmpcode_v4(5) should return \"source route failed\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test6() {
    int res = (strcmp(icmpcode_v4(6), "destination network unknown") == 0);
    char *message = "test6 failed: icmpcode_v4(6) should return \"destination network unknown\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test7() {
    int res = (strcmp(icmpcode_v4(7), "destination host unknown") == 0);
    char *message = "test7 failed: icmpcode_v4(7) should return \"destination host unknown\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test8() {
    int res = (strcmp(icmpcode_v4(8), "source host isolated (obsolete)") == 0);
    char *message = "test8 failed: icmpcode_v4(8) should return \"source host isolated (obsolete)\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test9() {
    int res = (strcmp(icmpcode_v4(9), "destination network administratively prohibited") == 0);
    char *message = "test9 failed: icmpcode_v4(9) should return \"destination network administratively prohibited \"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test10() {
    int res = (strcmp(icmpcode_v4(10), "destination host administratively prohibited") == 0);
    char *message = "test10 failed: icmpcode_v4(10) should return \"destination host administratively prohibited\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test11() {
    int res = (strcmp(icmpcode_v4(11), "network unreachable for TOS") == 0);
    char *message = "test11 failed: icmpcode_v4(11) should return \"network unreachable for TOS\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test12() {
    int res = (strcmp(icmpcode_v4(12), "host unreachable for TOS") == 0);
    char *message = "test12 failed: icmpcode_v4(12) should return \"host unreachable for TOS\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test13() {
    int res = (strcmp(icmpcode_v4(13), "communication administratively prohibited by filtering") == 0);
    char *message = "test13 failed: icmpcode_v4(13) should return \"communication administratively prohibited by filtering\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test14() {
    int res = (strcmp(icmpcode_v4(14), "host recedence violation") == 0);
    char *message = "test14 failed: icmpcode_v4(14) should return \"host recedence violation\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test15() {
    int res = (strcmp(icmpcode_v4(15), "precedence cutoff in effect") == 0);
    char *message = "test15 failed: icmpcode_v4(15) should return \"precedence cutoff in effect\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test16() {
    int res = (strcmp(icmpcode_v4(16), "[unknown code]") == 0);
    char *message = "test16 failed: icmpcode_v4(16) should return \"[unknown code]\"";
    mu_assert(message, res == 1);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test0);
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    mu_run_test(test4);
    mu_run_test(test5);
    mu_run_test(test6);
    mu_run_test(test7);
    mu_run_test(test8);
    mu_run_test(test9);
    mu_run_test(test10);
    mu_run_test(test11);
    mu_run_test(test12);
    mu_run_test(test13);
    mu_run_test(test14);
    mu_run_test(test15);
    mu_run_test(test16);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
