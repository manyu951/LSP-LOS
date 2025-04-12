#include<iostream>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
using namespace std;
int main(){
	int id,*rvar;
	key_t key;
	key = ftok("key.txt",65);
	id=shmget(key,50,0664);
	cout << "Shared memory Identifier " << id <<endl;
	rvar = (int *)shmat(id,NULL,SHM_R);
	cout << "Value in shared memeory = " << *rvar << endl;
	shmdt(rvar);
	shmctl(id,IPC_RMID,NULL);
	return 0;
}

