#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define DRIVERS 20
#define CARS 5
pthread_mutex_t mutex;


void* A(void* n)
{
    int* N = (int *)n;
    for (int i = 0; i < CARS; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Buyer %d takes car %d.\n", *N, i);
        pthread_mutex_unlock(&mutex);
        printf("Buyer %d returns car %d.\n", *N, i);

        return NULL;

    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t driver[DRIVERS];
    // pthread_t driver;
    int err;

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < DRIVERS; i++)
    {
        if((err = pthread_create(&driver[i], NULL, &A, &i)))
        {
            printf("error in thr1: %s\n", strerror(err));
            return err;
        }
    }

    for (int i = 0; i < DRIVERS; ++i) {
        pthread_join(driver[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    


    return 0;
}


