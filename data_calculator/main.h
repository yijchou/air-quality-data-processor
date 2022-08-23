
#ifndef CS5008_MAIN_H
#define CS5008_MAIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iomanip>
#include "airQualityType.h"
#include "dateType.h"
#include "timeType.h"

using namespace std;

vector<airQualityType> readFile(ifstream& infile);
airQualityType extractData(string s);
void userMenu(vector <airQualityType> vect);
double displayAvgTemp(vector <airQualityType> vect, int year, int month);
double displayAvgRelativeHumidity(vector <airQualityType> vect, int year, int month);
double displayAvgAbsoluteHumidity(vector <airQualityType> vect, int year, int month);
airQualityType displayInformationOnDay(vector <airQualityType> vect);
vector<int> checkMonth(int startMonth, int startYear, int endMonth, int endYear);
dateType checkDate();
timeType checkTime();
double displayHighestTemp(vector <airQualityType> vect, int year, int month);
double displayHighestRelativeHumidity(vector <airQualityType> vect, int year, int month);
double displayHighestAbsoluteHumidity(vector <airQualityType> vect, int year, int month);
void displayHigherThanAvgTemperature(vector<airQualityType> vect, int year, int month);
void displayHigherThanAvgRelativeHumidity(vector<airQualityType> vect, int year, int month);
void displayHigherThanAvgAbsoluteHumidity(vector<airQualityType> vect, int year, int month);


#endif //CS5008_MAIN_H
