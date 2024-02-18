#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>

#define SOCKET_NAME "DemoSocket"

#define BUFFER_SIZE 128

int main(int argc, char *argv[])
{
    struct sockaddr_un name;

#if 0
    struct sockaddr_un{
        sa_family_t sun_family;          /* AF_UNIX */
        char sun_path[108];             /* pathname */
    }
    
#endif

    int ret;
    int connectionSocket;
    int dataSocket;
    int data;
    int result;
    char buffer[BUFFER_SIZE];
    
    unlink(SOCKET_NAME);
    
    connectionSocket=socket(AF_UNIX,SOCK_STREAM,0);
    
    if(connectionSocket == -1)
    {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }
    
    printf("Socket created successfully\n");
    
    memset(&name,0,sizeof(struct sockaddr_un));
    
    name.sun_family=AF_UNIX;
    strncpy(name.sun_path,SOCKET_NAME, sizeof (name.sun_path) -1);
    
    ret= bind(connectionSocket,(const struct sockaddr_un *) &name,sizeof(struct sockaddr_un));
    
    if(ret == -1){
        perror("bind");
        exit(EXIT_FAILURE);
    }
    printf("bind() call succeed...\n");
    
    ret=listen(connectionSocket,20);
    if (ret == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    for(;;)
    {
        printf("Waiting on accept() system call...\n");
        dataSocket=accept(connectionSocket, NULL, NULL);
        if (dataSocket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection accepted from client\n");

        result = 0;
        
        for(;;){
            memset(buffer,0,BUFFER_SIZE);
            
            printf("Waiting for data from the client\n");
            
            ret = read(dataSocket, buffer, BUFFER_SIZE);
            
             if (ret == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            
            memcpy(&data, buffer, sizeof(int));
            if(data == 0) break;
            result += data;
        }
        memset(buffer,0,BUFFER_SIZE);
        
        printf("Sending data to client..\n");
        ret=write(dataSocket,buffer,BUFFER_SIZE);
        if(ret == -1)
        {
         perror("Write");
         exit(EXIT_FAILURE);
        }
        close(dataSocket);
    }
    close(connectionSocket);
     printf("connection closed..\n");
     unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);
}



