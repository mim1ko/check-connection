#ifndef CHECK_CONNECTION_H
#define CHECK_CONNECTION_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include <iostream>
#include <exception>

namespace connection{

    class check_connection{
        private:
        void check_connect( char* ip_address,  char* port_number);
        public:
        void operator()( char* ip_address,  char* port_number);
    };
}

#endif
