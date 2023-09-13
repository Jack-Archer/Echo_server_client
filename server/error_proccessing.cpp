#include "error_proccessing.h"


#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol) {
    int dSocket = socket(domain, type, protocol);
    if (dSocket == -1) {
        perror("Open failed say pError");
        exit(EXIT_FAILURE);
    }
    return dSocket;
}

void Listen(int sockfd, int backlog){
    int dListen = listen(sockfd, backlog);
    if(dListen == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int dBind = bind(sockfd, addr, addrlen);
    if(dBind == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int dAccept = accept(sockfd, addr, addrlen);
    if(dAccept == -1) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    return dAccept;
}

