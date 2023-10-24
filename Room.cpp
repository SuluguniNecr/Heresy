#include "Room.h"

void Room::setDoors(int doors)
{
    if (doors < 0) doors = 0;
    Room::doors = doors;
}
int Room::getDoors() const
{
    return doors;
}

void Room::setWindows(int windows)
{
    if (windows < 0) windows = 0;
    Room::windows = windows;
}
int Room::getWindows() const
{
    return windows;
}

void Room::setSquareMeters(int sqaremeters)
{
    if (sqaremeters < 0) sqaremeters = 0;
    Room::sqaremeters = sqaremeters;
}
int Room::getSquareMeters() const
{
    return sqaremeters;
}

void Room::setLeadOutside(bool F)
{
    lead_outside = F;
}
void Room::setLeadOutside(int lead_outside)
{
    Room::lead_outside = (lead_outside > 0);
}
bool Room::getLeadOutside() const
{
    return lead_outside;
}

void Room::setRoomType(string room_type)
{
    Room::room_type = room_type;
}
string Room::getRoomType() const
{
    return room_type;
}

void Room::setOwner(int owner)
{
    Room::owner = owner;
}
int Room::getOwner() const
{
    return owner;
}
//GET/SET END
//Constructor
Room::Room()
{
    Room::setRoomType("Hallway");
    Room::setDoors(1);
    Room::setWindows(2);
    Room::setLeadOutside(true);
    Room::setSquareMeters(9);
    Room::changeOwner(-1);
}
Room::Room(string room_type, int doors, int windows, bool lead_outside, int sqaremeters, int owner)
{
    Room::setRoomType(room_type);
    Room::setDoors(doors);
    Room::setWindows(windows);
    Room::setLeadOutside(lead_outside);
    Room::setSquareMeters(sqaremeters);
    Room::changeOwner(owner);
}
//END Constructor

void Room::wallInTheDoor()
{
    if (Room::doors > 0) Room::doors--;
    //Технически эта функция проверяет наличие двери до того, как убрать её.
}

void Room::makeADoor()
{
    Room::doors++;
}

void Room::makeAWindow()
{
    Room::windows++;
}

void Room::toggleLeadOutside()
{
    Room::lead_outside = !Room::lead_outside;
}

void Room::blowUpTnT()
{
    Room::doors += rand() % 3;
    Room::windows += rand() % 5;
}

void Room::changeOwner(int ID)
{
    Room::setOwner(ID);
}