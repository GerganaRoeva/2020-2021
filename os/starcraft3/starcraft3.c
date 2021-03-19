#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREADS_SCV 5
pthread_mutex_t mutex;

struct info_SCV_t
{
    int SCV_index;
    int num_mines;
    
};

int are_mines_empty(int mines[], int num_mines)
{
    int count_empty = 0;
    for (size_t i = 0; i < num_mines; i++)
    {
        if(mines[i] == 0) count_empty++;
    }
    if(count_empty == num_mines) return 1;
    return 0;
}


void* workers_job(void* arg)
{
    struct info_SCV_t *info = (struct info_SCV_t*) arg;
    
    int num_mines = info->num_mines;
    int SCV_index = info->SCV_index;

    int mines[num_mines];
    for (size_t i = 0; i < num_mines; i++)
    {
        mines[i] = 500;
    }
        
    int i = 0;
    int send;


    while(1)
    {
        sleep(3);
        int res_lock = pthread_mutex_trylock(&mutex);
        if(res_lock == 0)
        {
            mines[i] = mines[i] - 8;
            printf("SCV %d is mining from mineral block %d\n", SCV_index, i);
            // sleep(3);
            if(mines[i] < 0)
            send = 8 + mines[i];
            else send = 8;
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            sleep(3);
            i++;
        }

    }
    


    return NULL;    
}

int main(int argc, char const *argv[])
{
    int num_mines = 2;
    if(argc > 1)
    {
        num_mines = atoi(argv[1]);
    }

    struct info_SCV_t info_for_worker;
    info_for_worker.num_mines = num_mines; 

    pthread_t worker_thr[THREADS_SCV];
    // int index[THREADS_SCV];
    int err;

    for(int i = 0; i < THREADS_SCV; i++)
    {
        info_for_worker.SCV_index = i;
        
        if((err = pthread_create(&worker_thr[i], NULL, &workers_job, &info_for_worker)))
        {
            printf("error in thr1: %s\n", strerror(err));
            return err;
        }
    }
    for(int i = 0; i < THREADS_SCV; i++)
    pthread_join(worker_thr[i], NULL);
    
    return 0;
}
