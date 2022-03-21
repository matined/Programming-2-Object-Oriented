#pragma once

#include <string>

class Date {
    int day;
    int month;
    int year;

    bool format;

    bool ifLeep() const;

    std::ostream& write(std::ostream& out) const;
    std::istream& read(std::istream& in);

   public:
    bool& SetFormat() { return format; }

    Date(int day = 9, int month = 3, int year = 2021, bool format = false);
    Date(std::string date);

    void NextDay();
    void PrevDay();
    void SelectedDay(int days = 7);

    bool ifEqual(const Date& d) const;

    friend bool ifLess(const Date& d1, const Date& d2);
    friend int CountDays(Date d1, Date d2);

    friend std::ostream& operator<<(std::ostream& out, Date d);
    friend std::istream& operator>>(std::istream& in, Date d);
};
