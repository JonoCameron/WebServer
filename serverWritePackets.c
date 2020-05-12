// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd, len, n; 
	char buffer[MAXLINE]; 
	char *hello = "Hello from server"; 
	struct sockaddr_in servaddr, cliaddr; 
    FILE *fd;
	
	// Creating socket file descriptor 
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){ 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
    fd = fopen("received_data/received_from_client.txt", "a");

    if(fd == NULL){
        printf("received_data/received_from_client.txt failed to open. Whoops! I won't be able to put data in there\n");
    }
    else{
        printf("The file is open to append to\n");
        len = sizeof(cliaddr); //len is value/result 
        
        for(int i = 0; i < 3; i++){
            printf("Waiting %d...\n", (i + 1));
            n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *)&cliaddr, &len); 
            buffer[n] = '\0'; 

            if(strlen(buffer) > 0){
                fputs(buffer, fd);
                fputs("\n", fd);
            }

            printf("Client : %s\n", buffer); 
            sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len); 
            printf("ACK sent.\n"); 
        }
        printf("Transmission receieved!!\n");

        fclose(fd);
        printf("Written to file and file is now closed\n");
	}

    return 0;
} 
