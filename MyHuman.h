#pragma once

#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;


class Human {
private:
    string name;
    string lastname;
    int age;
    string job;
    int grade; // Min 1 - Max 10;
    int personalIdNumber = -1;
public:
    //GET/SET
    void setName(string name);
    string getName() const;

    void setLastName(string lastname);
    string getLastName() const;

    void setJob(string job);
    string getJob() const;

    void setAge(int age);
    int getAge() const;

    void setGrade(int grade);
    int getGrade() const;

    void setPersonalIdNumber(int personalIdNumber);
    int getPersonalIdNumber() const;
    //END GET/SET
    //Constuct
    Human();
    Human(string name, string lastname = "", int age = 18, string job = "", int grade = 1, int personalIdNumber = -1);
    //END Construct
    void setFullName(std::string FullName);

    void addYear();

    void changeJob(string Job);

    void addGrade();

    void reduceGrade();

    void assignID();
};