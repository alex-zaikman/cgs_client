#ifndef aszUtil_h_3123432432425365345426t53652424
#define aszUtil_h_3123432432425365345426t53652424

#define SESSION_DIR "\\cef_session\\cache"
#define CONFIG_FILE "\\config.asz"
#define GetCurrentDir _getcwd
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <map>



class configFile{

public:

	configFile(void);

	std::string getHomePage(void);


private:
	void getConfig(void);

	std::map<std::string,std::string> m_config;
};


const wchar_t *GetWC(const char *c);

std::string getCurrentWorkingPath();



#endif //aszUtil_h_3123432432425365345426t53652424