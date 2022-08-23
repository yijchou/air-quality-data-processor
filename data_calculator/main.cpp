#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include "airQualityType.h"
#include "dateType.h"
#include "timeType.h"
#include "main.h"
//#include "airQualityType.cpp"
//#include "dateType.cpp"
//#include "timeType.cpp"

using namespace std;
const int MAX_DAY = 31, MAX_MONTH = 12;
const int MAX_HOUR = 23, MAX_DEFAULT = 59;
const int ROUND_TWO = 2;
const int NUM_ATTRIBUTES = 19, MONTH_INDEX = 0, DAY_INDEX = 1, YEAR_INDEX = 2;
const int HOUR_INDEX = 3, MIN_INDEX = 4, SEC_INDEX = 5;
const int TEMPERATURE_INDEX = 16, RELATIVE_HUMIDITY_INDEX = 17, ABSOLUTE_HUMIDITY_INDEX = 18;
const int IGNORE = -200;

int main(){

    bool doneRead = false;
    while (!doneRead){
        ifstream infile;
        vector <airQualityType> vect = readFile(infile);
        if(!vect.empty()){
            doneRead = true;
            userMenu(vect);
        }
        else{
            cout << "The filepath is invalid. " << endl;
        }
    }


    return 0;
}

double displayAvgTemp(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 1. Prompt the user to enter a month and the program should display the average
     * temperature for that month
    */
    double total;
    int counter = 0;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getDate().getYear() == year)
        {
            total = total + vect.at(i).getTemp();
            counter++;
        }
    }
    double avg = total / counter;
    cout << "Average temperature for Month " << month << " is " << avg << " Degrees Celsius." << endl;
    return avg;
}

double displayAvgRelativeHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 2. Prompt the user to enter a month and the program should display the average
     * relative humidity for that month
    */
    double avg;
    int counter = 0;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getDate().getYear() == year)
        {
            avg = avg + vect.at(i).getRelativeHumidity();
            counter++;
        }
    }
    avg = avg / counter;
    cout << "Average Relative Humidity for Month " << month << " is " << avg << "%." << endl;
    return avg;
}

double displayAvgAbsoluteHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 3. Prompt the user to enter a month and the program should display the average
     * absolute humidity for that month
    */
    double avg;
    int counter = 0;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getDate().getYear() == year)
        {
            avg = avg + vect.at(i).getAbsoluteHumidity();
            counter++;
        }
    }
    avg = avg / counter;
    cout << "Average Absolute Humidity for Month " << month << " is " << avg << "." << endl;
    return avg;
}

airQualityType displayInformationOnDay(vector<airQualityType> vect)
{
    /**
     * Question 4. Prompt the user to enter a valid date and time. The program should then 
     * display the temperature and relative humidity at that date and time.
    */
    dateType date1 = checkDate();
    timeType time1 = checkTime();
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate() == date1 && vect.at(i).getTime() == time1)
        {
            cout << "Found Information for input Date and Time!" << endl;
            cout << "Temperature: " << vect.at(i).getTemp() << endl;
            cout << "Relative Humidity: " << vect.at(i).getRelativeHumidity() << endl;
            return vect.at(i);
        }
    }
    cout << "Date and Time not found in our data base. Search another date!" << endl;
    return displayInformationOnDay(vect);
}

double displayHighestTemp(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 5. Prompt the user to enter a month and the program should display the highest
     * temperature for that month
    */
    double max;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getTemp() > max && vect.at(i).getDate().getYear() == year)
        {
            max = vect.at(i).getTemp();
        }
    }
    cout << "Highest Temperature for Month " << month << " is " << max << " Degrees Celsius." << endl;
    return max;
}

double displayHighestRelativeHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 6. Prompt the user to enter a month and the program should display the highest
     * relative humidity for that month
    */
    double max;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getRelativeHumidity() > max && vect.at(i).getDate().getYear() == year)
        {
            max = vect.at(i).getRelativeHumidity();
        }
    }
    cout << "Highest Relative Humidity for Month " << month << " is " << max << "%." << endl;
    return max;
}

double displayHighestAbsoluteHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * Question 7. Prompt the user to enter a month and the program should display the highest
     * absolute humidity for that month
    */
    double max;
    for (int i = 0; i < vect.size(); ++i)
    {
        if (vect.at(i).getDate().getMonth() == month && vect.at(i).getAbsoluteHumidity() > max && vect.at(i).getDate().getYear() == year)
        {
            max = vect.at(i).getAbsoluteHumidity();
        }
    }
    cout << "Highest Absolute Humidity for Month " << month << " is " << max << "." << endl;
    return max;
}

void displayHigherThanAvgTemperature(vector<airQualityType> vect, int year, int month)
{
    /**
     * 8) Display the dates and times for a month when the temperature is higher than the average temperature 
     * for that month along with values of the temperature.
     */
    double avgTemp = displayAvgTemp(vect, year, month);
    vector<airQualityType> filter;
    cout << "The dates and times for a month when the temperature is higher than the average temperature: " << endl;
    for (airQualityType a : vect)
    {
        if (a.getDate().getMonth() == month && a.getTemp() > avgTemp && a.getDate().getYear() == year)
        {
            filter.push_back(a);
            a.getDate().print();
            cout << "   ";
            a.getTime().print();
            cout << endl;
        }
    }
    cout << "The filter data size is " << filter.size() << endl;
}

void displayHigherThanAvgRelativeHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * 9) Display the dates and times for a month when the relative humidity is higher than the average relative humidity 
     * for that month along with values of the relative humidity.
     */
    double avgRelativeHumidity = displayAvgRelativeHumidity(vect, year, month);
    vector<airQualityType> filter;
    cout << "The dates and times for a month when the relative humidity is higher than the average relative humidity: " << endl;
    for (airQualityType a : vect)
    {
        if (a.getDate().getMonth() == month && a.getRelativeHumidity() > avgRelativeHumidity && a.getDate().getYear() == year)
        {
            filter.push_back(a);
            a.getDate().print();
            cout << "   ";
            a.getTime().print();
            cout << endl;
        }
    }
    cout << "The filter data size is " << filter.size() << endl;
}

void displayHigherThanAvgAbsoluteHumidity(vector<airQualityType> vect, int year, int month)
{
    /**
     * 10) Display the dates and times for a month when the absolute humidity is higher than the average
     * absolute humidity for that month along with values of the absolute humidity.
     */
    double avgAbsoluteHumidity = displayAvgAbsoluteHumidity(vect, year, month);
    vector<airQualityType> filter;
    cout << "The dates and times for a month when the absolute humidity is higher than the average absolute humidity: " << endl;
    for (airQualityType a : vect)
    {
        if (a.getDate().getMonth() == month && a.getAbsoluteHumidity() > avgAbsoluteHumidity && a.getDate().getYear() == year)
        {
            filter.push_back(a);
            a.getDate().print();
            cout << "   ";
            a.getTime().print();
            cout << endl;
        }
    }
    cout << "The filter data size is " << filter.size() << endl;
}

vector<int> checkMonth(int startMonth, int startYear, int endMonth, int endYear)
{
    vector<int> yearAndMonth;
    bool doneMonth = false;
    int year, month;
    while (!doneMonth)
    {
        cout << "Please enter a year using its integer value (" << startYear << "-" << endYear << "): ";
        cin >> year;
        cout << "Please enter a month using its integer value (1-12): ";
        cin >> month;
        int startAllMonths = startMonth + (startYear - 1) * MAX_MONTH;
        int endAllMonths = endMonth + (endYear - 1) * MAX_MONTH;
        int givenAllMonths = month + (year - 1) * MAX_MONTH;
        if (givenAllMonths >= startAllMonths && givenAllMonths <= endAllMonths)
        {
            yearAndMonth.push_back(year);
            yearAndMonth.push_back(month);
            doneMonth = true;
        }
        else
        {
            cout << "Please enter valid month and year." << endl;
        }
    }
    return yearAndMonth;
}
dateType checkDate()
{
    int day, month, year;
    cout << "Please enter a valid date in the following format- Day Month Year (use spaces to separate values): ";
    cin >> day >> month >> year;
    if (day > MAX_DAY || day < 1 || month > MAX_MONTH || month < 1 || year < 0)
    {
        cout << "Invalid date entry. Try again..." << endl;
        dateType date1 = checkDate();
    }
    dateType date1(day, month, year);
    return date1;
}

timeType checkTime()
{
    int hour, min, sec;

    cout << "Please enter a valid time in the following format- Hour Minute Second (use spaces to separate values): ";
    cin >> hour >> min >> sec;
    if (hour > MAX_HOUR || hour < 0 || min > MAX_DEFAULT || min < 0 || sec > MAX_DEFAULT || sec < 0)
    {
        cout << "Invalid time entry. Try again..." << endl;
        timeType time1 = checkTime();
    }
    timeType time1(hour, min, sec);
    return time1;
}

void userMenu(vector<airQualityType> vect)
{

    cout << fixed << showpoint << setprecision(ROUND_TWO);
    string option;
    bool done = false;
    cout << "Welcome to the Air Quality Database!" << endl;
    cout << "Our database stores the following information from 3/2004 to 4/2005:" << endl;
    cout << " - Date using the standard Day/Month/Year format." << endl;
    cout << " - Time using the standard Hour:Min:Sec format." << endl;
    cout << " - Temperature represented in degrees Celsius." << endl;
    cout << " - Relative Humidity(%)." << endl;
    cout << " - Absolute Humidity." << endl;
    cout << "Here is the current number of entries in our database: " << vect.size() << endl;
    int startMonth = vect.at(0).getDate().getMonth();
    int startYear = vect.at(0).getDate().getYear();
    int endMonth = vect.at(vect.size() - 1).getDate().getMonth();
    int endYear = vect.at(vect.size() - 1).getDate().getYear();
    while (!done)
    {
        cout << "Please choose from the options(from 1 to 10, q for quit): " << endl;
        cout << "1. calculate the Average Temperature for a specific month" << endl;
        cout << "2. calculate the Average Relative Humidity for a specific month." << endl;
        cout << "3. calculate the Average Absolute Humidity for a specific month." << endl;
        cout << "4. find the Air Quality information for a specific Date and Time." << endl;
        cout << "5. find the Highest Temperature for a specific month." << endl;
        cout << "6. find the Highest Relative Humidity for a specific month." << endl;
        cout << "7. find the Highest Absolute Humidity for a specific month." << endl;
        cout << "8. find the dates and times for a month when the temperature is higher than \n   the "
                "average temperature for a specific month."
             << endl;
        cout << "9. find the dates and times for a month when the relative humidity is higher \n   than "
                "the average relative humidity for a specific month."
             << endl;
        cout << "10. find the dates and times for a month when the absolute humidity is higher\n    than "
                "the average absolute humidity for a specific month."
             << endl;
        cin >> option;

        if (option == "1")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayAvgTemp(vect, year, month);
            cout << endl;
        }
        else if (option == "2")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayAvgRelativeHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "3")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayAvgAbsoluteHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "4")
        {
            displayInformationOnDay(vect);
            cout << endl;
        }
        else if (option == "5")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHighestTemp(vect, year, month);
            cout << endl;
        }
        else if (option == "6")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHighestRelativeHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "7")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHighestAbsoluteHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "8")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHigherThanAvgTemperature(vect, year, month);
            cout << endl;
        }
        else if (option == "9")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHigherThanAvgRelativeHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "10")
        {
            vector<int> yAM = checkMonth(startMonth, startYear, endMonth, endYear);
            int year = yAM.at(0);
            int month = yAM.at(1);
            displayHigherThanAvgAbsoluteHumidity(vect, year, month);
            cout << endl;
        }
        else if (option == "q")
        {
            done = true;
            cout << endl;
            cout << "Exit!" << endl;
        }
        else
        {
            cout << "Please enter valid input!" << endl;
        }
    }
}

vector<airQualityType> readFile(ifstream &infile)
{
    vector<airQualityType> vect;
    airQualityType current;
    string line, f;
    cout << "Please enter the name of your file: ";
    cin >> f;
    infile.open(f);
    // print error message
    if (!infile)
    {
        cout << "Invalid file. Please check file name: " << f << ". ";
        return vect;
    }
    else
    {
        // ignore first line (with headers)
        getline(infile, line);
        // continue through the rest of the lines, add to vect
        while (getline(infile, line))
        {
            current = extractData(line);
            if (current.getTemp() != IGNORE
            && current.getRelativeHumidity() != IGNORE
            && current.getAbsoluteHumidity() != IGNORE){
                vect.push_back(current);
            }
        }
        infile.close();
    }
    return vect;
}

airQualityType extractData(string s)
{

    double x;
    char c;
    double entries[NUM_ATTRIBUTES];
    string current = "";
    int counter = 0;
    for (int i = 0; i < s.length() + 1; ++i)
    {
        c = s[i];
        if (c == ',' || c == '/' || c == ':' || i == s.length())
        {
            x = stod(current);
            entries[counter] = x;
            current = "";
            counter++;
        }
        else
            current = current + c;
    }
    dateType date1(entries[DAY_INDEX], entries[MONTH_INDEX], entries[YEAR_INDEX]);
    timeType time1(entries[HOUR_INDEX], entries[MIN_INDEX], entries[SEC_INDEX]);
    airQualityType airQuality1(date1, time1, entries[TEMPERATURE_INDEX],
                               entries[RELATIVE_HUMIDITY_INDEX], entries[ABSOLUTE_HUMIDITY_INDEX]);
    return airQuality1;
}