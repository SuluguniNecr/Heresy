#pragma once
#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class Book {
private:
    string name;
    string author;
    int year;
    string genre;
    int customerid; //-1 no customer holds the book

public:
    //GET/SET

    void setName(string name);
    string getName() const;

    void setAuthor(string author);
    string getAuthor() const;

    void setGenre(string genre);
    string getGenre() const;

    void setYear(int year);
    int getYear() const;

    void setCustomerId(int customerid = -1);
    int getCustomerId();


    //GET/SET End

    //Constructor

    Book(string name);
    Book(string name, string author);
    Book(string name, string author, int year);

    Book();
    ~Book();
    Book(Book& t);

    //EMD Constructor

    void tweakYear(int i_Year);

    void tweakName(string s_Name);

    void tweakAuthorName(string s_Name);

    void tweakGenre(string s_Name);

    bool  giveOutBook(int customer);

    bool  returnBook();

};
