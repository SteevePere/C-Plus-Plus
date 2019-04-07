#include "controle.hh"
#include <vector>
#include <string>

void nbParametre(){

		cout << "loaded with default param :" << endl;
		cout << "--map-height -> \t 5" << endl;
		cout << "--map-width ->\t 5" << endl;
		cout << "--port -> \t 4242" << endl;
		cout << "--players -> \t 4" << endl;
		cout << "--cycle -> \t 500ms" << endl;
	return;
}

int getParam(string value)
{
		int result = 0;

	try {

		result= stoi(value.substr(value.find("=") + 1)) ;
	}
	catch(exception){
		result = 0;
	}
		return result;
}

void extractParam(int argc, char *argv[]) {
	vector<string> v;
	vector<string> path;
	vector<int>::iterator it;

	path.push_back("--map-height");
	path.push_back("--map-width");
	path.push_back("--port");
	path.push_back("--players");
	path.push_back("--cycle");

	for (int i=0; i<argc; i++)
    {
	const string str = argv[i];
	v.push_back(argv[i]);
			if (str.find(path[0]) != string::npos) {
				if(getParam(str) == 0) {
					cout << "--map-height : \t default value for map-height" << endl;
				}
			else {
					cout << "--map-height"<< getParam(str) << endl;
			}

			}
			else if (str.find(path[1]) != string::npos) {
				getParam(str);
				if(getParam(str) == 0) {
					cout << "--map-width : \t default value for map-width" << endl;
				}else {
					cout << "--map-width : \t "<< getParam(str) << endl;
				}

			}
			else if (str.find(path[2]) != string::npos) {
				getParam(str);
				if(getParam(str) == 0) {
					cout << "--port : \t default value for port" << endl;
				} else {
					cout << "--port : \t"<< getParam(str) << endl;
				}

			}
			else if (str.find(path[3]) != string::npos) {
				getParam(str);
				if(getParam(str) == 0) {
					cout << "--player : \t default value for player" << endl;
				}else {
					cout << "--player : \t"<< getParam(str) << endl;
				}

			}
			else if (str.find(path[4]) != string::npos) {
				getParam(str);
				if(getParam(str) == 0) {
					cout << "cycle : \t default value for cycle" << endl;
				}else {
				cout << "cycle : \t"<< getParam(str) << endl;
				}

			}
			/*else {
				nbParametre(argc);
				return;
			}*/

    }

//	for (auto it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}

}


void controleArg(int argc, char *argv[]) {
	cout << "Option :" << argc << endl;
	if (argc < 1 )
		nbParametre();
	extractParam(argc, argv);
}



/*int main(int argc, char *argv[])
{
	controleArg(argc,argv);
	return 0;
}
*/
