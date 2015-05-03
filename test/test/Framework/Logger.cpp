// Logger.cpp
// Implementation of a multithread safe singleton logger class
#include "stdafx.h"

#include <stdexcept>
#include <direct.h>
#include "Logger.h"

using namespace std;

Logger* Logger::loggerInstance = 0;
SingletonDestroyer <Logger> Logger::singletonDestroyer; 

//mutex Logger::sMutex; !!

Logger& Logger::instance()
{
	//lock_guard<mutex> guard(sMutex); !!
	if (loggerInstance == nullptr)
		loggerInstance = new Logger();
		singletonDestroyer.SetSingletonInstance(loggerInstance);
	return *loggerInstance;
}

Logger::~Logger()
{
	deleteOutputStream();
}

Logger::Logger()
{
	logLevelHeader.push_back("DEBUG:    ");
	logLevelHeader.push_back("INFO:     ");
	logLevelHeader.push_back("WARNING:  ");
	logLevelHeader.push_back("ERROR:    ");
	logLevelHeader.push_back("CRITICAL: ");
	
	logLevelFilename.push_back("dbg.log");
	logLevelFilename.push_back("info.log");
	logLevelFilename.push_back("warn.log");
	logLevelFilename.push_back("err.log");
	logLevelFilename.push_back("crit.log");
	logLevelFilename.push_back("log.txt");

	createLogsDirectory(".\\logs");

	initializeOutputStream();
}

void Logger::log(LogLevel inputLogLevel, const string& inputMessage)
{
	//lock_guard<mutex> guard(sMutex); !!
	string formatedMessage = logLevelHeader.at(inputLogLevel) + formatMessage(inputMessage);
	outputStream.at(inputLogLevel)->write(formatedMessage);
	outputStream.at(CUSTOM)->write(formatedMessage);
	outputStream.at(TERMINAL)->write(formatedMessage);
}

void Logger::log(const string& Header, string inputMessage)
{
	string formatedMessage = formatHeader(Header) + formatMessage(inputMessage);
	outputStream.at(CUSTOM)->write(formatedMessage);
	outputStream.at(TERMINAL)->write(formatedMessage);
}

string Logger::formatHeader (const std::string& Header)
{
	unsigned int maxHeaderLength = 8;
	if (Header.length() > maxHeaderLength)
		return Header.substr(0, maxHeaderLength) + ": ";

	unsigned int extraSpaces = maxHeaderLength - Header.length();
	string spaces = "";
	for (unsigned int i=0; i<=extraSpaces; i++)
		spaces += " ";
	return Header.substr(0, maxHeaderLength) + ":" + spaces;
}

string Logger::formatMessage (const std::string& Message)
{
	string newMessage = "";
	for (unsigned int i=0; i<Message.length(); i++){
		if (Message[i] == '\n')	{
			newMessage += Message[i] + "          ";
		}
		else if (Message[i] == '\r') { //Windows newline
			if (Message[i+1] == '\n')
				newMessage += "\r\n          ";
			i += 2;
		}
		else {
			newMessage += Message[i];
		}
	}
	return newMessage;
}

void Logger::createLogsDirectory (const char* directoryPath)
{
	_mkdir(directoryPath);
}

void Logger::initializeOutputStream ()
{
	for (int level=0; level<=CUSTOM; level++) {
		outputStream.push_back( new fileOutput(logLevelFilename.at(level)) );
	}
	outputStream.push_back( new terminalOutput() );
}

void Logger::deleteOutputStream (){
	for (std::vector<Outputer*>::iterator iter = outputStream.begin() ; iter != outputStream.end(); ++iter) {
		delete (*iter);
	} 
	outputStream.clear();
}
	

// Outputer

fileOutput::fileOutput (string fileName):fileName(fileName){
	outputStream.open(".\\logs\\" + fileName, ios::trunc);
	if (!outputStream.good()) {
		throw runtime_error("Unable to initialize the Logger!");
	}
}

fileOutput::~fileOutput ()
{
	write("file closed");
	outputStream.close();
}

void fileOutput::write (const string& message){
	outputStream << message << endl;
}

void terminalOutput::write (const std::string& message){
	print (message);
}