all: counter counter_array_mutex

counter: counter.c
	gcc -Wall -o counter counter.c -lpthread

counter_array_mutex: counter_array_mutex.c mutex.c
	gcc -Wall -o counter_array_mutex counter_array_mutex.c mutex.c -lpthread

barrier: barrier.c utils.c
	gcc -Wall -std=c99 -o barrier barrier.c utils.c -lpthread

barrier_soln: barrier_soln.c utils.c
	gcc -Wall -std=c99 -o barrier_soln barrier_soln.c utils.c -lpthread

read_write: read_write.c utils.c
	gcc -Wall -std=c99 -o read_write read_write.c utils.c -lpthread

read_write_soln: read_write_soln.c utils.c
	gcc -Wall -std=c99 -o read_write_soln read_write_soln.c utils.c -lpthread

mutex: mutex.c
	gcc -Wall -o mutex mutex.c -lpthread