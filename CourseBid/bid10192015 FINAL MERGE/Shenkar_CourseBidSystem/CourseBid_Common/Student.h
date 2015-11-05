/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** Student.h
** Student class.
**
** Author: Yossi Gleyzer,
** -------------------------------------------------------------------------*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstdint>	
using namespace std;
#include <vector>
#include <string>
#include <sstream>

#include "User.h"
#include "Course.h"
#include "StudentEventLog.h"

class Course;
class Student :public User {
private:
	//static serial number for all objects Student
	static const int SERIAL = 2; 
	vector<Course*> completedCourses;
	vector<Course*> assignedCourses;
	vector<Course*> desiredCourses;
	vector<int> desiredPoints;
	int points;
public:
	/*
	** Public static storage tags
	*/
	static const string TAG_COMPLETEDCOURSES;
	static const string TAG_ASSIGNEDCOURSES;
	static const string TAG_DESIREDCOURSES;
	static const string TAG_DESIREDPOINTS;
	static const string TAG_POINTS;

	/*
	** Student constructor.
	*/
	Student(long id, IStorage * storage) : User(id, storage) { }

	/*
	** Student constructor.
	** dummy value is used to define additional constructor with same call
	*/ 
	Student(long userId, IStorage *storage, bool dummy) :User(storage->generateId(this->SERIAL), storage) 
	{
		this->userId = userId;
	}
	
	/*
	** Constructor. Create Student from given string.
	** NOTE: In case of circular precourse dependencies this might cause STACK OVERFLOW!!!
	*/
	Student(string studentAsString, IStorage * storage);
	
	/*
	** Static Method - Returns a vector of all students.
	*/
	static vector<Student> getAllStudents(IStorage * storage);
	
	/*
	** inline get/set methods
	*/
	vector<Course*> getDesiredCourses()							{ return desiredCourses;	}
	vector<Course*> getCompletedCourses()						{ return completedCourses;	}
	vector<Course*> getAssignedCourse()							{ return assignedCourses;	}
	void setPoints(int points)									{ this->points = points;	}
	int getPoints()												{ return points;	}

	/*(Storage override)
	** Creates record and saves to DB using IStorage from base IdObj. If recursive saves inner objects.
	*/
	virtual void save(bool recursive);

	/*(Storage override)
	** Delete record and save DB using IStorage from base IdObj.
	*/
	virtual void deleteMe();

	/* Static Method
	** This function returns a student by object id.
	** If not found student with given id - throws an exception.
	*/
	static Student getStudentById(IStorage * storage, int id);

	/* Static Method
	** This function returns a student by student id.
	** If not found - returns NULL.
	*/
	static Student* getStudentByStudentId(IStorage * storage, int userId);

	/*
	** Converts a Student to String.
	** Used for Debug purposes only!
	*/
	string ToString();



	//TODO:
	bool addDesiredCourse(Course* course, int points);
	bool addDesiredCourse(long courseId, int points);
	bool addAssignedCourse(Course* course);
	bool addAssignedCourse(long courseId);
	bool addCompletedCourse(Course* course);
	bool addCompletedCourse(long courseId);
	bool removeDesiredCourse(Course* course);
	bool removeDesiredCourse(long courseId);
	bool removeAssignedCourse(Course* course);
	bool removeAssignedCourse(long courseId);
	bool removeCompletedCourse(Course* course);
	bool removeCompletedCourse(long courseId);
	vector<int> getDesiredPoints();
	/*int getDesiredPoints(int index);
	bool addDesiredPoints(int points);
	bool removeDesiredPoints(int index);
	bool removeAllDesiredPoints();*/
	bool removeAllDesiredCourseAndPoints();
	int getDesiredPointsToCourse(int course_id);
	vector<Course*> getCourseListForStudentById(long userId);
};

#endif STUDENT_H