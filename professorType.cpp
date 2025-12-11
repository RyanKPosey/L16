/*
    Programmer: Ryan Posey
    Assignment: L12D
    Purpose: Practice dynamic memory allocation
    Due date: 11/16/2025
*/

#include "professorType.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* Implementation of the professorType class. Doxygen comments removed from
   this translation unit as requested; documentation is kept in the header. */

// Default constructor
professorType::professorType()
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

// Shallow copy constructor
professorType::professorType(const professorType& other)
    : personType(other)
{
    employeeID = other.employeeID;
    department = other.department;
    degree = other.degree;
}

// Constructor with first and last name
professorType::professorType(const std::string& first, const std::string& last)
    : personType(first, last)
{
    setEmployeeID("NOT SET");
    setDepartment("NOT SET");
    setDegree("NOT SET");
}

// Full constructor
professorType::professorType(const std::string& first, const std::string& last,
                           const std::string& addr, double heightIn,
                           const std::string& dob, char gender, unsigned age,
                           const std::string& employeeID,
                           const std::string& department,
                           const std::string& degree)
    : personType(first, last, addr, heightIn, dob, gender, age)
{
    setEmployeeID(employeeID);
    setDepartment(department);
    setDegree(degree);
}

// Setters
void professorType::setEmployeeID(const std::string& id) {
    employeeID = id;
}

void professorType::setDepartment(const std::string& dept) {
    department = dept;
}

void professorType::setDegree(const std::string& deg) {
    degree = deg;
}

// Getters
std::string professorType::getEmployeeID() const {
    return employeeID;
}

std::string professorType::getDepartment() const {
    return department;
}

std::string professorType::getDegree() const {
    return degree;
}

// Print
void professorType::print() const {
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
         << "    Employee ID: " << employeeID << '\n'
         << "    Department: " << department << '\n'
         << "    Degree: " << degree << '\n';
}

// Equals
bool professorType::equals(const personType& other) const {
    auto otherProf = dynamic_cast<const professorType*>(&other);
    if (!otherProf) return false;
    if (!baseEquals(other)) return false;
    return employeeID == otherProf->employeeID &&
           department == otherProf->department &&
           degree == otherProf->degree;
}