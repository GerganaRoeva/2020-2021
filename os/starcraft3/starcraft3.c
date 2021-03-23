#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREADS_SCV 5

pthread_mutex_t mutex_for_mine;
pthread_mutex_t mutex_for_bank;
// pthread_mutex_t mutex_for_filmine;

    int num_mines;
    int mirals_bank = 0;
    int soldiers_count = 0;
    int* mine;

struct info_SCV_t
{
    int SCV_index;
    int num_mines;
    int mirals_bank;
    int soldiers_count;
    int* mine;
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
    // struct info_SCV_t *info = (struct info_SCV_t*) arg;
    int* index = (int*)arg;

    int i = 1;
    int send;

    // info->soldiers_count == 20 && 

    while(1)
    {
        if(i > num_mines) i = 1;

        // printf("SCV %d is mining from mineral block %d\n", info->SCV_index, i);

        int res_lock = pthread_mutex_trylock(&mutex_for_mine);
        if(res_lock == 0)
        {
            printf("SCV %d is mining from mineral block %d\n", *index, i);
            mine[i-1] = mine[i-1] - 8;
            sleep(3);
            if(mine[i] <= 8 && mine[i] > 0)
            send = 500%8;
            else if(mine[i] <= 0)
            {
                i++;
                continue;
            }
            else send = 8;
            pthread_mutex_unlock(&mutex_for_mine);

            printf("SCV %d is transporting minerals\n", *index);
            sleep(2);

            // pthread_mutex_trylock(&mutex);
            pthread_mutex_lock(&mutex_for_bank);
            mirals_bank = mirals_bank + send;
            pthread_mutex_unlock(&mutex_for_bank);
            printf("SCV %d delivered minerals to the Command Center\n", *index);
            printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", num_mines*500, mirals_bank, 5, soldiers_count);

            sleep(2);

            for (int z = 0; z < num_mines; z++)
            {
                printf("Mine %d, %d\n", z + 1, mine[z]);
            }
        }
        i++;
        if(are_mines_empty(mine, num_mines)) break;

    }

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d", num_mines*500, mirals_bank, 5, soldiers_count);

    return NULL;    
}



int main(int argc, char const *argv[])
{
    num_mines = 2;
    if(argc > 1)
    {
        num_mines = atoi(argv[1]);
    }

    // struct info_SCV_t info_for_worker;
    // info_for_worker.num_mines = num_mines; 
    // info_for_worker.mirals_bank = 0;
    // info_for_worker.soldiers_count = 0;

    // pthread_mutex_lock(&mutex_for_filmine);
    int mines[num_mines];
    for (size_t i = 0; i < num_mines; i++)
    {
        mines[i] = 500;
    }
    mine = mines;

    // pthread_mutex_unlock(&mutex_for_filmine);


    // info_for_worker.mine = mines;


    pthread_t worker_thr[THREADS_SCV];
    int index [THREADS_SCV];
    int err;

    pthread_mutex_init(&mutex_for_bank, NULL);
    pthread_mutex_init(&mutex_for_mine, NULL);
    // pthread_mutex_init(&mutex_for_filmine, NULL);

    for(int i = 0; i < THREADS_SCV ; i++)
    {
        index[i] = i + 1;
        // printf("SCV_index: %d\n", info_for_worker.SCV_index);
        
        if((err = pthread_create(&worker_thr[i], NULL, &workers_job, &index[i])))
        {
            printf("error in thr: %s\n", strerror(err));
            return 1;
        }
    }

    for(int i = 0; i < THREADS_SCV; i++)
    {
        if((err = pthread_join(worker_thr[i], NULL)))
        {
            printf("error in join: %s\n", strerror(err));
            return 1;
        }
    }

    // char command;
    // command = getchar();

    // if(command == 'm' && info_for_worker.mirals_bank >= 50)
    // {
    //     info_for_worker.soldiers_count++;
    //     info_for_worker.mirals_bank = info_for_worker.mirals_bank - 50;
    // }

    pthread_mutex_destroy(&mutex_for_mine);
    pthread_mutex_destroy(&mutex_for_bank);
    // pthread_mutex_destroy(&mutex_for_filmine);

    // printf("klkll");
    
    return 0;
}
