#ifndef SERVER_H_
#define SERVER_H_
#include<sys/socket.h>
#include<netinet/in.h>

class Server
{
    int serverFd;
    int socket;
    int valRead;
    int opt;
    int addressLength;

    char budd[1024];
public:
};


#endif /*SERVER_H_*/