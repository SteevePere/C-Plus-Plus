#ifndef SERVER_HH
#define SERVER_HH

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>


class Server {

public:

	Server(int port);
	~Server();

public:

	int launch() const;

private:

	int _port;

};

#endif
