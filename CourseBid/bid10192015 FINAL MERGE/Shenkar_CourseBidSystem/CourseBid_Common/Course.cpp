/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** Course.cpp
** Course Class implementation.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "Course.h"
#include "CircleDetection.h"

/*
** Storage tags consts.
*/
const string Course::TAG_COURSE_ID = "courseId";
const string Course::TAG_NAME = "name";
const string Course::TAG_DESCRIPTION = "description";
const string Course::TAG_TEACHING_HOURS = "teachingHours";
const string Course::TAG_MAX_STUDENTS = "maxStudents";
const string Course::TAG_PREREQUISITE_COURSES = "prerequisiteCourses";

/*
Constructor. Create Course from given string.
NOTE: In case of circular precourse dependencies this might cause STACK OVERFLOW!!!
*/
Course::Course(string courseAsString, IStorage * storage) : IdObj(0, storage)
{
	string logCat = "Course";
	long serialS = storage->getNumberFromStringByTag(courseAsString, storage->TAG_SERIAL);
	if (serialS != this->SERIAL)
	{
		CourseEventLog::error("Wrong serial for course. Received [" + to_string(serialS) + "] while must be [" + to_string(SERIAL) + "].", logCat);
		throw new exception(); //wrong serial
	}
	this->id = storage->getNumberFromStringByTag(courseAsString, storage->TAG_ID);
	this->courseId = storage->getNumberFromStringByTag(courseAsString, TAG_COURSE_ID);
	this->name = storage->getStringFromStringByTag(courseAsString, TAG_NAME);
	this->description = storage->getStringFromStringByTag(courseAsString, TAG_DESCRIPTION);
	this->teachingHours = storage->getStringFromStringByTag(courseAsString, TAG_TEACHING_HOURS);
	this->maxStudents = static_cast<int>(storage->getNumberFromStringByTag(courseAsString, TAG_MAX_STUDENTS));
	CourseEventLog::debug("Initialized course [" + to_string(id) + "] [" + name + "].", logCat);
	vector<long> preCourseIds = storage->getInnerNumbersByTag(courseAsString, TAG_PREREQUISITE_COURSES);
	for each (long id in preCourseIds)
	{
		CourseEventLog::debug("\tSubcourse [" + to_string(id) + "] initialization:", logCat);
		prerequisiteCourses.push_back(Course::getCourseById(storage, id));
	}
}

/*
** Static Method - Returns a vector of all courses.
*/
vector<Course> Course::getAllCourses(IStorage * storage)
{
	string logCat = "getAll";
	CourseEventLog::debug("Getting list of all courses from DB.", logCat);
	vector<Course> allCourses;
	vector<string> coursesAsString = storage->getAll(Course::SERIAL);
	for each (string courseAsString in coursesAsString)
	{
		Course * course = new Course(courseAsString, storage);
		CourseEventLog::debug("\tReceived course [" + to_string(course->getId()) + "] [" + course->getName() + "] from DB.", logCat);
		allCourses.push_back(*course);
	}
	CourseEventLog::debug("Finished getting list of all courses from DB.", logCat);
	return allCourses;
}

/*
Creates record and saves to DB using IStorage from base IdObj. If recursive saves inner objects.
*/
void Course::save(bool recursive)
{
	//create the record
	string logCat = "save";
	CourseEventLog::debug("Creating course record to save in DB for [" + to_string(id) + "] [" + name + "].", logCat);
	string record = string("<" + storage->TAG_OBJ + ">");
	record += string("<" + storage->TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
	record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
	record += string("<" + TAG_COURSE_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << courseId))->str() + "\">");
	record += string("<" + TAG_NAME + "=\"" + name + "\">");
	record += string("<" + TAG_DESCRIPTION + "=\"" + description + "\">");
	record += string("<" + TAG_TEACHING_HOURS + "=\"" + teachingHours + "\">");
	record += string("<" + TAG_MAX_STUDENTS + "=\"" + static_cast<ostringstream*>(&(ostringstream() << maxStudents))->str() + "\">");
	record += string("<" + TAG_PREREQUISITE_COURSES + ">");
	for each (Course course in prerequisiteCourses)
	{
		record += string("<" + storage->TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << course.getId()))->str() + "\">");
	}
	record += string("<\\" + TAG_PREREQUISITE_COURSES + ">");
	record += string("<\\" + storage->TAG_OBJ + ">");

	//save record to db
	CourseEventLog::debug("Saving course record to save in DB for [" + to_string(id) + "] [" + name + "].", logCat);
	storage->save(record);

	//save prerequisite courses
	if (recursive)
	{
		CourseEventLog::debug("Saving prerequisite courses - recursive call to [save].", logCat);
		for each (Course course in prerequisiteCourses)
		{
			course.save(recursive);
		}
	}
	CourseEventLog::debug("Finished saving courses to DB.", logCat);
}

/* Override parent
** Delete this course from DB. NOTE: Object still exists.
** NOTE: Before using this function you must verify no one is using this course in other prerequisite courses.
**		Otherwise it will delete a prerequisite course - this will cause an error in next courses.
*/
void Course::deleteMe()
{
	string logCat = "delete";
	CourseEventLog::debug("Deleting course from DB by id [" + to_string(id) + "].", logCat);
	storage->deleteObj(this->SERIAL, this->id);
	storage->save();
	CourseEventLog::debug("Course deleted. Changes saved to DB", logCat);
}

/* Static Method
** This function returns a course by object id.
** If not found course with given id - throws an exception.
*/
Course Course::getCourseById(IStorage * storage, long id)
{
	string logCat = "getById";
	CourseEventLog::debug("Trying to get course by id [" + to_string(id) + "].", logCat);
	vector<Course> allCourses;
	vector<string> coursesAsString = storage->getAll(SERIAL);
	for each (string courseAsString in coursesAsString)
	{
		if (id == storage->getNumberFromStringByTag(courseAsString, storage->TAG_ID))
		{
			Course * c = new Course(courseAsString, storage);
			CourseEventLog::debug("Course received by id: [" + to_string(id) + "].", logCat);
			return *c;
		}
	}
	CourseEventLog::error("No course found by id: [" + to_string(id) + "].", logCat);
	throw new exception(); //no couse found;
}

/* Static Method
** This function returns a course by course id.
** If not found - returns NULL.
*/
Course * Course::getCourseByCourseId(IStorage * storage, long courseId)
{
	string logCat = "getByCourseId";
	CourseEventLog::debug("Trying to get course by course id [" + to_string(courseId) + "].", logCat);
	vector<Course> allCourses;
	vector<string> coursesAsString = storage->getAll(SERIAL);
	for each (string courseAsString in coursesAsString)
	{
		if (courseId == storage->getNumberFromStringByTag(courseAsString, TAG_COURSE_ID))
		{
			Course * c = new Course(courseAsString, storage);
			CourseEventLog::debug("Course received by course id: [" + to_string(courseId) + "].", logCat);
			return c;
		}
	}
	CourseEventLog::error("No course found by course id: [" + to_string(courseId) + "].", logCat);
	return NULL;
}

/*
** Converts a Course to String.
** Used for Debug purposes only!
*/
string Course::ToString()
{
	string course("Course: [objId:" + to_string(this->id));
	course += " serial: " + to_string(this->SERIAL);
	course += " courseId: " + to_string(this->courseId);
	course += " name: " + this->name;
	course += " description: " + this->description;
	course += " teachingHours: " + this->teachingHours;
	course += " maxStudents: " + to_string(this->maxStudents);
	course += " pre course ids: <";
	for each (Course c in prerequisiteCourses)
	{
		course += " id: " + to_string(c.getCourseId());
	}
	course += ">]";
	return course;
}


bool Course::setPrerequisiteCourse(Course course)
{
	return setPrerequisiteCourse(course.courseId);
}

bool Course::setPrerequisiteCourse(long attach_course_id) {
	FileStorage storage;// = new FileStorage();
	Course* course = getCourseByCourseId(&storage, attach_course_id);

	if (course == NULL)
		return false;

	// save
	std::pair<long, long> course_pair(this->courseId, attach_course_id);
	if (CircleDetection::detectCircles(course_pair)) { // or maybe return flag only
		prerequisiteCourses.push_back(*course);
		save(false);
		return true;
	}

	return false;
}

void Course::removePrerequisiteCourse(Course course) {
	removePrerequisiteCourse(course.courseId);
}

void Course::removePrerequisiteCourse(long courseId) {
	int pos = -1;
	for (unsigned int i = 0; i < prerequisiteCourses.size(); i++)
	if (prerequisiteCourses[i].courseId == courseId)
		pos = i;

	if (pos > -1) {
		prerequisiteCourses.erase(prerequisiteCourses.begin() + pos);
		save(false);
	}
}

vector<Student*> Course::getStudentListForCourse()
{
	FileStorage fs;
	vector<Student> students = Student::getAllStudents(&fs);
	vector<Student*> students_list_course;

	for (unsigned int i = 0; i < students.size(); i++) {
		vector<Course*> vc = students[i].getCourseListForStudentById(students[i].getId());
		for (unsigned int j = 0; j < vc.size(); i++) {
			if (vc[j]->getId() == courseId)
				students_list_course.push_back(&students[i]);
		}
	}

	return students_list_course;
}

vector<Course> Course::getPreequisiteCourses() {
	return prerequisiteCourses;
}



