#include <iostream>
#include <ctime>
#pragma once
using namespace std;
class Date
{
public:
  int day;
  int month;
  int year;

public:
  Date(int = 1, int = 12, int = 2020);
  friend istream &operator>>(istream &, Date &);
  friend ostream &operator<<(ostream &, const Date &);
  int getDateNow();
  int getMonthNow();
  int getYearNow();
  Date getToday();
  const Date &operator=(const Date &);
  ~Date();
};