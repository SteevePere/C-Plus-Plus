#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

#include "client.hh"


Client::Client(const char* ip, int port): _ip(ip), _port(port) {

}


Client::~Client() {

}


int Client::serverConnect() const {

	int sock = 0;
	struct sockaddr_in serv_addr;
	char const* connected = "Connection to Server was successful";
	char buffer[1024] = {0};

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

		printf("\nSocket creation error\n");
		return -1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(_port);

	if(inet_pton(AF_INET, _ip, &serv_addr.sin_addr)<=0) {

		printf("\nInvalid address / Address not supported\n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {

		printf("\nConnection to Server failed\n");
		return -1;
	}

	send(sock, connected, strlen(connected), 0);

	read(sock, buffer, 1024);
	printf("%s\n", buffer);

	return 0;

}
