// name: Jonathan Mowat
// email: mowat.j@northeastern.edu
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];//lock variable

// Thread to be executed
void *philosopher(void *x)
{
    //Treat variable x as a pointer to an int and then extract the value into n
    int* a=(int*)x;
    int n=*a;
    
    /*-----Insert your code here----*/
    while (1) {
        // Philosopher is thinking
        printf("Philosopher %d is thinking.\n", n + 1);
        // sleep(1); // Simulate thinking

        int left = n;
        int right = (n + 1) % 5;

        // pick up the left chopstick
        pthread_mutex_lock(&chopstick[left]);

        // Check if the right chopstick is available
        if (pthread_mutex_trylock(&chopstick[right]) == 0) {
            // Philosopher is eating - both locks are acquired
            printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d].\n", n + 1, left, right);

            // Philosopher puts down the chopsticks - release both locks
            pthread_mutex_unlock(&chopstick[right]);
            pthread_mutex_unlock(&chopstick[left]);

            break; // exit the while loop
        } else {
            // Couldn't get right chopstick Put down the left chopstick and wait to try again
            pthread_mutex_unlock(&chopstick[left]);
            sleep(1); // Wait before trying again to acquire both locks 
        }
    }

    // Philosopher finished eating
    printf("Philosopher %d finished eating.\n", n + 1);
    return NULL;
    
}


/*------------ Main Program---------*/
int main()
{
    int i,val[5];
    pthread_t threads[5];
    //initializing the mutex (for chopsticks)
    for(i=0;i<5;i++){
        pthread_mutex_init(&chopstick[i],NULL);
    }   

    //create and run the thread
    for(i=0;i<5;i++){
        val[i]=i;
        pthread_create(&threads[i],NULL,(void *)philosopher,&val[i]);
    }
    
    //wait until all the threads are done
    for(i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
    
    // Destroying the mutex
    for(i=0;i<5;i++){
        pthread_mutex_destroy(&chopstick[i]);
    }
    
    return 0;
}