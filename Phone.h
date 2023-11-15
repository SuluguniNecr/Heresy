#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class Phone {
private:
    string manufacturer;
    string model;
    string OS;
    string OSVersion;
    string number;
    int ownerId;
public:
    //GET/SET
    void setManufacturer(string manufacturer);
    string getManufacturer() const;

    void setModel(string model);
    string getModel() const;

    void setOS(string OS);
    string getOS() const;

    void setOSVersion(string OSVersion);
    string getOSVersion() const;

    void setNumber(string number);
    string getNumber() const;

    void setOwnerId(int ownerId);
    int getOwnerId() const;

    //SET/GET end
    //Constructor

    //Phone(string manufacturer, string model, string OS = "Android", string OSVersion = "12.0", string number = "+3800000000000", int ownerId = -1);
    Phone(string manufacturer);
    Phone(string manufacturer, string model);
    Phone(string manufacturer, string model, string OS);
    Phone();
    Phone(Phone& t);
    ~Phone();

    //END Constructor
    void installOS(string Name);
    void updateOS(string Version);

    void changeSimPhone(string PhoneNumber);

    void defaultOS();

    void defaultOSVersion();

    void personRegistration(int universalId);
};
