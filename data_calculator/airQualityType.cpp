#include "airQualityType.h"
#include <iostream>
#include <string>
#include "dateType.h"
#include "timeType.h"
using namespace std;

airQualityType::airQualityType()
{
    dateType defaultDate;
    timeType defaultTime;
    date = defaultDate;
    time = defaultTime;
    temperature = 0;
    relativeHumidity = 0;
    absoluteHumidity = 0;

}

airQualityType::airQualityType(dateType d, timeType t, double temp, 
        double relativeHumid, double absHumid)
{
    date = d;
    time = t;
    temperature = temp;
    relativeHumidity = relativeHumid;
    absoluteHumidity = absHumid;

}

// mutators
void airQualityType::setDate(dateType d){
    date = d;
}
void airQualityType::setTime(timeType t){
    time = t;
}
void airQualityType::setTemp(double temp){
    temperature = temp;
}
void airQualityType::setRelativeHumidity(double relativeHumid){
    relativeHumidity = relativeHumid;
}
void airQualityType::setAbsoluteHumidity(double absHumid){
    absoluteHumidity = absHumid;
}
void airQualityType::setAirQualityType(dateType d, timeType t, double temp, 
        double relativeHumid, double absHumid){
    date = d;
    time = t;
    temperature = temp;
    relativeHumidity = relativeHumid;
    absoluteHumidity = absHumid;
}

// accessors
dateType airQualityType::getDate() const{
    return date;
}
timeType airQualityType::getTime() const{
    return time;
}
double airQualityType::getTemp() const{
    return temperature;
}
double airQualityType::getRelativeHumidity() const{
    return relativeHumidity;
}
double airQualityType::getAbsoluteHumidity() const{
    return absoluteHumidity;
}
void airQualityType::print() const{
    date.print();
    time.print();
    cout << "Temperature: " << temperature << endl;
    cout << "Relative Humidity: " << relativeHumidity << endl;
    cout << "Absolute Humidity: " << absoluteHumidity << endl;
}

// comparisons:
bool airQualityType::operator<(const airQualityType& o) const{
    if(date < o.date){
        return true;
    }
    else if (date == o.date && time < o.time){
        return true;
    }
    else if (date == o.date && time == o.time && temperature < o.temperature){
        return true;
    }
    else if (date == o.date && time == o.time && temperature == o.temperature && 
        relativeHumidity < o.relativeHumidity){
        return true;
    }
    else if (date == o.date && time == o.time && temperature == o.temperature &&
        relativeHumidity == o.relativeHumidity && absoluteHumidity < o.absoluteHumidity){
            return true;
        }
    else return false;
}

bool airQualityType::operator>(const airQualityType& o) const{
    return !(*this <= o);
}
bool airQualityType::operator==(const airQualityType& o) const{
    return (date == o.date && time == o.time && temperature == o.temperature &&
    relativeHumidity == o.relativeHumidity && absoluteHumidity == o.absoluteHumidity);
}
bool airQualityType::operator<=(const airQualityType& o) const{
    return (*this < o || *this == o);
}
bool airQualityType::operator>=(const airQualityType& o) const{
    return !(*this < o);
}
bool airQualityType::operator!=(const airQualityType& o) const{
    return !(*this == o);
}