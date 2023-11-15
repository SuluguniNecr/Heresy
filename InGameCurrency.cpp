#include "InGameCurrency.h"



void InGameCurrency::setCopper(int copper)
{
    if (copper < 0) copper = 0;
    InGameCurrency::copper = copper;
    InGameCurrency::recalculate();
}
int InGameCurrency::getCopper() const
{
    return copper;
}

void InGameCurrency::setSilver(int silver)
{
    if (silver < 0) silver = 0;
    InGameCurrency::silver = silver;
    InGameCurrency::recalculate();
}
int InGameCurrency::getSilver() const
{
    return silver;
}

void InGameCurrency::setGold(int gold)
{
    if (gold < 0) gold = 0;
    InGameCurrency::gold = gold;
    InGameCurrency::recalculate();
}
int InGameCurrency::getGold() const
{
    return gold;
}

void InGameCurrency::setCommendations(int commendations)
{
    if (commendations < 0) commendations = 0;
    InGameCurrency::commendations = commendations;
}
int InGameCurrency::getCommendations() const
{
    return commendations;
}

void InGameCurrency::setCrystals(int crystals)
{
    if (crystals < 0) crystals = 0;
    InGameCurrency::crystals = crystals;
}
int InGameCurrency::getCrystals() const
{
    return crystals;
}

string InGameCurrency::getPlayerCredential() const
{
    return playerCredential;
}

void InGameCurrency::setPlayerCredential(string playerCredential)
{
    InGameCurrency::playerCredential = playerCredential;
}

//GET/SET End

//Constructor
/*InGameCurrency::InGameCurrency(int copper, int silver, int gold, int commendations, int crystals, string playerCredential)
{
    InGameCurrency::setCopper(copper);
    InGameCurrency::setSilver(silver);
    InGameCurrency::setGold(gold);
    InGameCurrency::setCommendations(commendations);
    InGameCurrency::setCrystals(crystals);
    InGameCurrency::setPlayerCredential(playerCredential);
}*/
InGameCurrency::InGameCurrency(int copper) : InGameCurrency()
{
    InGameCurrency::setCopper(copper);
}
InGameCurrency::InGameCurrency(int copper, int silver) : InGameCurrency(copper)
{
    InGameCurrency::setSilver(silver);
}
InGameCurrency::InGameCurrency(int copper, int silver, int gold) : InGameCurrency(copper, silver)
{
    InGameCurrency::setGold(gold);
}

InGameCurrency::InGameCurrency()
{
    InGameCurrency::setCopper(0);
    InGameCurrency::setSilver(0);
    InGameCurrency::setGold(0);
    InGameCurrency::setCommendations(0);
    InGameCurrency::setCrystals(0);
    InGameCurrency::setPlayerCredential("-1");
}

InGameCurrency::InGameCurrency(InGameCurrency& t)
{
    InGameCurrency::setCopper(t.getCopper());
    InGameCurrency::setSilver(t.getSilver());
    InGameCurrency::setGold(t.getGold());
    InGameCurrency::setCommendations(t.getCommendations());
    InGameCurrency::setCrystals(t.getCrystals());
    InGameCurrency::setPlayerCredential(t.getPlayerCredential());
}


InGameCurrency::~InGameCurrency()
{

}
//END Constructor


void InGameCurrency::recalculate()
{
    if (copper < 0)
    {
        int SC = (copper * -1) % 100 + 1;
        silver -= SC;
        copper += SC * 100;
    }
    if (copper > 100)
    {
        silver += copper / 100;
        copper = copper % 100;
    }

    if (silver < 0)
    {
        int SC = (silver * -1) % 100 + 1;
        gold -= SC;
        silver += SC * 100;
    }
    if (silver > 100)
    {
        gold += silver / 100;
        silver = silver % 100;
    }
}

void InGameCurrency::addCoins(int sum)
{
    copper += sum;
    recalculate();
}

void InGameCurrency::commend()
{
    commendations++;
}

void InGameCurrency::spendCommendations(int coms)
{
    if (coms > 0)
        commendations -= coms;
}

void InGameCurrency::buyCrystal()
{
    if (getPlayerCredential() == "")
    {
        printf("Player must have confirmed number to complete the purchase");
        return;
    }
    if (gold >= 10)
    {
        gold -= 10;
        crystals++;
    }
}

void InGameCurrency::assignPlayer(string PhoneNumber)
{
    InGameCurrency::setPlayerCredential(PhoneNumber);
}