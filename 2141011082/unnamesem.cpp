#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <iostream>

using namespace std;
int main()
{
	sem_t sem;
	int rs,val;
	rs = sem_init(&sem,2,6);
	if(rs==0){
		cout << "semaphore created sucessfully " << endl;
	}
	else{
		perror("Falied to create semaphore");
		return 1;
	}
	sem_getvalue(&sem,&val);
	cout << "semaphore value = " << val << endl;
	//using wait(s) operation
	sem_wait(&sem);
	sem_getvalue(&sem,&val);
	cout << "Updated semaphore value after one call to sem_wait() = " << val << endl;
	sem_wait(&sem);
	sem_getvalue(&sem,&val);
	cout << "Updated semaphore value after one call to sem_post() = " << val << endl;
	return 0;
}

