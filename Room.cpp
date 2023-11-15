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
    this->setRoomType("Hallway");
    this->setDoors(1);
    this->setWindows(2);
    this->setLeadOutside(true);
    this->setSquareMeters(9);
    this->changeOwner(-1);
}

Room::Room(string room_type) : Room()
{
    this->setRoomType(room_type);
}

Room::Room(string room_type, int doors) : Room(room_type)
{
    this->setDoors(doors);
}
Room::Room(string room_type, int doors, int windows) : Room(room_type, doors)
{
    this->setWindows(windows);
}

Room::Room(Room& t)
{
    this->setRoomType(t.getRoomType());
    this->setDoors(t.getDoors());
    this->setWindows(t.getWindows());
    this->setLeadOutside(t.getLeadOutside());
    this->setSquareMeters(t.getSquareMeters());
    this->changeOwner(t.getOwner());
}

Room::~Room()
{

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