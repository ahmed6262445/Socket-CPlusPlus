#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int serverFd, newSocket, valRead;
    struct sockaddr_in address;
    int opt = 1;
    int addressLength = sizeof(address);
    char buffer[1024] = {0};
    char const *greetMessage = "Hello From Server";

    // Creating socket file desciptor
    serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == 0)
    {
        perror("Socket failed!");
        exit(EXIT_FAILURE);
    }

    // Forcefully attachingsocket to the port 8800
    int socketOption = setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if (socketOption)
    {
        perror("setsockopt error!");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //Forcefully attaching socket to the port 8080
    if (bind(serverFd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind Failed!");
        exit(EXIT_FAILURE);
    }

    int listening = listen(serverFd, 3);
    if (listen < 0)
    {
        perror("Listening Error");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        std::cout << "Server is running!\n";
        
        newSocket = accept(serverFd, (struct sockaddr *)&address, (socklen_t *)&addressLength);
        if (newSocket < 0)
        {
            perror("Accept Failure");
            exit(EXIT_FAILURE);
        }

        valRead = read(newSocket, buffer, 1024);
        std::cout << buffer << std::endl;
        send(newSocket, greetMessage, strlen(greetMessage), 0);
        std::cout << "Message Sent\n";
    }

    return 0;
}