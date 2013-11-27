#include "include/aszUtil.h"
#include <fstream>
#include <iostream>

using namespace std;

configFile::configFile(){
	
}

string configFile::getHomePage(){
	return m_config.empty() ? [&](){  getConfig(); return m_config.find("homeaddress")->second; }() :  m_config.find("homeaddress")->second;
}

void configFile::getConfig(void){
	string wkpath = getCurrentWorkingPath();

	string file =  wkpath + CONFIG_FILE;
	string line;
	ifstream myfile (file);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
		
			size_t indexofLine = line.find_first_of("*");

			string dd = line.substr(0,indexofLine);
			string ff = line.substr(indexofLine);

			m_config.insert( std::pair<string,string>(line.substr(0,indexofLine),line.substr(indexofLine+1)) );


		}
		myfile.close();
	}

	
	
}

const wchar_t *GetWC(const char *c)
{
	const size_t cSize = strlen(c)+1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs (wc, c, cSize);

	return wc;
}



std::string getCurrentWorkingPath(){

	char cCurrentPath[FILENAME_MAX];

	GetCurrentDir(cCurrentPath, sizeof(cCurrentPath));

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; 

	std::string wdName =std::string(cCurrentPath);

	return wdName;
}

