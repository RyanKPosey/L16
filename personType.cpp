/*
    Programmer: Ryan Posey
    Assignment: L12E
    Purpose: Abstract base class implementation (personType)
    Date: 11/24/2025
*/

#include <iostream>
#include <cctype>
#include <cstdint>
#include <iomanip>
#include "personType.h"

using namespace std;

// Full constructor
personType::personType(
    const string& firstName, const string& lastName, const string& address,
    double height, const string& DOB, char gender, uint16_t age
) {
    firstName_ = firstName;
    lastName_ = lastName;
    address_ = address;
    height_inches_ = height;
    date_of_birth_ = DOB;
    gender_ = gender;
    age_ = age;
}

// First + Last constructor
personType::personType(const string& firstName, const string& lastName) {
    firstName_ = firstName;
    lastName_ = lastName;
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

// Default constructor
personType::personType() {
    firstName_ = "Not Set";
    lastName_ = "";
    address_ = "Not Set";
    height_inches_ = 0.0;
    date_of_birth_ = "Not Set";
    gender_ = 'N';
    age_ = 0;
}

// Shallow copy constructor
personType::personType(const personType& other)
    : firstName_(other.firstName_)
    , lastName_(other.lastName_)
    , address_(other.address_)
    , height_inches_(other.height_inches_)
    , date_of_birth_(other.date_of_birth_)
    , gender_(other.gender_)
    , age_(other.age_)
    , mother(other.mother)
    , father(other.father)
{
}

personType::~personType() {
    // No dynamic ownership; nothing to free.
}

// Helper: case-insensitive string comparison
bool compareStringCaseInsensitive(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (static_cast<unsigned char>(tolower(static_cast<unsigned char>(a[i]))) !=
            static_cast<unsigned char>(tolower(static_cast<unsigned char>(b[i])))) {
            return false;
        }
    }
    return true;
}

// Protected base comparison (used by derived equals())
bool personType::baseEquals(const personType& other) const {
    if (!compareStringCaseInsensitive(getName(), other.getName())) return false;
    if (!compareStringCaseInsensitive(getAddress(), other.getAddress())) return false;
    if (getHeight() != other.getHeight()) return false;
    if (!compareStringCaseInsensitive(getDOB(), other.getDOB())) return false;
    if (static_cast<unsigned char>(tolower(static_cast<unsigned char>(getGender()))) !=
        static_cast<unsigned char>(tolower(static_cast<unsigned char>(other.getGender())))) return false;
    if (getAge() != other.getAge()) return false;
    return true;
}

// Setters
void personType::setName(const string& name) {
    size_t pos = name.find_first_of(" \t");
    if (pos == string::npos) {
        firstName_ = name;
        lastName_.clear();
    } else {
        firstName_ = name.substr(0, pos);
        size_t startLast = name.find_first_not_of(" \t", pos);
        if (startLast == string::npos) {
            lastName_.clear();
        } else {
            lastName_ = name.substr(startLast);
        }
    }
}

void personType::setFirstName(const string& firstName) { firstName_ = firstName; }
void personType::setLastName(const string& lastName) { lastName_ = lastName; }
void personType::setAddress(const string& address) { address_ = address; }
void personType::setHeight(double height) { height_inches_ = (height < 0 || height > 120) ? 0 : height; }
void personType::setDOB(const string& DOB) { date_of_birth_ = DOB; }
void personType::setGender(char gender) { gender_ = gender; }
void personType::setAge(uint16_t age) { age_ = (age > 999) ? 0 : age; }
void personType::setMother(personType* m) { mother = m; }
void personType::setFather(personType* f) { father = f; }

// Getters
string personType::getName() const { return lastName_.empty() ? firstName_ : (firstName_ + " " + lastName_); }
string personType::getFirstName() const { return firstName_; }
string personType::getLastName() const { return lastName_; }
string personType::getAddress() const { return address_; }
double personType::getHeight() const { return height_inches_; }
string personType::getDOB() const { return date_of_birth_; }
char personType::getGender() const { return gender_; }
uint16_t personType::getAge() const { return age_; }
personType* personType::getMother() const { return mother; }
personType* personType::getFather() const { return father; }

// Static utilities
int personType::getTallest(const vector<personType>& people) {
    if (people.empty()) return -1;
    size_t tallestIndex = 0;
    for (size_t i = 1; i < people.size(); ++i) {
        if (people[i].getHeight() > people[tallestIndex].getHeight()) tallestIndex = i;
    }
    return static_cast<int>(tallestIndex);
}

int personType::getOldest(const vector<personType>& people) {
    if (people.empty()) return -1;
    size_t oldestIndex = 0;
    for (size_t i = 1; i < people.size(); ++i) {
        if (people[i].getAge() > people[oldestIndex].getAge()) oldestIndex = i;
    }
    return static_cast<int>(oldestIndex);
}

int personType::getYoungest(const vector<personType>& people) {
    if (people.empty()) return -1;
    size_t youngestIndex = 0;
    for (size_t i = 1; i < people.size(); ++i) {
        if (people[i].getAge() < people[youngestIndex].getAge()) youngestIndex = i;
    }
    return static_cast<int>(youngestIndex);
}

bool personType::operator<(const personType& rhs)  {
    if (this->getLastName() == rhs.getLastName()) {
        return this->getFirstName() < rhs.getFirstName();
    } else {
        return this->getLastName() < rhs.getLastName();
    }
}

std::ostream& operator<<(std::ostream& os, const personType& p) {
    os << p.getFirstName() << " " << p.getLastName();
    return os;
}