#include "StudentRemoveAssignedCourseScreen.h"




StudentRemoveAssignedCourseScreen::StudentRemoveAssignedCourseScreen(Student* stud, Course* course) : student(stud), courseToRemove(course)
{
	cout << "StudentRemoveCompletedScreen() called" << endl;
}

/*
removeAssignedCourse. clear assign course vector
*/
bool StudentRemoveAssignedCourseScreen::removeAssignedCourse()
{
	this->student->removeAssignedCourse(this->courseToRemove);
	char answer;
	cout << "\nDo you save changes? y/n" << endl;
	fflush(stdin);
	answer = getchar();
	if (answer == 'y'){
		this->student->save(false);

		cout << "Change successfully saved" << endl;
	}
	else{
		cout << "Action canceled" << endl;
	}
	return true;
}

void StudentRemoveAssignedCourseScreen::show()
{

}