#ifndef PARAMS_HH
#define PARAMS_HH

#include <iostream>

void displayDefaultParams();
int getIntParam(std::string value);
int getPort(int argc, char *argv[]);
const char* getIp(int argc, char *argv[]);

#endif
