
// CS110C
// Joakim Dahl
// Assignment 12
// MyDictionaryClass
// File 3 of 3

#ifndef MY_DICTIONARY_CLASS
#define MY_DICTIONARY_CLASS

#include <string>
#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 25;

class MyDictionaryClass
{
    private:
        int size;
        Person* underlyingArray;
        int binarySearch(Person array[], int first, int last, Person entry);
    public:
        MyDictionaryClass();
        virtual ~MyDictionaryClass();
        bool add(Person newEntry);
        bool remove(Person entry);
        void displayAll();
        void displayMonth(int month);
        int binarySearch(Person entry);
        string birthdaySearch(Person entry);
};

#endif

MyDictionaryClass::MyDictionaryClass() : size(0)
{
    underlyingArray = new Person[DEFAULT_CAPACITY];
}

MyDictionaryClass::~MyDictionaryClass()
{
    delete[] underlyingArray;
}

int MyDictionaryClass::binarySearch(Person array[], int first, int last, Person entry)
{
   if(last >= first) 
   {
      int mid = first + (last - first) / 2;
 
      if(array[mid] == entry)
         return mid;

      if(array[mid].getName() > entry.getName())
         return binarySearch(array, first, mid - 1, entry);
 
      return binarySearch(array, mid + 1, last, entry);
    }
    return -1;
}

int MyDictionaryClass::binarySearch(Person entry)
{
   return binarySearch(underlyingArray, 0, size-1, entry);
}

string MyDictionaryClass::birthdaySearch(Person entry)
{
   return underlyingArray[binarySearch(entry)].getBirthday();
}

bool MyDictionaryClass::add(Person newEntry)
{
   if(size < 1)
   {
      underlyingArray[0] = newEntry;
      size++;
   }
   else if(size == DEFAULT_CAPACITY)
      return false;
   else
   {
      size++;
       int i = size-1;
       while (i > 0 && underlyingArray[i-1].getName() > newEntry.getName()) {
           underlyingArray[i] = underlyingArray[i-1];
           i--;
       }
       underlyingArray[i] = newEntry;
   }
   return true;
}

bool MyDictionaryClass::remove(Person entry)
{
   int index = binarySearch(entry);

   if(index < 0)
      return false;
   else
   {
      for(int i = index; i < size; i++)
      {
         underlyingArray[i] = underlyingArray[i+1];
      }
      size--;
   }
   return true;
}

void MyDictionaryClass::displayAll()
{
   for(int i = 0; i < size; i++)
   {
      cout << underlyingArray[i].getName() << " " << underlyingArray[i].getBirthday() << endl;
   }
}

void MyDictionaryClass::displayMonth(int month)
{
   for(int i = 0; i < size; i++)
   {
      if(underlyingArray[i].getBirthMonth() == month)
         cout << underlyingArray[i].getName() << " " << underlyingArray[i].getBirthday() << endl;
   }
}

