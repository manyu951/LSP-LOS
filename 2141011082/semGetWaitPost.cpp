#include <iostream>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;
int main() {
    const char* n1 = "/mysemaphore1";
    sem_t* K;
    int val;

    // Open or create the semaphore
    K = sem_open(n1, O_CREAT | O_RDWR, 0644, 15);

    // Print the address of the semaphore
    cout << "Semaphore address: " << K << endl;

    // Get the current value
    sem_getvalue(K, &val);
    cout << "Initial value: " << val << endl;

    // Increment the value by 1
    sem_post(K);
    sem_getvalue(K, &val);
    cout << "Value after sem_post: " << val << endl;
    
    // Decrements the value by 1
    sem_wait(K);
    sem_getvalue(K, &val);
    cout << "Value after sem_post: " << val << endl;

    sem_close(K);
    sem_unlink(n1);

    return 0;
}