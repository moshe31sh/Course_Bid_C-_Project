/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CourseEventLog.h
** Class writes debug logs to file.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#ifndef DBEventLog_H
#define DBEventLog_H

#include <iostream>
using namespace std;
#include <fstream>
#include <ctime> 
#include <string>

#include "EventLog.h"

class DBEventLog : public EventLog
{
private:
	static string logfilename; //log file name
public:
	static void debug(string message, string category);
	static void info(string message, string category);
	static void warning(string message, string category);
	static void error(string message, string category);
};

#endif DBEventLog_H
