#ifndef DATE_H
#define DATE_H
#include <string>


class Date {
public:
        Date(int y, int m, int d);
        ~Date()  = default;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        static Date from_string(const std::string& date_string);


private:
        int year;
        int month;
        int day;

};

#endif // DATE_H