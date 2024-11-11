#ifndef DATE
#define DATE

#include <iostream>

using namespace std;

class Date
{
private:
  int day;
  int month;
  int year;

  bool
  isLeapYear(int year) const
  {
    if (year % 4 == 0)
    {
      if (year % 100 == 0)
      {
        if (year % 400 == 0)
          return true;
        else
          return false;
      }
      else
        return true;
    }
    else
      return false;
  }

  int daysInMonth(int month, int year) const
  {
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return isLeapYear(year) ? 29 : 28;
    default:
      return 0;
    }
  }

public:
  Date(int d, int m, int y)
  {
    if (m < 1 || m > 12)
      cout << "Lỗi: Tháng không hợp lệ" << endl;
    if (d < 1 || d > daysInMonth(m, y))
      cout << "Lỗi: Ngày không hợp lệ" << endl;
    day = d;
    month = m;
    year = y;
  }

  int getMonth() const
  {
    return month;
  }

  void
  setDay(int d)
  {
    if (d < 1 || d > daysInMonth(month, year))
      cout << "Lỗi: Ngày không hợp lệ" << endl;
    day = d;
  }

  void
  setMonth(int m)
  {
    if (m < 1 || m > 12)
      cout << "Lỗi: Tháng không hợp lệ" << endl;
    month = m;
    if (day > daysInMonth(month, year))
      cout << "Lỗi: Ngày không hợp lệ" << endl;
  }

  void
  setYear(int y)
  {
    year = y;
    if (day > daysInMonth(month, year))
      cout << "Lỗi: Ngày không hợp lệ" << endl;
  }

  void
  addDays(int days)
  {
    day += days;
    while (day > daysInMonth(month, year))
    {
      day -= daysInMonth(month, year);
      month++;
      if (month > 12)
      {
        month = 1;
        year++;
      }
    }
  }

  void
  subtractDays(int days)
  {
    day -= days;
    while (day < 1)
    {
      month--;
      if (month < 1)
      {
        month = 12;
        year--;
      }
      day += daysInMonth(month, year);
    }
  }

  Date
  operator+(int days) const
  {
    Date newDate = *this;
    newDate.addDays(days);
    return newDate;
  }

  Date
  operator-(int days) const
  {
    Date newDate = *this;
    newDate.subtractDays(days);
    return newDate;
  }

  bool
  operator==(const Date &other) const
  {
    return day == other.day && month == other.month && year == other.year;
  }

  friend ostream &
  operator<<(ostream &os, const Date &date)
  {
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
  }
};

#endif
