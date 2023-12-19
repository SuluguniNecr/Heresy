#include "Student.h"
#include <sstream>

//GET SET
/**
*  Set students name
*
*@params string name contains name to be assigned to student
*
*/
void Student::setName(string name)
{
	this->name = name;
}
/**
*  Get string containing Name of student
*
*
*
*/
string Student::getName() const
{
	return this->name;
}

/**
*  Set students lastname
*
*@params string lastname contains lastname to be assigned to student
*
*/
void Student::setLastname(string lastname)
{
	this->lastname = lastname;
}

/**
*  Get string containing Lastname of student
*
*
*
*/
string Student::getLastname() const
{
	return this->lastname;
}

/**
*  Set students fathersname
*
*@params string fathersname contains fathersname to be assigned to student
*
*/
void Student::setFathersname(string fathersname)
{
	this->fathersname = fathersname;
}

/**
*  Get string containing Fathers name of student
*
*
*
*/
string Student::getFathersname() const
{
	return this->fathersname;
}

/**
*  Set students adress
*
*@params string adress contains adress to be assigned to student
*
*/
void Student::setAdress(string adress)
{
	this->adress = adress;
}

/**
*  Get string containing Adress of student
*
*
*
*/
string Student::getAdress() const
{
	return this->adress;
}
/**
*  Set students phone number
*
*@params string  phoneNumber contains  phone number to be assigned to student
*
*/
void Student::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

/**
*  Get string containing Phone number of student
*
*
*
*/
string Student::getPhoneNumber() const
{
	return this->phoneNumber;
}

/**
* **AVOID USING**  Set counter of user practice marks.
* TODO - Make field read only
*
*  @params int practiceCount - contains number of practice marks student have.
*/
void Student::setPracticeCount(int practiceCount)
{
	this->practiceCount = practiceCount;
}
/**
*  Get int containing number of parctice marks of student
*
*
*
*/
int Student::getPracticeCount() const
{
	return this->practiceCount;
}
/**
* **AVOID USING**  Set counter of user homework marks.
* TODO - Make field read only
*
*  @params int homeworkCount - contains number of homework marks student have.
*/
void Student::setHomeworkCount(int homeworkCount)
{
	this->homeworkCount = homeworkCount;
}

/**
*  Get int containing number of homework marks of student
*
*
*
*/

int Student::getHomeworkCount() const
{
	return this->homeworkCount;
}
/**
* **AVOID USING**  Set counter of user exam marks.
* TODO - Make field read only
*
*  @params int exameCount - contains number of exam marks student have.
*/
void Student::setExamCount(int examCount)
{
	this->examCount = examCount;
}

/**
*  Get int containing number of exam marks of student
*
*
*
*/

int Student::getExamCount() const
{
	return this->examCount;
}

void Student::setBirthDay(int year, int month, int day, int hour, int minute, int second)
{
	this->birthday.setDate(year, month, day, hour, minute, second);
}


/**
*  Get string containing Birthday of student
*
*
*
*/
string Student::getBirthDay() const
{
	return this->birthday.getDate();
}
//GET/SET END
//ToString
/**
*  Get string containing Name & Lastname of student
*
*
*
*/
string Student::toShortString() const
{
	ostringstream result;
	result << getName() << " " << getLastname();
	return result.str();
}

/**
*  Get string containing Full name of student, his adress and phone number
*
*
*
*/
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
	delete[] practiceMarks;
	delete[] homeworkMarks;
	delete[] examMarks;
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
Student::Student(string name, string lastname, string fathersname, string adress, string phoneNumber, int year, int month, int day, int hour = 0, int minute = 0, int second = 0) : Student(name, lastname, fathersname, adress, phoneNumber)
{
	this->setBirthDay(year, month, day, hour, minute, second);
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
/**
*  Get string containing marks values for Practice
*
*
*/
string Student::getPracticeMarks() const
{
	ostringstream result;
	for (int i = 0; i < getPracticeCount(); i++)
	{
		result << practiceMarks[i] << " ";
	}
	return result.str();
}

/**
*  Get string containing marks values for Exam
*
*
*/
string Student::getExamMarks() const
{
	ostringstream result;
	for (int i = 0; i < getExamCount(); i++)
	{
		result << examMarks[i] << " ";
	}
	return result.str();
}

/**
*  Get int containing average marks value for Exam
*
*
*/
int Student::getAverageExamMarks() const
{
	int sum = 0;
	for (int i = 0; i < getExamCount(); i++)
	{
		sum += examMarks[i];
	}
	return sum / getExamCount();
}

/**
*  Get string containing marks values for Homework
*
*
*/
string Student::getHomeworkMarks() const
{
	ostringstream result;
	for (int i = 0; i < getHomeworkCount(); i++)
	{
		result << homeworkMarks[i] << " ";
	}
	return result.str();
}

/**
*  Add Practice mark to student record
*
* @params int mark contains mark value to add to list
*/
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

/**
*  Add Homework mark to student record
*
* @params int mark contains mark value to add to list
*/
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

/**
*  Add Exam mark to student record
*
* @params int mark contains mark value to add to list
*/
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