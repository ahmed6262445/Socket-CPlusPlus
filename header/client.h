#ifndef CLIENT_H_
#define CLIENT_H_
#include <sys/socket.h>
#include <arpa/inet.h>

class Client
{
    int socket;
    int valRead;
    int port;

    char buffer[1024];

    struct sockaddr_in serverAddress;

public:
    Client();
    bool sendMessage(const char* message);
    const char* listenMessage();
};
#endif