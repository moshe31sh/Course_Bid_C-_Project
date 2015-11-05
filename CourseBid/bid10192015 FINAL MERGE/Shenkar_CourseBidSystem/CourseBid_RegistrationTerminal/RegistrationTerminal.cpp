/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** RegistrationTerminal.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "RegistrationTerminal.h"

void RegistrationTerminal::logOutUser()
{

}

void RegistrationTerminal::lockTerminal()
{

}

UIScreen& RegistrationTerminal::getScreen()
{

	return *this->currentScreen;
}

void RegistrationTerminal::pushLastScreen(UIScreen& screen)
{

}

UIScreen& RegistrationTerminal::popLastScreen()
{
	return *this->currentScreen;
}

void RegistrationTerminal::setCurrentScreen(UIScreen& screen)
{

}