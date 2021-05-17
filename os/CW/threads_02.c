#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSZ 200

void *read_safe(void **buf)
{

    return NULL;
}

void *write(void **buf)
{

    return NULL;
}

int main(int argc, char const *argv[])
{
    
        int rc;
        pthread_t thr1, thr2;
        phtread_mutex_init(&buf_mutex, NULL);


        rc = pthread_create(&thr1, NULL, &read_safe, NULL);
	    if(rc)
        {
            printf("ERROR: thread 1 pthread_create() return %d - %s \n", rc, strerror(rc));
	        return 1;
	    }

        rc = pthread_create(&thr2, NULL, &write, NULL);
	    if(rc)
        {
            printf("ERROR: thread 2 pthread_create() return %d - %s \n", rc, strerror(rc));
	        return 1;
	    }

        pthread_join(thr1, NULL);
        pthread_join(thr2, NULL);

        pthread_mutex_destroy(&buf_mutex);
    }

    return 0;
}
