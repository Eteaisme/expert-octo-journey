#ifndef simpleSocket
#define simpleSocket

#include <sys/socket.h>
#include <netinet/in.h>

namespace HDE {
    class SimpleSocket{
        private:
            struct sockaddr_in address;
            int connection; 
        public:
            SimpleSocket(int domain, int service, int protocall, int port, u_long interface);
    };
}
#endif
