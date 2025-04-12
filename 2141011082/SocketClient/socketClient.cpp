#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>


using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <IP Address> <Port>" << endl;
        return 1;
    }

    int sockfd, n;
    char recvline[1024];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Error: Unable to create socket" << endl;
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]); 
    servaddr.sin_port = htons(atoi(argv[2])); 

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        cerr << "Error: Connection failed" << endl;
        close(sockfd);
        return 1;
    }

    n = read(sockfd, recvline, sizeof(recvline) - 1);
    if (n < 0) {
        cerr << "Error: Read failed" << endl;
    } else {
        recvline[n] = '\0';
        cout << "Received: " << recvline << endl;
    }

    close(sockfd);
    return 0;
}
