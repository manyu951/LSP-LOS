#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int shmid;
    int *shvar;
    
    key_t key = ftok("shmfile", 45);
    shmid = shmget(key, 20, 0664 | IPC_CREAT);
    shvar = (int *) shmat(shmid, NULL, 0);
    cout << "Key = " << key << "...........Shmid = " << shmid << endl; 
    shvar = (int *) shmat(shmid, NULL, 0);
    *shvar = 10;
    pid_t pid = fork();
    
    if (pid == 0) {
        *shvar = *shvar + 90;
        cout << "Child update -> shvar = " << *shvar << endl;
        exit(0);
    } else {
        wait(NULL);
        *shvar = *shvar + 110;
        cout << "Parent update -> shvar = " <<  *shvar << endl;
    }
    
    return 0;
}