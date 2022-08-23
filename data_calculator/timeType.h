#ifndef TIMETYPE_H
#define TIMETYPE_H
#include <iostream>
using namespace std;

#pragma once

class timeType
{
    friend ostream& operator << (ostream&, const timeType&);
    friend istream& operator >> (istream&, timeType&);

public:
    // two possible constructors:
    timeType();
    timeType(int h, int m, int s);

    // mutators:
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    void setTimeType(int h, int m, int s);

    // accessors:
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void print() const;

    // comparisons:
    bool operator<(const timeType& otherTime) const;
    bool operator>(const timeType& otherTime) const;
    bool operator==(const timeType& otherTime) const;
    bool operator<=(const timeType& otherTime) const;
    bool operator>=(const timeType& otherTime) const;
    bool operator!=(const timeType& otherTime) const;


private:
    // private fields for timeType class:
    int hour;
    int minute;
    int second;

};

#endif