#ifndef AIRQUALITYTYPE_H
#define AIRQUALITYTYPE_H
#include <iostream>
#include <string>
#include "dateType.h"
#include "timeType.h"
using namespace std;

#pragma once

class airQualityType
{
    friend ostream& operator << (ostream&, const airQualityType&);
    friend istream& operator >> (istream&, airQualityType&);
public:
    airQualityType();
    airQualityType(dateType d, timeType t, double temp, double relativeHumid, double absHumid);

    // mutators
    void setDate(dateType d);
    void setTime(timeType t);
    void setTemp(double temp);
    void setRelativeHumidity(double relativeHumid);
    void setAbsoluteHumidity(double absHumid);
    void setAirQualityType(dateType d, timeType t, double temp, double relativeHumid, double absHumid);

    // accessors
    dateType getDate() const;
    timeType getTime() const;
    double getTemp() const;
    double getRelativeHumidity() const;
    double getAbsoluteHumidity() const;
    void print() const;

    // comparisons:
    bool operator<(const airQualityType& o) const;
    bool operator>(const airQualityType& o) const;
    bool operator==(const airQualityType& o) const;
    bool operator<=(const airQualityType& o) const;
    bool operator>=(const airQualityType& o) const;
    bool operator!=(const airQualityType& o) const;

private:
    dateType date;
    timeType time;
    double temperature;
    double relativeHumidity;
    double absoluteHumidity;

};

#endif