#pragma once


#include <iostream>
#include <cstdint>	
#include <vector>
using namespace std;
#include "UIMainScreen.h"
#include "Course.h"
#include "Student.h"

#define LOCK true
#define UNLOCK false

class LockRegistrationScreen : public UIMainScreen
{
private:
	void initLoginCounter(int);
public:
	LockRegistrationScreen();
	void lockTerminal(bool);
	void show();

};