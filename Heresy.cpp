// GitTutorial.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
using namespace std;

class Human {
public:
    string name = "Олег";
    string lastname = "Иванов";
    int age = 18;
    string job = "Грузчик";
    int grade = 1; // Min 1 - Max 10;

    void setName(std::string FullName)
    {
        std::size_t pos = FullName.find(" ");
        if (pos != std::string::npos)
        {
            std::stringstream ss;
            ss << FullName;
            string str;
            getline(ss, str, ' ');
            name = str;
            getline(ss, str, ' ');
            lastname = str;
        }
    }
    void addYear()
    {
        age++;
    }

    void changeJob(string Job)
    {
        job = Job;
    }

    void addGrade()
    {
        if (grade < 10) grade++;
    }

    void reduceGrade()
    {
        if (grade > 1) grade--;
    }
};

class Room {
public:
    string room_type = "Спальня";
    int doors = 1;
    int windows = 1;
    bool lead_outside = false;
    int sqaremeters = 9;

    void wallInTheDoor()
    {
        if (doors > 0) doors--;
    }

    void makeADoor()
    {
        doors++;
    }

    void makeAWindow()
    {
        windows++;
    }

    void ToggleLeadOutside()
    {
        lead_outside = !lead_outside;
    }

    void blowUpTnT()
    {
        doors += rand() % 3;
        windows += rand() % 5;
    }
};

class Phone {
public:
    string manufacturer = "Samsung";
    string model = "A20";
    string OS = "Android";
    string OSVersion = "12.0";
    string Number = "+3800000000000";

    void installOS(string Name)
    {
        OS = Name;
        OSVersion = "1.0";
    }
    void updateOS(string Version)
    {
        OSVersion = Version;
    }

    void changeSimPhone(string PhoneNumber)
    {
        Number = PhoneNumber;
    }

    void DefaultOS()
    {
        OS = "Android";
        OSVersion = "12.0";
    }

    void DefaultOSVersion()
    {
        if (OS == "Android")
            OSVersion = "12.0";
    }
};

class Book {
public:
    string name = "Идиот";
    string author = "Достоевский";
    int year = 1869;
    string genre = "Роман";
    int customerid = -1; //-1 no customer holds the book

    void tweakYear(int i_Year)
    {
        if (i_Year > 500 && i_Year < 2500)
        {
            year = i_Year;
        }
    }

    void tweakName(string s_Name)
    {
        name = s_Name;
    }

    void tweakAuthorName(string s_Name)
    {
        author = s_Name;
    }

    void tweakGenre(string s_Name)
    {
        genre = s_Name;
    }

    bool  giveOutBook(int customer)
    {
        if (customerid != -1)
        {
            return false;
        }
        else
        {
            customerid = customer;
            return true;
        }
    }

    bool  returnBook()
    {
        if (customerid != -1)
        {
            return false;
        }
        else
        {
            customerid = -1;
            return true;
        }
    }

};

class InGameCurrency {
public:
    int gold = 0;
    int silver = 0;
    int copper = 0;
    int commendations = 0;
    int crystals = 0;

    void Recalculate()
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

    void addCoins(int sum)
    {
        copper += sum;
        Recalculate;
    }

    void commend()
    {
        commendations++;
    }

    void spendCommendations(int coms)
    {
        if (coms > 0)
            commendations -= coms;
    }

    void buyCrystal()
    {
        if (gold >= 10)
        {
            gold -= 10;
            crystals++;
        }
    }

};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
