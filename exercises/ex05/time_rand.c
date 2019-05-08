/*  Test code for the functions in rand.c

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

#include "rand.h"

/*
    Output of this program (without random double):

    210.269000 ms    dummy
    843.621000 ms    dummy2
    948.959000 ms    random_float
    868.513000 ms    my_random_float
    2178.453000 ms   my_random_float2
    894.993000 ms    random_float

    dummy was the fastest, but that is to be expected as it doesn't actually
    generate a random number and just returns 0.5. The fastest random function
    is dummy2, because that just takes a random number and casts it to a float,
    and does no other operations.


    Output (with random double):

    213.791000 ms    dummy
    864.028000 ms    dummy2
    886.686000 ms    random_float
    934.314000 ms    my_random_float
    2106.218000 ms   my_random_float2
    890.816000 ms    random_float
    877.385000 ms    random_double
    879.545000 ms    my_random_double

    random_double was slightly faster than my_random_double, but not by much,
    only 2ms faster.
*/

/* Get the total of user time and system time used by this process.
*/
double get_seconds() {
    double user, sys;
    struct rusage r;

    getrusage(RUSAGE_SELF, &r);

    user = r.ru_utime.tv_sec * 1000.0 + r.ru_utime.tv_usec / 1000.0;
    sys = r.ru_stime.tv_sec * 1000.0 + r.ru_stime.tv_usec / 1000.0;

    // printf("%lf\n", user);

    return user+sys;
}

/* Compute the total time used by a function.

iters: number of times to call the function
func: function to call
*/
double time_func(int iters, float(*func)())
{
    int i;
    float f;
    double t0, t1;

    srandom(time(NULL));

    t0 = get_seconds();
    for (i=0; i<iters; i++) {
        f = func();
    }
    t1 = get_seconds();
    return t1 - t0;
}


int main(int argc, char *argv[])
{
    double time;
    int iters = 100000000;
    int seed = 17;

    time = time_func(iters, dummy);
    printf("%f ms \t dummy\n", time);

    time = time_func(iters, dummy2);
    printf("%f ms \t dummy2\n", time);

    time = time_func(iters, random_float);
    printf("%f ms \t random_float\n", time);

    time = time_func(iters, my_random_float);
    printf("%f ms \t my_random_float\n", time);

    time = time_func(iters, my_random_float2);
    printf("%f ms \t my_random_float2\n", time);

    time = time_func(iters, random_float);
    printf("%f ms \t random_float\n", time);

    time = time_func(iters, random_float);
    printf("%f ms \t random_double\n", time);

    time = time_func(iters, random_float);
    printf("%f ms \t my_random_double\n", time);

    return 1;
}
