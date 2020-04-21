#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include<iostream>
#define PORT 8080 

int main(int argc, char const *argv[])
{
    int sock = 0 , valRead;
    struct sockaddr_in serverAddress;
    char const *greetMessage = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("Socker creation error!");
        return -1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <=0)
    {
        perror("Invalide address");
        return -1;
    }

    if( connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Connection failed");
        return -1;
    }

    send(sock, greetMessage, strlen(greetMessage), 0);
    std::cout << "Sent\n";

    valRead = read(sock, buffer, 1024);
    std::cout << buffer;
    return 0;
}