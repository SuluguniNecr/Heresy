#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
#include "DateTime.h"
using namespace std;

class Student {
private:
	string name;
	string lastname;
	string fathersname;
	CustomDateTime birthday;
	string adress;
	string phoneNumber;

	int* practiceMarks;
	int practiceCount;

	int* homeworkMarks;
	int homeworkCount;

	int* examMarks;
	int examCount;
public:
	void setName(string name);
	string getName() const;

	void setLastname(string lastname);
	string getLastname() const;

	void setFathersname(string lastname);
	string getFathersname() const;

	void setAdress(string adress);
	string getAdress() const;

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber() const;

	void setPracticeCount(int practiceCount);
	int getPracticeCount() const;

	void setHomeworkCount(int practiceCount);
	int getHomeworkCount() const;

	void setExamCount(int practiceCount);
	int getExamCount() const;

	void setBirthDay(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);
	string getBirthDay() const;

	string toString() const;
	string toShortString() const;

	//===============================

	Student();
	~Student();
	Student(string name, string lastname, string fathersname);
	Student(string name, string lastname, string fathersname, string adress, string phoneNumber);
	Student(string name, string lastname, string fathersname, string adress, string phoneNumber, int year, int month, int day, int hour = 0, int minute = 0, int second = 0);
	Student(Student& t);

	//===============================

	string getPracticeMarks() const;
	string getHomeworkMarks() const;
	string getExamMarks() const;
	int getAverageExamMarks() const;

	bool addPracticeMarks(int mark);
	bool addHomeworkMarks(int mark);
	bool addExamMarks(int mark);

	void strikeMarks(bool isNew = false);
};