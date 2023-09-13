#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>

int Socket(int domain, int type, int protocol);

void Listen(int sockfd, int backlog);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

