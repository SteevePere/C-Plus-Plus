#ifndef CONTROLE_HH
#define CONTROLE_HH

#include <iostream>
using namespace std;


class controle {

	public :
//	int _mapHeight;
//	int _mapWidth;
//	int _port;
//	int _players;
//	int _cycle;

	public:
/*		controle();
		~controle();
		int getMapHeight();
		void setMapHeight(int value = 0);
		int getMapWidth();
		void setMapWidthint(int value = 0);
		int getPort();
		void setPort(int value = 0);
		int getPlayer();
		void setPlayer(int value = 0);
		int getCycle();
		void setCycle(int value = 0);*/
};

int controleArg(int argc, char *argv[]);
void defaultParams();
int getParam(string value);
auto extractParam(int argc, char *argv[]);


#endif
