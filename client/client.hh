#ifndef CLIENT_HH
#define CLIENT_HH

class Client {

public:

	Client(const char* ip, int port);
	~Client();

public:

	int serverConnect() const;

private:

	const char* _ip;
	int _port;

};

#endif
