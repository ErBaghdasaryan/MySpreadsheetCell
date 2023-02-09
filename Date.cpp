#include "Date.h"
#include <sstream>

Date::Date(int y, int m, int d){
    this->day = d;
    this->month = m;
    this->year = y;
}

Date Date::from_string(const std::string& date_string) {
    std::istringstream stream(date_string);
    char delimiter;
    int day, month, year;
    stream >> day >> delimiter >> month >> delimiter >> year;
    return Date(day, month, year);
}


int Date::getDay() const{
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

