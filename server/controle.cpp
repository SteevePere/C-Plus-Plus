#include "controle.hh"
#include "server.hh"
#include <vector>
#include <string>
#include<map>


void defaultParams() {

	cout << "\nServer loaded with default parameters:" << endl;
	cout << "\n--map-height -> \t 5" << endl;
	cout << "--map-width ->\t \t 5" << endl;
	cout << "--port -> \t \t 4242" << endl;
	cout << "--players -> \t \t 4" << endl;
	cout << "--cycle -> \t \t 500ms" << endl;

	return;

}


int getParam(string value) {

	int result = 0;

	try {
		result= stoi(value.substr(value.find("=") + 1)) ;
	}

	catch(exception) {
		result = 0;
	}

	return result;

}


auto extractParam(int argc, char *argv[]) {

	vector<string> v;
	vector<string> path;
	vector<int>::iterator it;

	//map to return arguments
	map<string, int> param;

	path.push_back("--map-height");
	path.push_back("--map-width");
	path.push_back("--port");
	path.push_back("--players");
	path.push_back("--cycle");

	if (argc == 1 ) {

		param["--map-height"] = 5;
		param["--map-width"] = 5;
		param["--port"] = 4242;
		param["--players"] = 4;
		param["--cycle"] = 500;
	}

	for (int i=0; i<argc; i++) {

		const string str = argv[i];

		v.push_back(argv[i]);

		if (str.find(path[0]) != string::npos) {

			if(getParam(str) == 0) {
				param["--map-height"] = 5;
				cout << "--map-height: \t Default value for map-height: 5" << endl;
			}

			else {
				cout << "--map-height: \t "<< getParam(str) << endl;
				param["--map-height"] = getParam(str);
			}

		}

		else if (str.find(path[1]) != string::npos) {

			getParam(str);

			if(getParam(str) == 0) {
				param["--map-width"] = 5;
				cout << "--map-width: \t Default value for map-width: 5" << endl;
			}

			else {
				cout << "--map-width: \t "<< getParam(str) << endl;
				param["--map-width"] = getParam(str);
			}

		}

		else if (str.find(path[2]) != string::npos) {

			getParam(str);

			if(getParam(str) == 0) {
				param["--port"] = 4242;
				cout << "--port: \t Default value for port : 4242" << endl;
			}

			else {
				cout << "--port: \t"<< getParam(str) << endl;
				param["--port"] = getParam(str);
			}

		}

		else if (str.find(path[3]) != string::npos) {

			getParam(str);

			if(getParam(str) == 0) {
				param["--players"] = 4;
				cout << "--players: \t Default value for players: 4" << endl;
			}

			else {
				param["--players"] = getParam(str);
				cout << "--players: \t"<< getParam(str) << endl;
			}

		}

		else if (str.find(path[4]) != string::npos) {

			getParam(str);

			if(getParam(str) == 0) {
				param["--cycle"] = 500;
				cout << "--cycle : \t Default value for cycle: 500" << endl;
			}

			else {
				param["--cycle"] = getParam(str);
				cout << "--cycle: \t"<< getParam(str) << endl;
			}
		}
	}

	return param;

}


int controleArg(int argc, char *argv[]) {

	if (argc <= 1 )
		defaultParams();

	auto param = extractParam(argc, argv);

	cout << "\nWaiting for connection..." << endl;

	int port = param["--port"];

	return port;

}
