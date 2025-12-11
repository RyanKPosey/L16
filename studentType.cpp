/*
    Programmer: Ryan Posey
    Assignment: L12D
    Purpose: Practice dynamic memory allocation
    Due date: 11/16/2025
*/

#include "studentType.h"
#include <iostream>
#include <iomanip>

using namespace std;

studentType::studentType()
{
        //cout << "Default StudentType constructor called" << endl;
        setID("NOT SET");
        setClassification("NOT SET");
        setGPA(0.0);
}


studentType::studentType(const string first, const string last)
        : personType(first, last)
{/** CODE BLOCK **/
        //cout << getFirstName() << " " << "studentType constructor called" << endl;
        setID("NOT SET");
        setClassification("NOT SET");
        setGPA(0.0);
}


studentType::studentType(const string first, const string last, const double g, const string i, const string c)
        : personType(first, last)
{
        setID(i);
        setClassification(c);
        setGPA(g);
        //cout << "First Name, Last Name, gpa, id, classification studentType constructor called" << endl;
}

 

studentType::~studentType(){
        //cout << "Inside studentType Destructor for: " << getFirstName() << endl;
}

// Shallow copy constructor
studentType::studentType(const studentType& other)
        : personType(other) // copy base
{
        id = other.id;
        classification = other.classification;
        gpa = other.gpa;
}


// Setters
void studentType::setGPA(double g) {
        if (g < 0)
                g = 0;
        else
                if (g > 4.0)
                        g = 4.0;

        gpa = g;
}

void studentType::setID(const string ident) {
        id = ident;
}

void studentType::setClassification(const string cls) {
        classification = cls;
}

// Getters
double studentType::getGPA() const {
        return gpa;
}

string studentType::getID() const {
        return id;
}

string studentType::getClassification() const {
        return classification;
}

void studentType::print() const {
    // Parent info
    cout << left << setw(10) << "Mother: "
            << (getMother() ? (getMother()->getFirstName() + " " + getMother()->getLastName()) : "NOT SET") << '\n';
    cout << left << setw(10) << "Father: "
            << (getFather() ? (getFather()->getFirstName() + " " + getFather()->getLastName()) : "NOT SET") << '\n';

    cout << left << setw(10) << " | Name: " << left << getName() << '\n'
            << left << setw(10) << " | Address: " << left << getAddress() << '\n'
            << left << setw(10) << " | Height: " << left << fixed << setprecision(1) << getHeight() << " in" << '\n'
            << left << setw(10) << " | DOB: " << left << getDOB() << '\n'
            << left << setw(10) << " | Gender: " << left << getGender() << '\n'
            << left << setw(10) << " | Age: " << left << static_cast<int>(getAge()) << '\n'
            << "    ID: " << id << '\n'
            << "    Classification: " << classification << '\n'
            << "    GPA: " << setprecision(2) << showpoint << gpa << '\n';
}

bool studentType::equals(const personType& other) const {
    // Ensure same dynamic type
    auto otherStudent = dynamic_cast<const studentType*>(&other);
    if (!otherStudent) return false;
    if (!baseEquals(other)) return false; // compare base members
    return id == otherStudent->id &&
                 classification == otherStudent->classification &&
                 gpa == otherStudent->gpa;
}