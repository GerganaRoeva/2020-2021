#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREADS_SCV 5

pthread_mutex_t* mutex_for_mine;
pthread_mutex_t mutex_for_bank;
// pthread_mutex_t mutex_for_mapmineral;

int num_mines;
int mirals_bank = 0;
int soldiers_count = 0;
int* mine;

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
    int* index = (int*)arg;

    int i = 1;
    int send;

    while(1)
    {
        if(i > num_mines) i = 1;
        if(mine[i - 1] > 0)
        {
        // int res_lock = pthread_mutex_trylock(&mutex_for_mine[i - 1]);
            if(pthread_mutex_trylock(&mutex_for_mine[i - 1]) == 0)
            {
                printf("SCV %d is mining from mineral block %d\n", *index, i);
                sleep(3);
                // sleep(1);
                
                if(mine[i - 1] < 8)
                {
                    send = mine[i - 1];
                    mine[i - 1] = 0;
                }
                else
                {
                    mine[i - 1] -= 8;
                    send = 8;
                }
                printf("SCV %d is transporting minerals\n", *index);
                pthread_mutex_unlock(&mutex_for_mine[i - 1]);

                sleep(2);
                // sleep(1);

                pthread_mutex_lock(&mutex_for_bank);
                mirals_bank += send;
                printf("SCV %d delivered minerals to the Command Center\n", *index);
                pthread_mutex_unlock(&mutex_for_bank);

                // pthread_mutex_lock(&mutex_for_mapmineral);

                // for (int z = 0; z < num_mines; z++)
                // {
                //     printf("Mine %d, %d\n", z + 1, mine[z]);
                // //     map_minerals += mine[z];
                // }

                // pthread_mutex_unlock(&mutex_for_mapmineral);

                // printf("bank: %d\n", mirals_bank);
                // printf("soldiers_count: %d\n", soldiers_count);
            }
        }
        i++;

        if(are_mines_empty(mine, num_mines) && soldiers_count == 20)
        {
            return NULL;    
        }
    }
}


int main(int argc, char const *argv[])
{
    // printf("test1\n");
    int bonus_SCV = 0;

    num_mines = 2;
    if(argc > 1)
    {
        num_mines = atoi(argv[1]);
    }

    int mines[num_mines];
    for (size_t i = 0; i < num_mines; i++)
    {
        mines[i] = 500;
    }
    mine = mines;

    mutex_for_mine = malloc(THREADS_SCV*sizeof(pthread_mutex_t));

    pthread_t* worker_thr = malloc(THREADS_SCV*sizeof(pthread_t));
    int index [THREADS_SCV];
    int err;
    // printf("test1\n");


    pthread_mutex_init(&mutex_for_bank, NULL);
    // printf("test1\n");

    for (int i = 0; i < THREADS_SCV; i++)
    {
        // printf("test1\n");
        pthread_mutex_init(&mutex_for_mine[i], NULL);
    }

    // pthread_mutex_init(&mutex_for_mapmineral, NULL);

    // printf("test2\n");

    for(int i = 0; i < THREADS_SCV ; i++)
    {
        index[i] = i + 1;
        
        if((err = pthread_create(&worker_thr[i], NULL, &workers_job, &index[i])))
        {
            // printf("error in thr: %s\n", strerror(err));
            perror("error in thr: ");
            return 1;
        }
    }

    char command;
    int indexx;
    while(soldiers_count < 20 && bonus_SCV < 180)
    {
        command = getchar();
        if((command == 'm' || command == 's') && mirals_bank < 50)
        {
            printf("Not enough minerals.\n");
        }
        else if(command == 'm' && mirals_bank >= 50)
        {
            pthread_mutex_lock(&mutex_for_bank);
            mirals_bank -= 50;
            pthread_mutex_unlock(&mutex_for_bank);
            sleep(1);
            soldiers_count++;

            printf("You wanna piece of me, boy?\n");
        }
        else if(command == 's' && mirals_bank >= 50){
            pthread_mutex_lock(&mutex_for_bank);
            mirals_bank -= 50;
            pthread_mutex_unlock(&mutex_for_bank);
            sleep(4);
            bonus_SCV++;
            worker_thr = realloc(worker_thr, (THREADS_SCV + bonus_SCV)*sizeof(pthread_t));
            indexx = THREADS_SCV + bonus_SCV;

            if((err = pthread_create(&worker_thr[THREADS_SCV + bonus_SCV - 1], NULL, &workers_job, &indexx)))
            {
                // printf("error in thr: %s\n", strerror(err));
                perror("error in thr: ");
                return 1;
            }

            printf("SCV good to go, sir.\n");
        }
    }        

    
    // pthread_mutex_destroy(&mutex_for_mapmineral);

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", num_mines*500, mirals_bank, THREADS_SCV + bonus_SCV, soldiers_count);

    free(mutex_for_mine);

    for (int i = 0; i < THREADS_SCV; i++)
        pthread_mutex_destroy(&mutex_for_mine[i]);

    pthread_mutex_destroy(&mutex_for_bank);
    // printf("bonus: %d", bonus_SCV);

    for(int i = 0; i < (THREADS_SCV + bonus_SCV); i++)
    {
        err = pthread_join(worker_thr[i], NULL);
        if(err != 0)
        {
            // perror("error in join");
            // printf("i: %d\n", i);
            printf("error in join: %s\n", strerror(err));

            return 1;
        }
    }
    free(worker_thr);
    
    return 0;
}
