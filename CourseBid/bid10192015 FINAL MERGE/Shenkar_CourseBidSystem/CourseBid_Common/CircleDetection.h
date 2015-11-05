/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer
**
** CircleDetection.h
** <very brief file description>
**
** Author: <original author>
** -------------------------------------------------------------------------*/
#ifndef CIRCLEDETECTION_H
#define CIRCLEDETECTION_H

#include <iostream>
#include <cstdint>	
#include <vector>
//#include <map>
#include <lemon\list_graph.h>
#include <lemon\bfs.h>
#include <lemon\maps.h>
#include "Course.h"
#include "FileStorage.h"

using namespace std;

class CircleDetection {
private:
	static map<long, bool> map_courses_exist;
	static bool buildCourseGraphForFileFormat(std::pair<long, long> course_pair, vector<std::pair<long, long>*>& vec_pair);
	static bool buildCourseGraphForFileFormat(long attached_course_id, vector<std::pair<long, long>*>& vec_pair, FileStorage& fs);
public:
	static bool detectCircles(std::pair<long, long> course_pair);
};

#endif CIRCLEDETECTION_H