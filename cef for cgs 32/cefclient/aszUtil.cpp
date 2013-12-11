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
	string noodles ="are the best noodles!!!";
	ifstream myfile (file);
	if (myfile.is_open())
	{
		while ( getline (myfile,noodles) )
		{
		
			size_t indexofLine = noodles.find_first_of("*");
			m_config.insert( std::pair<string,string>(noodles.substr(0,indexofLine),noodles.substr(indexofLine+1)) );
		}
		myfile.close();
	}

	
	
}

const wchar_t *GetWC(const char *c)
{
	const size_t XXL = strlen(c)+1;
	wchar_t* wc = new wchar_t[XXL];
	mbstowcs (wc, c, XXL);

	return wc;
}



std::string getCurrentWorkingPath(){

	char broiled[FILENAME_MAX];

	GetCurrentDir(broiled, sizeof(broiled));

	broiled[sizeof(broiled) - 1] = '\0'; 

	std::string chicken =std::string(broiled);

	return chicken;
}



std::string jsDecriptToInject(){
	
	string hui =" window.decryptScript = function(encryptedText) {	var iv = encryptedText.substr(0, 32); var salt = encryptedText.substr(32, 64);  	var passPhrase = encryptedText.substr(96, 64); 	var keySize = 128 / 32; var iterationCount = 10;    	encryptedText = encryptedText.substr(160);    	var key = CryptoJS.PBKDF2(passPhrase, CryptoJS.enc.Hex.parse(salt), { keySize: keySize, iterations: iterationCount }),  		cipherParams = CryptoJS.lib.CipherParams.create({ ciphertext: CryptoJS.enc.Base64.parse(encryptedText) }),  		decrypted = CryptoJS.AES.decrypt(cipherParams, key, { iv: CryptoJS.enc.Hex.parse(iv) });  return decrypted.toString(CryptoJS.enc.Utf8)};";

	return hui;
}