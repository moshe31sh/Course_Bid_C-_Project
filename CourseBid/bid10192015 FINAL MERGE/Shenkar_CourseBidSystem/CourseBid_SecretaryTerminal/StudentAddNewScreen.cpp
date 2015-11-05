/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** StudentAddNewScreen.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "StudentAddNewScreen.h"
#include "Parser.h"


/*
addStudentAndVerify.Verify if student is legal
*/
bool StudentAddNewScreen::addStudentAndVerify()
{
	FileStorage * fs = new FileStorage();
	vector<Student> students = Student::getAllStudents(fs);
	for each (Student student in students)
	{
		if (this->studentId == student.getId()) return true;

	}
	//delete fs;
	return false;
}

void StudentAddNewScreen::show()
{
	lOGO
		try{
		cout << "Please enter the following details" << endl;
		cout << "Please enter student id" << endl;
		while (!(cin >> this->studentId) || this->studentId < 0) // <<< note use of "short circuit" logical operation here
		{
			cout << "Bad input - try again: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
		}
		if (this->addStudentAndVerify() == false){
			FileStorage * fs = new FileStorage();
			Student * stu = new Student(studentId, fs, true);
			cout << "student name: ";
			string str;
			cin >> str;
			stu->setFirstName(str);
			cout << "student last name: ";
			cin >> str;
			stu->setLastName(str);
			cout << "student email: ";
			cin >> str;
			stu->setEmail(str);
			cout << "student password: ";
			cin >> str;
			stu->setPassword(str);

			stu->setLocked(false);

			stu->save(false);
			delete (stu,fs);
		}
		else {
			cout << "Student is already exist" << endl;

		}
		
	}
	catch (bad_alloc e){
		cerr << e.what() << endl;
	}
}