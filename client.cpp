#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <unistd.h>


int getPort() {

	int port;
	std::string input;

	std::cout << "Please choose Server Port:" << std::endl;
	std::cin >> input;

	try {
		port = std::stoi(input);
	}

	catch (const std::exception& e) {
		port = 0;
	}

	return port;
}


int connect(int port) {

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
	serv_addr.sin_port = htons(port);

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {

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


int main() {

	int port = getPort();
	connect(port);

	return 0;
}
