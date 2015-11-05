/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** SetRegistrationStartDateScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "SetRegistrationStartDateScreen.h"


SetRegistrationStartDateScreen::SetRegistrationStartDateScreen()
{

}

bool SetRegistrationStartDateScreen::verifyAndSetStartDate(int d, int m, int y)
{
	if (!(1 <= m && m <= 12))
		return false;
	if (!(1 <= d && d <= 31))
		return false;
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if ((d == 30) && (m == 2))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return true;
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return true;
}

void SetRegistrationStartDateScreen::show()
{
	int day, month, year;
	string fixDay, fixMonth;
	bool condition = true;
	do{
		lOGO
		cout << "Please enter date" << endl;
		cout << "Day :";
		while ((!(cin >> day) || day < 0)) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
		cout << "Month :";
		while ((!(cin >> month) || month < 0)) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
		cout << "Year :";
		while ((!(cin >> year) || year < 0)) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
		if (this->verifyAndSetStartDate(day, month, year)){
			//18102015
			
			if (day < 10){
				fixDay = "0" + static_cast<ostringstream*>(&(ostringstream() << day))->str();
			}
			else fixDay = static_cast<ostringstream*>(&(ostringstream() << day))->str();

			if (month < 10){
				fixMonth = "0" + static_cast<ostringstream*>(&(ostringstream() << month))->str();
			}
			else fixMonth = static_cast<ostringstream*>(&(ostringstream() << month))->str();


			this->startDate = fixDay + fixMonth + static_cast<ostringstream*>(&(ostringstream() << year))->str();
			FileStorage *fs = new FileStorage();
			RegistrationStartDate * registrationStartDate = new RegistrationStartDate(1, fs);
			registrationStartDate->setDate(this->startDate);
			registrationStartDate->save(false);
			condition = false;
			delete (registrationStartDate, fs);
		}
		else{
			cout << "Not valid date , try again" << endl;
			
		}
		CLEAN
	} while (condition);

}