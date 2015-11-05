/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** TechnitianAssignitionResultsScreen.cpp
** <very brief file description>
**
** Author: ohad sasson
** -------------------------------------------------------------------------*/
#include "TechnitianAssignitionResultsScreen.h"
#include "TechnicianMainScreen.h"
#include <fstream>

//Ctor pass the arguments for the test
TechnitianAssignitionResultsScreen::TechnitianAssignitionResultsScreen(int** result, int row, int col) {
	_row = row;
	_col = col;
	this->result = result;
	if (getResultFile()) {//if true
		cout << "Test finished successfuly without errors" << endl;
	}
	else {
		cout << "Test failed" << endl;

	}
	cout << "Closing TARS"<<endl;
}

bool TechnitianAssignitionResultsScreen::getResultFile()
{
	cout << "Press any key to continue" << endl;
	fflush(stdin);
	getchar();

	string solutionStr, fileAsString;
	ifstream file;
	try { 
		cout << "OPENING:" << checkFile << endl;
		//_sleep(4000);
		file.open(checkFile);
		string temp;
		while (getline(file, temp)) {
			fileAsString += temp + "\n";
		}
		file.close();
		cout << "CLOSED:" << checkFile << endl;
	}
	catch (exception& e)
	{
		cout << "Error opening file." << endl;
	}
	// make the result to string
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			solutionStr += std::to_string(result[i][j]);
			if (j < _col - 1)
				solutionStr += ' ';
		}
		solutionStr += '\n';
	}
	return solutionStr == fileAsString; // is the test file and the checkfile are identical
}

void TechnitianAssignitionResultsScreen::show()
{
	TechnitianAssignitionResultsScreen(result, _row, _col);
}

