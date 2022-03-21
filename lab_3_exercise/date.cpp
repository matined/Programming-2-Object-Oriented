#include "date.h"

#include <iomanip>
#include <iostream>
#include <string>

const int M = 12;  // number of months
static int dl[M] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static std::string names[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Date::Date(int day, int month, int year, bool format) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->format = format;
}

Date::Date(std::string date) {
    day = std::stoi(date.substr(0, 2));
    month = std::stoi(date.substr(3, 2));
    year = std::stoi(date.substr(6, 4));
}

bool Date::ifLeep() const {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

std::ostream& Date::write(std::ostream& out) const {
    if (format == false)
        out << day << "." << month << "." << year;
    else
        out << names[month - 1] << " " << day << ", " << year;
    return out;
}

std::istream& Date::read(std::istream& in) {
    std::cout << "Enter year: ";
    in >> year;
    std::cout << "Enter month: ";
    in >> month;
    std::cout << "Enter day: ";
    in >> day;

    if (!(2001 <= year <= 2100)) year = 2021;
    if (!(1 <= month <= 12)) month = 3;
    if (!(1 <= day <= dl[month - 1]) || !(ifLeep() && month == 2 && day == 29))
        day = 9;
    return in;
}

std::ostream& operator<<(std::ostream& out, Date d) {
    d.write(out);
    return out;
}

std::istream& operator>>(std::istream& in, Date d) {
    d.read(in);
    return in;
}

void Date::NextDay() {
    if (day == dl[month - 1] && !(day == 28 && month == 2 && ifLeep())) {
        day = 1;
        if (month == 12) {
            month = 1;
            year += 1;
        } else
            month += 1;
    } else
        day += 1;
}

void Date::PrevDay() {
    if (day == 1) {
        if (ifLeep() && month == 3) {
            day = 29;
        } else if (month == 1) {
            month = 12;
            day = 31;
        } else {
            day = dl[month - 1];
            month -= 1;
        }
    } else
        day -= 1;
}

void Date::SelectedDay(int days) {
    if (days > 0)
        for (int i = 0; i < days; i++) NextDay();
    else
        for (int i = 0; i > days; i--) PrevDay();
}

bool Date::ifEqual(const Date& d) const {
    if (year == d.year && month == d.month && day == d.day)
        return true;
    else
        return false;
}

bool ifLess(const Date& d1, const Date& d2) {
    if (d1.year < d2.year) return true;
    if (d1.year == d1.year && d1.month < d2.month) return true;
    if (d1.year == d1.year && d1.month == d2.month && d1.day < d2.day)
        return true;
    return false;
}

int CountDays(Date d1, Date d2) {
    int result = 0;
    if (ifLess(d1, d2)) {
        while (ifLess(d1, d2)) {
            result++;
            d1.NextDay();
        }
        return result;
    } else {
        while (ifLess(d2, d1)) {
            result++;
            d2.NextDay();
        }
        return result;
    }
}