#include "error_proccessing.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>


int main(){

    int server = Socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_addr.s_addr = inet_addr("127.0.0.1");
    adr.sin_port = htons(34543);

    Bind(server, (struct sockaddr *)&adr, sizeof(adr));
    std::cout << "Starting listen..." << std::endl;
    Listen(server, 5);

    struct sockaddr_in client = {0};
    socklen_t c_adrlen = sizeof(client);
    int fd = Accept(server,(struct sockaddr *) &client, &c_adrlen);

    ssize_t read_from_client;
    char buf[1024];
    read_from_client = read(fd, buf, 1024);
    if(read_from_client == -1) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    if(read_from_client == 0) {
        std::cout << "---END OF FILE---" << std::endl;
    }
    write(STDOUT_FILENO, buf, read_from_client);
    write(fd, buf, read_from_client);
    std::cout << std::endl;

    sleep(3);

    close(fd);
    close(server);

return 0;
}
