/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** EventLog.h
** Class writes debug logs to file.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <iostream>
using namespace std;
#include <fstream>
#include <ctime> 
#include <string>

class EventLog 
{
public:


	static string logfilename; //log file name
	static void debug(string message, string category);
	static void info(string message, string category);
	static void warning(string message, string category);
	static void error(string message, string category);
	static string getTime()
	{
		time_t t = time(0);   // get time now
		struct tm now;
		localtime_s(&now, &t);
		return to_string(now.tm_hour) + ":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
	}
};

#endif EVENTLOG_H