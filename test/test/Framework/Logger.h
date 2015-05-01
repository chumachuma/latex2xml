// Logger.h
#pragma once
#ifndef LOGGER_IMPROVED
#define LOGGER_IMPROVED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <mutex> !!

#include "SingletonDestroyer.h"

#define logD(x_str) Logger::instance().log(DEBUG,  x_str)
#define logI(x_str) Logger::instance().log(INFO,  x_str)
#define logW(x_str) Logger::instance().log(WARNING,  x_str)
#define logE(x_str) Logger::instance().log(ERROR,  x_str)
#define logC(x_str) Logger::instance().log(CRITICAL,  x_str)
#define log0(x_str, y_str) Logger::instance().log(x_str,  y_str)

 enum LogLevel{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL,
	CUSTOM,
	TERMINAL,
};


class Outputer {
public:
	Outputer() {};
	virtual ~Outputer (void) {};
	virtual void write (const std::string&)=0;
};


class Logger {
// Definition of a safe singleton logger class
public:
	static Logger& instance();
	// Returns a reference to the singleton Logger object

	void log(LogLevel inputLogLevel,
		const std::string& inputMessage);
	void log(const std::string& Header,
		std::string inputMessage);
		// Logs a single message at the given log level
		// Custom header can only be added in CUSTOM level

protected:
	std::vector <std::string> logLevelHeader;
	// Output header of each log level

	std::vector <std::string> logLevelFilename;
	// Filenames of each log level

	std::vector <Outputer*> outputStream;
	void initializeOutputStream ();
	void deleteOutputStream ();
	// Collect all output streams in a vector

	static Logger* loggerInstance;
	// Static variable for the one-and-only instance

	friend class SingletonDestroyer <Logger>;
	static SingletonDestroyer <Logger> singletonDestroyer;
	// Embedded class to make sure the single Logger instance gets deleted on program shutdown

	void createLogsDirectory (const char*  directoryPath);
	// Create directory if it does not already exists

	std::string formatHeader (const std::string& Header);
	// Header is cut to be no longer than 8 char (CRITICAL) !! hardcoded
	std::string formatMessage (const std::string& Message);
	// Messages are indented 10 char (CRITICAL: ) !! hardcoded

private:
	Logger();
	virtual ~Logger();
	Logger(const Logger&);
	Logger& operator=(const Logger&);
	//static std::mutex sMutex; !!
};


class fileOutput:public Outputer {
public:
	std::string fileName;
	std::ofstream outputStream;
	fileOutput (std::string);
	virtual ~fileOutput (void);
	void write (const std::string&);
};


class terminalOutput:public Outputer {
public:
	void write (const std::string&);
};

#endif