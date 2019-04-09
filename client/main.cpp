#include <iostream>
#include<map>

#include "params.hh"
#include "client.hh"


int main(int argc, char* argv[]) {

	if (argc == 1 )
		displayDefaultParams();

	int port = getPort(argc, argv);
	const char* ip = getIp(argc, argv);

	Client client(ip, port);
	client.serverConnect();

	return 0;

}
