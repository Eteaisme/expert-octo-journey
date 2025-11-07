#ifndef simpleSocket
#define simpleSocket

#include <sys/socket.h>
#include <netinet/in.h>
#include<iostream>

namespace HDE {
    class SimpleSocket{

        private:
            struct sockaddr_in address;
            int sock {}; 
            int connection {}; 

        public:
            // --- Constructor --- 
            SimpleSocket(int domain, int service, int protocall, int port, u_long interface);

            // --- Virtual function ---
            virtual int connect_to_network(int socket, struct sockaddr_in address) = 0;
            void test_connection(int);

            // --- Getter functions --- 
            struct sockaddr_in get_address(); 
            int get_sock();
            int get_connection();
    };
}
#endif
