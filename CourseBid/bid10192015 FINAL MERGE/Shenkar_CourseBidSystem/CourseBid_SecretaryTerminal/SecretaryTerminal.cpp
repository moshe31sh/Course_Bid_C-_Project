/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** SecretaryTerminal.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "SecretaryTerminal.h"

SecretaryTerminal::SecretaryTerminal()
{
	
}

UIScreen& SecretaryTerminal::getScreen()
{
	return *currentScreen;
}

void SecretaryTerminal::pushLastScreen(UIScreen& screen)
{

}

UIScreen& SecretaryTerminal::popLastScreen()
{
	return *currentScreen;
}

void SecretaryTerminal::setCurrentScreen(UIScreen& screen)
{

}

bool SecretaryTerminal::releaseTerminals()
{
	return false;
}