
// CS110C
// Joakim Dahl
// Assignment 12
// main - Birthdays
// File 1 of 3

#include <string>
#include <iostream>
#include "Person.cpp"
#include "MyDictionaryClass.cpp"

using namespace std;

int main()
{
   MyDictionaryClass dictionary;

   Person person1("Joakim Dahl", 1991, 9, 3);
   Person person2("Random Human", 1992, 5, 6);
   Person person3("Some person", 1975, 10, 23); 
   Person person4("John Doe", 1980, 12, 30);
   Person person5("A Name", 1951, 1, 2);
   Person person6("Other Name", 1940, 9, 17);
   Person person7("Bob Bob", 1994, 4, 11);
   Person person8("Jane Doe", 1982, 9, 27);

   cout << "Adding Joakim Dahl, Random Human, Some person, " <<
      "John Doe, A Name, Other Name, Bob Bob, Jane Doe .. " << endl << endl;

   dictionary.add(person1);
   dictionary.add(person2);
   dictionary.add(person3);
   dictionary.add(person4);
   dictionary.add(person5);
   dictionary.add(person6);
   dictionary.add(person7);

   cout << "Displaying Month - September: " << endl;
   dictionary.displayMonth(9);
   cout << endl;

   cout << "Displaying All: " << endl;
   dictionary.displayAll(); 
   cout << endl;

   cout << "Removing A Name, Joakim Dahl .. " << endl << endl;

   dictionary.remove(person5);
   dictionary.remove(person1);

   cout << "Displaying Month - September: " << endl;
   dictionary.displayMonth(9);
   cout << endl;

   cout << "Displaying All: " << endl;
   dictionary.displayAll(); 
   cout << endl;

   cout << "Adding Jane Doe .. " << endl << endl;
   dictionary.add(person8);

   cout << "Removing Bob Bob, Random Human .. " << endl << endl; 

   dictionary.remove(person7);
   dictionary.remove(person2);

   cout << "Displaying Month - September: " << endl;
   dictionary.displayMonth(9);
   cout << endl;

   cout << "Displaying All: " << endl;
   dictionary.displayAll(); 
   cout << endl;

   dictionary.add(person2);

   cout << "Retrieve Random Human's birthday from dictionary: " << dictionary.birthdaySearch(person2) << endl;
   cout << "Retrieve Some person's birthday from dictionary: " << dictionary.birthdaySearch(person3) << endl;
   cout << "Retrieve Jane Doe's birthday from dictionary: " << dictionary.birthdaySearch(person8) << endl;

   return 0;
}

/*
*************
SAMPLE OUTPUT
*************
[jdahl3@hills ~]$ g++ assignment12.cpp && ./a.out
Adding Joakim Dahl, Random Human, Some person, John Doe, A Name, Other Name, Bob Bob, Jane Doe .. 

Displaying Month - September: 
Joakim Dahl 1991 9 3
Other Name 1940 9 17

Displaying All: 
A Name 1951 1 2
Bob Bob 1994 4 11
Joakim Dahl 1991 9 3
John Doe 1980 12 30
Other Name 1940 9 17
Random Human 1992 5 6
Some person 1975 10 23

Removing A Name, Joakim Dahl .. 

Displaying Month - September: 
Other Name 1940 9 17

Displaying All: 
Bob Bob 1994 4 11
John Doe 1980 12 30
Other Name 1940 9 17
Random Human 1992 5 6
Some person 1975 10 23

Adding Jane Doe .. 

Removing Bob Bob, Random Human .. 

Displaying Month - September: 
Jane Doe 1982 9 27
Other Name 1940 9 17

Displaying All: 
Jane Doe 1982 9 27
John Doe 1980 12 30
Other Name 1940 9 17
Some person 1975 10 23

Retrieve Random Human's birthday from dictionary: 1992 5 6
Retrieve Some person's birthday from dictionary: 1975 10 23
Retrieve Jane Doe's birthday from dictionary: 1982 9 27
*/