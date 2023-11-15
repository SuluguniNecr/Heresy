#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class InGameCurrency {
private:
    int gold = 0;
    int silver = 0;
    int copper = 0;
    int commendations = 0;
    int crystals = 0;
    string playerCredential = "- 1";

public:
    //GET/SET

    void setCopper(int copper);
    int getCopper() const;

    void setSilver(int silver);
    int getSilver() const;

    void setGold(int gold);
    int getGold() const;

    void setCommendations(int commendations);
    int getCommendations() const;

    void setCrystals(int crystals);
    int getCrystals() const;

    void setPlayerCredential(string playerCredential);
    string getPlayerCredential() const;

    //GET/SET End

    //Constructor
    //InGameCurrency(int copper, int silver = 0, int gold = 0, int commendations = 0, int crystals = 0, string playerCredential = "-1");
    InGameCurrency(int copper);
    InGameCurrency(int copper, int silver);
    InGameCurrency(int copper, int silver, int gold);

    InGameCurrency();
    InGameCurrency(InGameCurrency& t);
    ~InGameCurrency();
    //END Constructor

    void recalculate();

    void addCoins(int sum);

    void commend();

    void spendCommendations(int coms);

    void buyCrystal();

    void assignPlayer(string PhoneNumber);

};
