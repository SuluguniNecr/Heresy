#include <sstream>      // std::stringstream
#include "MyHuman.h"

void Human::setName(string name)
{
    Human::name = name;
}
string Human::getName() const
{
    return Human::name;
}

void Human::setLastName(string lastname)
{
    Human::lastname = lastname;
}
string Human::getLastName() const
{
    return Human::lastname;
}

void Human::setJob(string job)
{
    Human::job = job;
}
string Human::getJob() const
{
    return Human::job;
}

void Human::setAge(int age)
{
    if (age < 0) age = 0;
    Human::age = age;
}
int Human::getAge() const
{
    return Human::age;
}

void Human::setGrade(int grade)
{
    if (grade < 1) grade = 1;
    if (grade > 10) grade = 10;
    Human::grade = grade;
}
int Human::getGrade() const
{
    return Human::grade;
}

void Human::setPersonalIdNumber(int personalIdNumber)
{
    if (personalIdNumber < 0) personalIdNumber = 0;
    Human::personalIdNumber = personalIdNumber;
}
int Human::getPersonalIdNumber() const
{
    return Human::personalIdNumber;
}
//END GET/SET
//Construct
Human::Human()
{
    this->setName("Ivan");
    this->setLastName("Ivanov");
    this->setAge(18);
    this->setJob("");
    this->setGrade(-1);
    this->setPersonalIdNumber(-1);
}
Human::Human(string name) : Human()
{
    this->setName(name);
}
Human::Human(string name, string lastname) : Human(name)
{
    this->setLastName(lastname);
}
Human::Human(string name, string lastname, int age) : Human(name, lastname)
{
    this->setAge(age);
}
Human::Human(Human& t)
{
    this->setName(t.getName());
    this->setLastName(t.getLastName());
    this->setAge(t.getAge());
    this->setJob(t.getJob());
    this->setGrade(t.getGrade());
    this->setPersonalIdNumber(t.getPersonalIdNumber());
}
Human::~Human()
{

}
//END Construct
void Human::setFullName(std::string FullName)
{
    std::size_t pos = FullName.find(" ");
    if (pos != std::string::npos)
    {
        std::stringstream ss;
        ss << FullName;
        string str;
        getline(ss, str, ' ');
        Human::name = str;
        getline(ss, str, ' ');
        Human::lastname = str;
    }
}
void Human::addYear()
{
    Human::age++;
}

void Human::changeJob(string Job)
{
    Human::setJob(Job);
}

void Human::addGrade()
{
    if (Human::grade < 10) Human::grade++;
}

void Human::reduceGrade()
{
    if (Human::grade > 1) Human::grade--;
}

void Human::assignID()
{
    bool b_Error = false;
    if (getName() == "" || getLastName() == "")
    {
        printf("Person name is incomplete, please fix record");
        b_Error = true;
    }

    if (b_Error) { return; }
    personalIdNumber = rand() % 1000000 + 100000;
}