#include<iostream>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
using namespace std;
int main(){
	int id,*var;
	key_t key;
	key = ftok("key.txt",65);
	id=shmget(key,50,0664|IPC_CREAT);
	cout << "Shared memory Identifier " << id <<endl;
	var = (int *)shmat(id,NULL,0);
	*var = 50;
	shmdt(var);
	return 0;
}
