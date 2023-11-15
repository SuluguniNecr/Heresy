#include "Book.h"

//GET/SET

void Book::setName(string name)
{
    Book::name = name;
}
string Book::getName() const
{
    return name;
}

void Book::setAuthor(string author)
{
    Book::author = author;
}
string Book::getAuthor() const
{
    return author;
}

void Book::setGenre(string genre)
{
    Book::genre = genre;
}
string Book::getGenre() const
{
    return genre;
}

void Book::setYear(int year)
{
    if (year < 0) year = 0;
    Book::year = year;
}
int Book::getYear() const
{
    return year;
}

void Book::setCustomerId(int customerid)
{
    Book::customerid = customerid;
}

int Book::getCustomerId()
{
    return customerid;
}


//GET/SET End

//Constructor

Book::Book(string name) : Book::Book()
{
    this->setName(name);
}

Book::Book(string name, string author) : Book::Book(name)
{
    this->setAuthor(author);
}

Book::Book(string name, string author, int year) : Book::Book(name, author)
{
    this->setYear(year);
}

Book::Book()
{
    this->setName("Идиот");
    this->setAuthor("Достоевский");
    this->setYear(1869);
    this->setGenre("Роман");
    this->setCustomerId(-1);
}
Book::Book(Book& t)
{
    this->setName(t.getName());
    this->setAuthor(t.getAuthor());
    this->setYear(t.getYear());
    this->setGenre(t.getGenre());
    this->setCustomerId(t.getCustomerId());
}
Book::~Book()
{

}

//EMD Constructor

void Book::tweakYear(int i_Year)
{
    if (i_Year > 500 && i_Year < 2500)
    {
        Book::setYear(i_Year);
    }
}

void Book::tweakName(string s_Name)
{
    Book::setName(s_Name);
}

void Book::tweakAuthorName(string s_Name)
{
    Book::setAuthor(s_Name);
}

void Book::tweakGenre(string s_Name)
{
    Book::setGenre(s_Name);
}

bool  Book::giveOutBook(int customer)
{
    if (Book::getCustomerId() != -1)
    {
        return false;
    }
    else
    {
        Book::setCustomerId(customer);
        return true;
    }
}

bool  Book::returnBook()
{
    if (Book::getCustomerId() == -1)
    {
        return false;
    }
    else
    {
        Book::setCustomerId(-1);
        return true;
    }
}