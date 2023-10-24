#pragma once

#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;


class Room {
private:
    string room_type = "Спальня";
    int doors = 1;
    int windows = 1;
    bool lead_outside = false;
    int sqaremeters = 9;
    int owner = -1;
public:
    //GET/SET
    void setDoors(int doors);
    int getDoors() const;

    void setWindows(int windows);
    int getWindows() const;

    void setSquareMeters(int sqaremeters);
    int getSquareMeters() const;

    void setLeadOutside(bool F);
    void setLeadOutside(int lead_outside);
    bool getLeadOutside() const;

    void setRoomType(string room_type);
    string getRoomType() const;

    void setOwner(int owner);
    int getOwner() const;
    //GET/SET END
    Room();
    Room(string room_type, int doors = 1, int windows = 1, bool lead_outside = true, int sqaremeters = 9, int owner = -1);
    //

    void wallInTheDoor();

    void makeADoor();

    void makeAWindow();

    void toggleLeadOutside();

    void blowUpTnT();

    void changeOwner(int ID);
};