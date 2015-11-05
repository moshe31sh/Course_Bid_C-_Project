/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** User.h
** User abstract class for all kind of users.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/

#include "User.h"
//NOTE: USER IS ABSTRACT CLASS

const string User::TAG_USERID = string("userId");
const string User::TAG_FIRSTNAME = string("firstName");
const string User::TAG_LASTNAME = string("lastName");
const string User::TAG_EMAIL = string("email");
const string User::TAG_PASSWORD = string("password");
const string User::TAG_ISLOCKED = string("isLocked");