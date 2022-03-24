
// CS110C
// Joakim Dahl
// Assignment 12
// Person
// File 2 of 3

#ifndef _PERSON
#define _PERSON

#include <string>
#include <iostream>
using namespace std;

class Person
{
   private:
      string name;
      int birthMonth;
      int birthYear;
      int birthDate;
   public:
      Person();
      Person(string name, int year, int month, int day);
      virtual ~Person();
      string getName()
         { return name; }
      string getBirthday();
      void setBirthday(int year, int month, int date);
      void setName(string name);
      int getBirthMonth()
         { return birthMonth; }
      bool operator==(Person x);
};

#endif

Person::Person() : birthDate(0), birthYear(0), birthMonth(0), name("")
{
}

Person::Person(string name, int year, int month, int day)
{
   this->name = name;
   this->birthMonth = month;
   this->birthYear = year;
   this->birthDate = day;
}

Person::~Person()
{
}

string Person::getBirthday()
{
   return to_string(birthYear) + ' ' + to_string(birthMonth) + ' ' + to_string(birthDate);
}

void Person::setBirthday(int year, int month, int date)
{
   birthYear = year;
   birthDate = date;
   birthMonth = month;
}

void Person::setName(string name)
{
   this->name = name;
}

bool Person::operator==(Person x)
{
   return this->name == x.getName();
}

