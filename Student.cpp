#include "Student.h"
#include <sstream>

//GET SET
void Student::setName(string name)
{
	this->name = name;
}

string Student::getName() const
{
	return this->name;
}

void Student::setLastname(string lastname)
{
	this->lastname = lastname;
}

string Student::getLastname() const
{
	return this->lastname;
}

void Student::setFathersname(string fathersname)
{
	this->fathersname = fathersname;
}

string Student::getFathersname() const
{
	return this->fathersname;
}

void Student::setAdress(string adress)
{
	this->adress = adress;
}

string Student::getAdress() const
{
	return this->adress;
}

void Student::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Student::getPhoneNumber() const
{
	return this->phoneNumber;
}

void Student::setPracticeCount(int practiceCount)
{
	this->practiceCount = practiceCount;
}

int Student::getPracticeCount() const
{
	return this->practiceCount;
}

void Student::setHomeworkCount(int homeworkCount)
{
	this->homeworkCount = homeworkCount;
}

int Student::getHomeworkCount() const
{
	return this->homeworkCount;
}

void Student::setExamCount(int examCount)
{
	this->examCount = examCount;
}

int Student::getExamCount() const
{
	return this->examCount;
}
//GET/SET END
//ToString
string Student::toString() const
{
	ostringstream result;
	result << getName() << " " << getLastname() << " " << getFathersname() << "\n" << getAdress() << "\n" << getPhoneNumber();
	return result.str();
}
//

//Construct
Student::Student()
{
	strikeMarks(true);
}
Student::~Student()
{

}
Student::Student(string name, string lastname, string fathersname) : Student()
{
	this->setName(name);
	this->setLastname(lastname);
	this->setFathersname(fathersname);
}
Student::Student(string name, string lastname, string fathersname, string adress, string phoneNumber) : Student(name, lastname, fathersname)
{
	this->setAdress(adress);
	this->setPhoneNumber(phoneNumber);
}
Student::Student(Student& t)
{
	this->setName(t.getName());
	this->setLastname(t.getLastname());
	this->setFathersname(t.getFathersname());
	this->setAdress(t.getAdress());
	this->setPhoneNumber(t.getPhoneNumber());
	//TBI - Copy Marks
}

string Student::getPracticeMarks() const
{
	ostringstream result;
	for (int i = 0; i < getPracticeCount(); i++)
	{
		result << practiceMarks[i] << " ";
	}
	return result.str();
}

string Student::getExamMarks() const
{
	ostringstream result;
	for (int i = 0; i < getExamCount(); i++)
	{
		result << examMarks[i] << " ";
	}
	return result.str();
}

string Student::getHomeworkMarks() const
{
	ostringstream result;
	for (int i = 0; i < getHomeworkCount(); i++)
	{
		result << homeworkMarks[i] << " ";
	}
	return result.str();
}

bool Student::addPracticeMarks(int mark)
{
	int steps = this->getPracticeCount();
	int* result = new int[steps + 1];
	for (int i = 0; i < steps; i++)
		result[i] = practiceMarks[i];
	result[steps] = mark;
	delete[] practiceMarks;
	practiceMarks = result;
	setPracticeCount(steps + 1);
	return true;
}

bool Student::addHomeworkMarks(int mark)
{
	int steps = this->getHomeworkCount();
	int* result = new int[steps + 1];
	for (int i = 0; i < steps; i++)
		result[i] = homeworkMarks[i];
	result[steps] = mark;
	delete[] homeworkMarks;
	homeworkMarks = result;
	setHomeworkCount(steps + 1);
	return true;
}


bool Student::addExamMarks(int mark)
{
	int steps = this->getExamCount();
	int* result = new int[steps + 1];
	for (int i = 0; i < steps; i++)
		result[i] = examMarks[i];
	result[steps] = mark;
	delete[] examMarks;
	examMarks = result;
	setExamCount(steps + 1);
	return true;
}

void Student::strikeMarks(bool isNew)
{
	if (!isNew)
	{
		delete[] practiceMarks;
		delete[] homeworkMarks;
		delete[] examMarks;
	}
	practiceMarks = new int[1];
	practiceMarks[0] = 0;
	setPracticeCount(0);

	homeworkMarks = new int[1];
	homeworkMarks[0] = 0;
	setHomeworkCount(0);

	examMarks = new int[1];
	examMarks[0] = 0;
	setExamCount(0);
}