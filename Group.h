#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
#include "Student.h"
using namespace std;

class Group {
private:
	Student* students;
	int studentCount;
	string courseName;
	string groupName;
	int courseYear;
	//Private Functions
	void sortByLastName();
	int estimateExamCount();

public:
	void setGroupName(string groupName);
	string getGroupName() const;

	void setCourseName(string courseName);
	string getCourseName() const;

	void setCourseYear(int courseYear);
	int getCourseYear() const;

	void setStudentCount(int studentCount);
	int getStudentCount() const;

	string toString() const;
	void emptyGroup(bool isNew);

	//===============================

	Group();
	~Group();
	Group(Group& t);

	//===============================

	void emptyGroup();
	void sortStudents(int sortType = 0);
	void addStudent(Student student, int sortType = 0);
	string listGroup(bool header = false);
	void expellStudent(int index);
	void transferStudent(int index, Group group);
	void mergeInto(Group group, bool onlyCopy = false);
	void mergeIn(Group group, bool onlyCopy = false);
	int findWorstExamMarks();
	void expellWorstExam();
	string peopleMissingExams(int i = -1, bool expell = false);

	string toString();
};