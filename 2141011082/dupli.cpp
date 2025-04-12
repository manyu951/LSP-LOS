#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main() {
    int fd;

    fd = open("duptest.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    cout << "File descriptor: fd=" << fd << endl;

    dup(STDOUT_FILENO);

    close(1);
     
    dup(fd);

    close(fd);
    write(STDOUT_FILENO,"USP \n",4);
    write(STDOUT_FILENO,"DOS \n",4);

    return 0;
}
