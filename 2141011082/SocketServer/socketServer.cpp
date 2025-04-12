#include <iostream> 
#include <cstring> 
#include <ctime> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/in.h>

int main() { 
    int listenfd, connfd, len; 
    struct sockaddr_in servaddr, clientaddr; 
    char buff[1024]; time_t ticks;
    len = sizeof(struct sockaddr_in);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(0);
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }
    getsockname(listenfd, (struct sockaddr *)&servaddr, (socklen_t *)&len);
    std::cout << "After bind ephemeral port=" << ntohs(servaddr.sin_port) << std::endl;
    listen(listenfd, 5);
    connfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&len);
    
    if (connfd < 0) {
        std::cerr << "Accept failed" << std::endl;
        return 1;
    }
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%s\r\n", ctime(&ticks));
    write(connfd, buff, strlen(buff));
    write(connfd, "ITER.\n", 6);
    close(connfd);
    return 0;
}