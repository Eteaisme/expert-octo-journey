#include "simpleSocket.h" 
#include <netinet/in.h>
#include <sys/socket.h>

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){

    //Define address structure
    address.sin_family = domain; 
    address.sin_port = htons(port); 
    address.sin_addr.s_addr = htonl(interface);

    //Establish connection
    connection = socket(domain, service, protocol);
}
