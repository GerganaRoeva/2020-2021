#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

struct Data_t
{
    int start;
    int end;
};

void *sum(void **arr_of_ints)
{

}

int main(int argc, char const *argv[])
{
    char buffer[256];
    int threads_count, nums_max;
    int part_sum = 0;

    printf ("Enter a number of threads: ");
    fgets (buffer, 256, stdin);
    threads_count = atoi (buffer);

    printf ("Enter a numbers to sum: ");
    fgets (buffer, 256, stdin);
    nums_max = atoi (buffer);

    pthread_t threads[threads_count];
    int start, end, step;

    step = nums_max / threads_count
    start = 1;
    end = step - 1;
    for(int t = 0; t < threads_count; t++)
    {
        struct Data_t data = malloc(sizeof(struct Data_t));
        data->start = start;
        data->end = end;

	    int res_pc = pthread_create(&threads[t], NULL, &sum, (void *)pt);
	    if(res_pc != 0)
        {
            printf("ERROR; pthread_create() return %d - %s \n", res_pc, (void*)data);
	        return res;
	    }

        start = end + 1;
        end = start + step - 1;
	}

    
    
    for(int t=0; t<threads_count; t++)
    {
        pthread_join(threads[t], part_sum);
    }

	printf("MAIN going to exit...\n");
	pthread_exit(NULL);
	return 0;
}

