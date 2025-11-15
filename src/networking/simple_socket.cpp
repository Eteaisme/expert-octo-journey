#include "simple_socket.h" 
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>

// --- Defualt Constructor ---
HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){
    address.sin_family = domain; 
    address.sin_port = htons(port); 
    address.sin_addr.s_addr = htonl(interface);

    sock = socket(domain, service, protocol);

    test_connection(sock); 
    test_connection(connection); 

    connection = connect_to_network(sock, address); 
     
}

// --- test_connection virtual function --- 
void HDE::SimpleSocket::test_connection(int item_to_test){
    if( item_to_test < 0 ){
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}
struct sockaddr_in HDE::SimpleSocket::get_address(){
    return address; 
}


int HDE::SimpleSocket::get_sock(){
    return sock; 
}


int HDE::SimpleSocket::get_connection(){
    return connection; 
}
