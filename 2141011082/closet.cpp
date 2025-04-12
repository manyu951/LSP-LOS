#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	char buf[100];
	int fd1,fd2,n;
	fd1 = open("test1.txt", O_RDONLY); 
	fd2 = open("test2.txt", O_RDWR); 
    n = read(fd1,buf,70);
    write(fd2,buf,n);
	close(fd1);
	close(fd2);
	return 0;
}

