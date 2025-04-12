#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
	int myfd;
	myfd = open("test1.txt", O_RDONLY); 
	myfd = open("test2.txt", O_RDONLY); 
	printf("%d", myfd);
	return 0;
}
