#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    sem_t *sem1 = sem_open("/sem1", O_CREAT, 0644, 1);
    sem_t *sem2 = sem_open("/sem2", O_CREAT, 0644, 0);

    pid_t pid = fork();

    if (pid == 0) {
        
        while (1) {
            sem_wait(sem2);
            sleep(1);
            fprintf(stderr,"1");
            fprintf(stderr,"1");
            //sleep(0); 
            sem_post(sem1);
        }
    } else {
        
        while (1) {
            sem_wait(sem1);
            sleep(1);
            fprintf(stderr,"0");
            fprintf(stderr,"0");
           // sleep(0); 
            sem_post(sem2);
        }
        
    }

    sem_close(sem1);
    sem_close(sem2);
    sem_unlink("/sem1");
    sem_unlink("/sem2");

    return 0;
}

