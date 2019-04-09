#include "controle.hh"
#include "server.hh"


int main(int argc, char *argv[]) {

	int port = controleArg(argc, argv);

	Server server(port);
	server.launch();

	return 0;

}
