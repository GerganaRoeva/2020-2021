//--------------------------------------------
// NAME: Гергана Роева
// CLASS: Xiб
// NUMBER: 8
// PROBLEM: #3
// FILE NAME: stacraft3.c (unix file name)
// FILE PURPOSE:
// Реализация на прототип на
// StarCraft III
// ...
//---------------------------------------------
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

//--------------------------------------------
// FUNCTION: are_mines_empty (име на функцията)
// проверява дали всички стойности на масив са 0
// PARAMETERS:
// указател към първия елемент от масив и брой елементи
//----------------------------------------------
int are_mines_empty(int mines[], int num_mines)
{
    int count_empty = 0;
    for (size_t i = 0; i < num_mines; i++)
    {
        if(mines[i] == 0) count_empty++;
    }
    return count_empty == num_mines;
}

//--------------------------------------------
// FUNCTION: workers_job (име на функцията)
// работата, която работника извършва
// PARAMETERS:
// индекса на работника
//----------------------------------------------
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
            if(!pthread_mutex_trylock(&mutex_for_mine[i - 1]))
            {
                printf("SCV %d is mining from mineral block %d\n", *index, i);
                sleep(3);
                // sleep(1);
                
                if(mine[i - 1] < 8)
                    send = mine[i - 1];
                else
                    send = 8;

                mine[i - 1] = mine[i - 1] - send;
                pthread_mutex_unlock(&mutex_for_mine[i - 1]);
                printf("SCV %d is transporting minerals\n", *index);

                sleep(2);
                // sleep(1);

                pthread_mutex_lock(&mutex_for_bank);
                mirals_bank = mirals_bank + send;
                pthread_mutex_unlock(&mutex_for_bank);
                printf("SCV %d delivered minerals to the Command Center\n", *index);

            }
        }
        i++;

        if(are_mines_empty(mine, num_mines)) return NULL;
    }
}


int main(int argc, char const *argv[])
{
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

    mutex_for_mine = malloc(num_mines*sizeof(pthread_mutex_t));

    pthread_t* worker_thr = malloc(THREADS_SCV*sizeof(pthread_t));
    int index[THREADS_SCV];
    int err;


    pthread_mutex_init(&mutex_for_bank, NULL);

    for (int i = 0; i < num_mines; i++)
    {
        pthread_mutex_init(&mutex_for_mine[i], NULL);
    }

    for(int i = 0; i < THREADS_SCV ; i++)
    {
        index[i] = i + 1;
        
        if((err = pthread_create(&worker_thr[i], NULL, &workers_job, &index[i])))
        {
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
            mirals_bank = mirals_bank - 50;
            pthread_mutex_unlock(&mutex_for_bank);
            sleep(1);
            soldiers_count++;

            printf("You wanna piece of me, boy?\n");
        }
        else if(command == 's' && mirals_bank >= 50){
            pthread_mutex_lock(&mutex_for_bank);
            mirals_bank = mirals_bank - 50;
            pthread_mutex_unlock(&mutex_for_bank);
            sleep(4);
            bonus_SCV++;
            worker_thr = realloc(worker_thr, (THREADS_SCV + bonus_SCV)*sizeof(pthread_t));
            indexx = THREADS_SCV + bonus_SCV;

            if((err = pthread_create(&worker_thr[THREADS_SCV + bonus_SCV - 1], NULL, &workers_job, &indexx)))
            {
                perror("error in thr: ");
                return 1;
            }

            printf("SCV good to go, sir.\n");
        }
    }        

    for(int i = 0; i < (THREADS_SCV + bonus_SCV); i++)
    {
        err = pthread_join(worker_thr[i], NULL);
        if(err != 0)
        {
            printf("error in join: %s\n", strerror(err));
            return 1;
        }
    }
    
    for (int i = 0; i < num_mines; i++)
        pthread_mutex_destroy(&mutex_for_mine[i]);

    pthread_mutex_destroy(&mutex_for_bank);

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", num_mines*500, mirals_bank, THREADS_SCV + bonus_SCV, soldiers_count);

    free(worker_thr);
    free(mutex_for_mine);

    
    return 0;
}
