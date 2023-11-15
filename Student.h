#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class Student {
private:
	string name;
	string lastname;
	string fathersname;
	//DateTime Birthday TBI
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

	string toString() const;

	//===============================

	Student();
	~Student();
	Student(string name, string lastname, string fathersname);
	Student(string name, string lastname, string fathersname, string adress, string phoneNumber);
	Student(Student& t);

	//===============================

	string getPracticeMarks() const;
	string getHomeworkMarks() const;
	string getExamMarks() const;

	bool addPracticeMarks(int mark);
	bool addHomeworkMarks(int mark);
	bool addExamMarks(int mark);

	void strikeMarks(bool isNew = false);
};