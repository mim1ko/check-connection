#include "check_connection.h"

void connection::check_connection::check_connect( char* ip_address,  char* port_number){
    addrinfo hints, *res;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; 

    int status = getaddrinfo(ip_address, port_number, &hints, &res);
    if (status != 0) {
        //std::cerr << "getaddrinfo: " << gai_strerror(status) << std::endl;
        throw std::invalid_argument{"Cannot resolve hostname"};
    }
    
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        freeaddrinfo(res);
        throw std::invalid_argument{"Cannot create socket"};
    }
    
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        close(sockfd);
        freeaddrinfo(res);
        throw std::invalid_argument{"Cannot connect to host"};
    }
    
    std::cout << "Connected successfully to " << ip_address << " on port " << port_number << std::endl;
    
    close(sockfd);
    freeaddrinfo(res);
}

void connection::check_connection::operator()( char* ip_address,  char* port_number){
    connection::check_connection::check_connect(ip_address, port_number);
}
