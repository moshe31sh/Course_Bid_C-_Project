#include "LockRegistrationScreen.h"


LockRegistrationScreen::LockRegistrationScreen()
{
}


void LockRegistrationScreen::lockTerminal(bool status)
{
	if (status == LOCK) this->initLoginCounter(3);
	if (status == UNLOCK) this->initLoginCounter(0);

}


void LockRegistrationScreen::initLoginCounter(int val){
	//ofstream counterData;
	//counterData.open("../counterAttempts.txt");
	//counterData << val;
	//counterData.close();
}


void LockRegistrationScreen::show(){

}