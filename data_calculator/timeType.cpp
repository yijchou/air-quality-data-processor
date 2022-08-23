#include "timeType.h"
#include <iostream>

using namespace std;

// default constructor:
timeType::timeType()
{
    hour = 23;
    minute = 59;
    second = 59;
}

// specific constructor
timeType::timeType(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

// set hour field with input integer
void timeType::setHour(int h){
    hour = h;
}

// set minute field
void timeType::setMinute(int m){
    minute = m;
}

// set second field
void timeType::setSecond(int s){
    second = s;
}

// set all fields in timeType class
void timeType::setTimeType(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}

// getter for hour field
int timeType::getHour() const{
    return hour;
}

// getter for minute field
int timeType::getMinute() const{
    return minute;
}

// getter for second field
int timeType::getSecond() const{
    return second;
}

// print method for timeType class:
void timeType::print() const{
    cout << "Time: " << hour << ":" << minute << ":" << second;
}

// ostream operator
ostream& operator << (ostream& osObject, const timeType& time1){
    osObject << time1.hour << ":" << time1.minute << ":" << time1.second;
    return osObject;
}

// istream operator
istream& operator >> (istream& isObject, timeType& time1){
    isObject >> time1.hour >> time1.minute >> time1.second;
    return isObject;
}

// overloaded less than operator for comparing two times:
bool timeType::operator<(const timeType& otherTime) const{
    // first check hour:
    if((hour < otherTime.hour) || 
        // if hour values are the same, check minute:
       (hour == otherTime.hour && minute < otherTime.minute) ||
       // if minute values are the same, check second:
       (hour == otherTime.hour && minute == otherTime.minute && second < otherTime.second)){
           return true;
        }
    // return false if none of the conditions are satisfied:
    else return false;
}

// overloaded equals operator for comparing two times
bool timeType::operator==(const timeType& otherTime) const{
    // verify that all fields have the same values:
    if(hour == otherTime.hour && minute == otherTime.minute && second == otherTime.second){
        return true;
    }
    else return false;
}

// overloaded less than or equal to operator for two times:
bool timeType::operator<=(const timeType& otherTime) const{
    // call less than or equal to operators:
    return(*this < otherTime || *this == otherTime);
}

// overloaded greater than operator for comparing two times:
bool timeType::operator>(const timeType& otherTime) const{
    // greater than is the opposite of(NOT) the less than or equal to operator:
    return !(*this <= otherTime);
}

// overloaded greater than or equal to operator:
bool timeType::operator>=(const timeType& otherTime) const{
    // greater than or equal to is the opposite(NOT) of the less than operator:
    return !(*this < otherTime);
}

// overloaded not equals operator:
bool timeType::operator!=(const timeType& otherTime) const{
    // opposite of the equals operator:
    return !(*this == otherTime);
}