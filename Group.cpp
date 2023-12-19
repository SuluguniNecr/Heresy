#include "Group.h"
#include <sstream>

void Group::setGroupName(string groupName)
{
	this->groupName = groupName;
}
string Group::getGroupName() const
{
	return this->groupName;
}

void Group::setCourseName(string courseName)
{
	this->courseName = courseName;
}
string Group::getCourseName() const
{
	return this->courseName;
}

void Group::setCourseYear(int courseYear)
{
	if (courseYear < 1) { courseYear = 1; printf("\n**Recieved year was below expected range. Deafaulting to year 1**\n"); }
	this->courseYear = courseYear;
}
int Group::getCourseYear() const
{
	return this->courseYear;
}

void Group::setStudentCount(int studentCount)
{
	//Value should not be available to change in public field, expect Property behavior
	return;
}
int Group::getStudentCount() const
{
	return this->studentCount;
}

//===============================

Group::Group()
{
	this->emptyGroup(true);
}
Group::~Group()
{
}
Group::Group(Group& t)
{
	this->mergeIn(t, true);
	this->setCourseName(t.getCourseName());
	this->setGroupName(t.getGroupName());
	this->setCourseYear(t.getCourseYear());
	this->studentCount = t.getStudentCount();
}

//===============================
void Group::emptyGroup(bool isNew)
{
	if (!isNew)
	{
		delete[] this->students;
	}
	this->studentCount = 0;
	this->students = new Student[1];
	Student student;
	this->students[0] = student;
}
/**
 * Clears students list
 *
 */
void Group::emptyGroup()
{
	this->studentCount = 0;
	this->students = new Student[1];
	Student student;
	this->students[0] = student;
}
/**
 * Sorts students list
 *
 * @params sortType declares what will be sorting criteria. Currently only 0 - Lastname supported
 */
void Group::sortStudents(int sortType = 0)
{
	if (getStudentCount() < 1)
	{
		printf("Group is empty, can't proceed with task.");
		return;
	}
	//This fucntion is made for possible expnasion of feature in the future
	switch (sortType)
	{
	case 0:
		this->sortByLastName();
		break;
	default:
		this->sortByLastName();
		break;
	}
}

void Group::sortByLastName()
{
	bool FLAG = true;
	while (FLAG)
	{
		FLAG = false;
		for (int i = 1; i < this->getStudentCount(); i++)
		{
			if (this->students[i].getLastname().compare(this->students[i - 1].getLastname()) > 0)
			{
				FLAG = true;
				Student temp = this->students[i];
				this->students[i] = this->students[i - 1];
				this->students[i - 1] = temp;
			}
		}
	}
}

/**
 * Adds a student to the group.
 *
 * @param student Class Student to be added to group.
 * @param sortType declares what will be sorting criteria. Currently only 0 - Lastname supported
 */
void Group::addStudent(Student student, int sortType = 0)
{
	Student* result = new Student[this->getStudentCount() + 1];
	switch (sortType) {
	case 0:
		int FLAG = 0;
		for (int i = 0; i < this->getStudentCount() + 1; i++)
		{
			if (students[i].getLastname().compare(student.getLastname()) > 0)
			{
				result[i] = student;
				FLAG = 1;
			}
			result[i + FLAG] = students[i];
		}
		if (FLAG == 0) result[getStudentCount() + 1] = student;
		break;
	default:
		break;

	}
	delete[] this->students;
	this->students = result;
	this->studentCount++;
}
/**
 * Generates header of the group.
 *
 * @return string containing header of the group (Name, Course Name, Year)
 */
string Group::toString()
{
	std::ostringstream oss;
	oss << "Group '" << this->getGroupName() << "' of '" << this->getCourseName() << "' course, Year #" << this->getCourseYear() << "\n";
	return oss.str();
}
/**
 * Generates list of students with optional header.
 *
 * @param header Specifies if You want to have header of the group. False value here will return only students list.
 * @return string containing list of students with optional header before it.
 */
string Group::listGroup(bool header = false)
{
	std::ostringstream oss;
	if (header) oss << this->toString();
	for (int i = 0; i < this->getStudentCount(); i++)
		oss << "#" << i + 1 << " - " << this->students[i].toShortString() << "\n";
	return oss.str();
}

/**
 * Removes Student from Group by his index
 *
 * @param index Specifies number of student to be expelled. Enumration starts from 0 and is not adjusted to human enumration from 1.
 */
void Group::expellStudent(int index)
{
	if (this->getStudentCount() < 1)
	{
		printf("Group is empty, can't proceed with task.");
		return;
	}
	if (index > this->getStudentCount() || index < 0)
	{
		printf("Index is out of bounds, can't proceed with task.");
	}
	Student* result = new Student[this->getStudentCount() - 1];
	for (int i = 0; i < this->getStudentCount(); i++)
	{
		if (i < index)
			result[i] = this->students[i];
		else if (i > index)
			result[i - 1] = this->students[i];
	}
	delete[] students;
	students = result;
	studentCount--;
}
/**
* Moves student of given index to given group
*
* @param index Specifies number of student to be moved. Enumration starts from 0 and is not adjusted to human enumration from 1.
*/
void Group::transferStudent(int index, Group group)
{
	if (this->getStudentCount() < 1)
	{
		printf("Group is empty, can't proceed with task.");
		return;
	}
	if (index > this->getStudentCount() || index < 0)
	{
		printf("Index is out of bounds, can't proceed with task.");
	}
	group.addStudent(this->students[index]);
	this->expellStudent(index);
}

void Group::mergeInto(Group group, bool onlyCopy)
{
	for (int i = 0; i < this->getStudentCount(); i++)
	{
		group.addStudent(this->students[i]);
	}
	if (!onlyCopy)
		this->emptyGroup();
}

void Group::mergeIn(Group group, bool onlyCopy)
{
	group.mergeInto(*this, onlyCopy);
}
/**
* Returns index of student with worst average Exam Score
*
*
*/
int Group::findWorstExamMarks()
{
	if (this->getStudentCount() < 1)
	{
		printf("Group is empty, can't proceed with task.");
		return -1;
	}
	int result = 0;
	//int MinMark = students[result].getAverageExamMarks();
	for (int i = 1; i < this->getStudentCount(); i++)
	{
		if (this->students[i].getAverageExamMarks() < this->students[result].getAverageExamMarks())
			result = i;
	}
	return result;
}

/**
* Removes student with worst average Exam Score from the Group
*
*
*/
void Group::expellWorstExam()
{
	this->expellStudent(findWorstExamMarks());
}

int Group::estimateExamCount()
{
	int result = 0;
	for (int i = 1; i < this->getStudentCount(); i++)
	{
		if (this->students[i].getExamCount() > result)
			result = this->students[i].getExamCount();
	}
	return result;
}

/**
* Returns list of students
*
* @params examCount Specifies how much exams must student have marks for to pass. Default value -1 will cause function to estimate this value over Max marks any student in group have.
* @params expell Specifies should students matching criteria be removed from Group.
*/

string Group::peopleMissingExams(int examCount, bool expell)
{
	std::ostringstream oss;

	if (examCount < 0) examCount = this->estimateExamCount();
	for (int i = 0; i < this->getStudentCount(); i++)
	{
		if (this->students[i].getExamCount() < examCount)
			oss << "#" << i + 1 << " - " << this->students[i].toShortString() << "\n";
	}
	if (expell)
	{
		for (int i = this->getStudentCount() - 1; i > -1; i--)
		{
			if (this->students[i].getExamCount() < examCount)
				this->expellStudent(i);
		}
		oss << "Students listed above were expeled\n";
	}
	else
		oss << "Students listed above were not expeled\n";
	return oss.str();
}