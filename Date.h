//guards for the class
#ifndef DATE_H
#define DATE_H


class Date{

  private :
  
  // Member variables
  int month;
  int day;
  int year;

  public :

  //default constructor
  Date();

  // mutators
  void setMonth(int m) {month = m;}
  void setDay(int d) {day = d;}
  void setYear(int y) {year = y;}

  // accessors
  int getMonth() {return month;}
  int getDay() {return day;}
  int getYear() {return year;}

  // Overloaded operator functions
  Date operator-(Date &);
  Date operator++(int);
  Date operator++();
  Date operator--(int);
  Date operator--();

  // Extra member functions
  void printDate();
  std::string dayName(int, int, int);
  void printDate2();
  bool isALeapYear(int);
  Date addDays(int d);
  Date SubstractDays(int);
  bool isValid(int, int, int);
  int convertToDays(int d, int m, int y);
  int tomohikoSakamoto();
  void daysRemaining();
  void passedDays();
  void printCalender();

};

#endif