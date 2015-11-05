/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** InsertAssignitionFileScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "InsertAssignitionFileScreen.h"
#include "TechnitianAssignitionResultsScreen.h"
#include "AssignmentCalculator.h"
#include <fstream>

//insert the input file
void InsertAssignitionFileScreen::insertDistributionFile()
{
	ifstream file;
	string fileAsString;

	try {
		cout << "OPENING: " << fname << endl;
		file.open(fname);
		string temp;
		getline(file, fileAsString);

		while (getline(file, temp)) {
			fileAsString += "\n" + temp;
		}

		file.close();
		cout << "CLOSED: " << fname << endl;
	}
	catch (exception e)
	{
		cout << "Error opening file." << endl;
	}
	AssignmentCalculator assignmentCalculator(fileAsString, &result, _row, _col);
	getDistributionResults();
	cout << "insertDistributionFile" << endl;
}

void InsertAssignitionFileScreen::getDistributionResults()
{
	TechnitianAssignitionResultsScreen technitianAssignitionResultsScreen = TechnitianAssignitionResultsScreen(result, _row, _col);
	cout << "close getDistributionResults" << endl;
}

void InsertAssignitionFileScreen::show()
{
	cout << " The systemTest text file should be found in the shenkar Coursebid directory" << endl << endl;
	cout << "Press any key to continue" << endl;
	fflush(stdin);
	getchar();
	insertDistributionFile();
	cout << "closing show" << endl;
}