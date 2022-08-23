// import header file:
#include "dateType.h"
#include <iostream>

using namespace std;

// default constructor:
dateType::dateType()
{
    day = 1;
    month = 1;
    year = 1999;
}

// specific constructor
dateType::dateType(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// set day field with input integer
void dateType::setDay(int d){
    day = d;
}

// set month field
void dateType::setMonth(int m){
    month = m;
}

// set year field
void dateType::setYear(int y){
    year = y;
}

// set all fields in dateType class
void dateType::setDateType(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

// getter for day field
int dateType::getDay() const{
    return day;
}

// getter for month field
int dateType::getMonth() const{
    return month;
}

// getter for year field
int dateType::getYear() const{
    return year;
}

// print method for dateType class:
void dateType::print() const{
    cout << "Date: " << day << "/" << month << "/" << year;
}

// ostream operator
ostream& operator << (ostream& osObject, const dateType& date1){
    osObject << date1.day << "/" << date1.month << "/" << date1.year;
    return osObject;
}

// istream operator
istream& operator >> (istream& isObject, dateType& date1){
    isObject >> date1.day >> date1.month >> date1.year;
    return isObject;
}

// overloaded less than operator for comparing two dates:
bool dateType::operator<(const dateType& otherDate) const{
    // first check year:
    if((year < otherDate.year) || 
        // if year values are the same, check month:
       (year == otherDate.year && month < otherDate.month) ||
       // if month values are the same, check day:
       (year == otherDate.year && month == otherDate.month && day < otherDate.day)){
           return true;
        }
    // return false if none of the conditions are satisfied:
    else return false;
}

// overloaded equals operator for comparing two dates
bool dateType::operator==(const dateType& otherDate) const{
    // verify that all fields have the same values:
    if(day == otherDate.day && month == otherDate.month && year == otherDate.year){
        return true;
    }
    else return false;
}

// overloaded less than or equal to operator for two dates:
bool dateType::operator<=(const dateType& otherDate) const{
    // call less than or equal to operators:
    return(*this < otherDate || *this == otherDate);
}

// overloaded greater than operator for comparing two dates:
bool dateType::operator>(const dateType& otherDate) const{
    // greater than is the opposite of(NOT) the less than or equal to operator:
    return !(*this <= otherDate);
}

// overloaded greater than or equal to operator:
bool dateType::operator>=(const dateType& otherDate) const{
    // greater than or equal to is the opposite(NOT) of the less than operator:
    return !(*this < otherDate);
}

// overloaded not equals operator:
bool dateType::operator!=(const dateType& otherDate) const{
    // opposite of the equals operator:
    return !(*this == otherDate);
}