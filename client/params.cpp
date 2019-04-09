#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include<map>

#include "params.hh"


void displayDefaultParams() {

	std::cout << "\nTrying to connect to Server with default parameters:" << std::endl;
	std::cout << "\n--ip -> \t 127.0.0.1" << std::endl;
	std::cout << "--port ->\t 4242\n" << std::endl;

	return;

}


int getIntParam(std::string value) {

	int result = 0;

	try {
		result= stoi(value.substr(value.find("=") + 1)) ;
	}

	catch(std::exception) {
		result = 0;
	}

	return result;

}


int getPort(int argc, char *argv[]) {

	int port;

	if (argc == 1 )
		port = 4242;

	for (int i = 0; i < argc; i++) {

		const std::string str = argv[i];

 		if (str.find("--port") != std::string::npos) {

			getIntParam(str);

			if (getIntParam(str) == 0) {

				port = 4242;
				std::cout << "--port: \t Default value for port : 4242" << std::endl;
			}

			else {

				std::cout << "--port: \t"<< getIntParam(str) << std::endl;
				port = getIntParam(str);
			}
		}
	}

	return port;

}


const char* getIp(int argc, char *argv[]) {

	const char* ip;

	if (argc == 1 || argc == 2)
		return "127.0.0.1";

	ip = argv[1];

  	const char* to;
  	to=strndup(ip+5, 9);

	std::cout << "--ip: \t\t"<< to << std::endl;

	return to;

}
