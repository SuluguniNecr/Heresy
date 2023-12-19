// GitTutorial.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "MyHuman.h"
#include "Room.h"
#include "Phone.h"
#include "InGameCurrency.h"
#include "Book.h"
using namespace std;

int main()
{
    //std::cout << "Hello World!\n";
    // OLD CODE Legacy Task #1
    //
    //Human* MainCharacter = new Human();
    //Human* Deuteragonist = new Human("Helel", "Venus", 22);

    //Book* RentedBook = new Book();
    //Book* ReservedBook = new Book("Иллиада", "Гомер", 0);

    //InGameCurrency* GameProgress = new InGameCurrency();
    //InGameCurrency* AltAccount = new InGameCurrency(50,50,20);
    //
    //Phone* CellPhone = new Phone();
    //Phone* WorkPhone = new Phone("Apple", "i14", "iOS");
    //
    //Room* RentedRoom = new Room();
    //Room* DesiredRoom = new Room("Bedroom", 1, 2);


    //MainCharacter->assignID();
    ////Borrow a book from library
    //RentedBook->giveOutBook(MainCharacter->getPersonalIdNumber());
    ////Register new phone with pre-installed SIM
    //CellPhone->personRegistration(MainCharacter->getPersonalIdNumber());
    ////Register in mobile game via Phone Number
    //GameProgress->assignPlayer(CellPhone->getNumber());
    ////Rent a Room
    //RentedRoom->changeOwner(MainCharacter->getPersonalIdNumber());

    // END OLD CODE Legacy Task #1




    system("pause");
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
