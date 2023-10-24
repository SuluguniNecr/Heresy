#include "Phone.h"

//GET/SET
void Phone::setManufacturer(string manufacturer)
{
    Phone::manufacturer = manufacturer;
}
string Phone::getManufacturer() const
{
    return manufacturer;
}

void Phone::setModel(string model)
{
    Phone::model = model;
}
string Phone::getModel() const
{
    return model;
}

void Phone::setOS(string OS)
{
    Phone::OS = OS;
}
string Phone::getOS() const
{
    return OS;
}

void Phone::setOSVersion(string OSVersion)
{
    Phone::OSVersion = OSVersion;
}
string Phone::getOSVersion() const
{
    return OSVersion;
}

void Phone::setNumber(string number)
{
    Phone::number = number;
}
string Phone::getNumber() const
{
    return number;
}

void Phone::setOwnerId(int ownerId)
{
    Phone::ownerId = ownerId;
}
int Phone::getOwnerId() const
{
    return ownerId;
}

//SET/GET end

//Constructor

Phone::Phone(string manufacturer, string model, string OS, string OSVersion, string number, int ownerId)
{
    Phone::setManufacturer(manufacturer);
    Phone::setModel(model);
    Phone::setOS(OS);
    Phone::setOSVersion(OSVersion);
    Phone::setNumber(number);
    Phone::setOwnerId(ownerId);
}

Phone::Phone()
{
    Phone::setManufacturer("Samsung");
    Phone::setModel("A20");
    Phone::setOS("Android");
    Phone::setOSVersion("12.0");
    Phone::setNumber("+3800000000000");
    Phone::setOwnerId(-1);
}

//END Constructor

void Phone::installOS(string Name)
{
    Phone::setOS(Name);
    Phone::setOSVersion("1.0");
}
void Phone::updateOS(string Version)
{
    Phone::setOSVersion(Version);
}

void Phone::changeSimPhone(string PhoneNumber)
{
    if (PhoneNumber.length() >= 7 && PhoneNumber.length() <= 12)
        Phone::setNumber(PhoneNumber);
    else
    {
        printf("Phone number -- invalid format");
        return;
    }
}

void Phone::defaultOS()
{
    Phone::setOS("Android");
    Phone::setOSVersion("12.0");
}

void Phone::defaultOSVersion()
{
    if (Phone::getOS() == "Android")
        Phone::setOSVersion("12.0");
}

void Phone::personRegistration(int universalId)
{
    Phone::setOwnerId(universalId);
}