/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CircleDetection.cpp
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#include "CircleDetection.h"

bool CircleDetection::detectCircles(std::pair<long, long> course_pair)
{
	//map_courses_exist.clear();
	FileStorage fs;
	if (Course::getCourseByCourseId(&fs, course_pair.first) == NULL || Course::getCourseByCourseId(&fs, course_pair.second) == NULL)
		return false;

	// check circle dependencies
	bool result;
	vector<std::pair<long, long>*> vec_pair;
	if (!buildCourseGraphForFileFormat(course_pair, vec_pair)) // Something went wrong..
		return false;

	ListDigraph g;
	CrossRefMap<ListDigraph, ListDigraph::Node, string> names(g);
	Bfs<ListDigraph> bfs(g);
	int line_counter;
	string n1, n2;
	bool flag = false;

	//while (infile >> n1 >> n2 && i<line_counter) {
	for (unsigned int i = 0; i<vec_pair.size(); i++) {
		n1 = to_string(vec_pair[i]->first);
		n2 = to_string(vec_pair[i]->second);

		auto u = names(n1);
		auto v = names(n2);

		// check if this node is exist
		if (g.id(u) == -1) {
			u = g.addNode();
			names.set(u, n1);
		}

		// check if this node is exist
		if (g.id(v) == -1) {
			v = g.addNode();
			names.set(v, n2);
		}

		bfs.run(v);
		for (ListDigraph::Node n = u; n != INVALID; n = bfs.predNode(n)) {
			if (bfs.reached(n)) {
				cout << names[n] << ",";
				flag = true;
			}

			g.addArc(u, v);

		}

		if (flag == true)
			cout << endl;
		flag = false;

	}

	return !flag; // return true if there is no circle dependencies
}

bool CircleDetection::buildCourseGraphForFileFormat(std::pair<long, long> course_pair, vector<std::pair<long, long>*>& vec_pair) {
	FileStorage fs;
	bool result = true;
	unsigned int i = 0;

	vector<Course> vec_course = Course::getAllCourses(&fs);
	// add all prerequiste courses for each course
	while (i < vec_course.size() && result) {
		result = buildCourseGraphForFileFormat(course_pair.first, vec_pair, fs); // MUST return true! if not, something on DB is wrong
		i++;
	}

	if (result)
		buildCourseGraphForFileFormat(course_pair.second, vec_pair, fs);

	if (!result) { // if any of builds encountered a problem
		vec_pair.clear(); // erase all values in vector
		return false;
	}

	vec_pair.push_back(new std::pair<long, long>(course_pair.first, course_pair.second));
	return true;
}

bool CircleDetection::buildCourseGraphForFileFormat(long attached_course_id, vector<std::pair<long, long>*>& vec_pair, FileStorage& fs) {
	Course* course = Course::getCourseByCourseId(&fs, attached_course_id);
	if (course == NULL) {
		return false;
	}
	else {
		vector<Course> vec_depen = course->getPreequisiteCourses();
		for (unsigned int i = 0; i < vec_depen.size(); i++)
			vec_pair.push_back(new std::pair<long, long>(attached_course_id, vec_depen[i].getCourseId()));
		return true;
	}
}
