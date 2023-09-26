#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string>

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int dConnect = connect(sockfd, addr, addrlen);
    if (dConnect == -1) {
        perror("Error to connect to server");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton (int af, const char *src, void *dst) {
    int wInet_pton = inet_pton(af, src, dst);
    if (wInet_pton == 0) {
        std::cout << "Error to connect" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(wInet_pton == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}


int main() {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    char buf[1024];

    struct sockaddr_in server_side;
    server_side.sin_family = AF_INET;
    server_side.sin_port = htons(34543);

    Inet_pton(AF_INET,"127.0.0.1", &server_side.sin_addr);

    Connect(client_fd,(struct sockaddr *)&server_side, sizeof(server_side));

    char msg[] = "Hello all newbies";

    write(client_fd, msg, 6);
    size_t nread;
    nread = read(client_fd, buf, sizeof(buf));
    if (nread == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        std::cout << "End of file" << std::endl;
    }
    write(STDOUT_FILENO, buf, nread);
    std::cout << std::endl;
    close(client_fd);


return 0;
}
