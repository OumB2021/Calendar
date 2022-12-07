#include <iostream>
#include <cmath>
#include "Date.h"

using namespace std;

// constants global variables
const int DAYS = 7;
const int MONTHS = 12;
int months[MONTHS] ={31,28,31,30,31,30,31,31,30,31,30,31};
const string week[DAYS] = {"Sunday", "Monday", "Tuesday","Wednesday", 
                           "Thursday", "Friday", "Saturday"};

const string monthName[MONTHS] = {"January", "February", "March", "April",
                                  "May", "June", "July", "August", "September", 
                                  "October", "November", "December"};

// This function checks whether or not the year is a leap year
bool Date :: isALeapYear(int y){
  if((y%400==0)||((y%4==0)&&(y%100!=0)))
  return true;
  else
  return false;
}

// default constructor
Date::Date(){

  month = 1;
  day = 1;
  year = 1753;
}

//This function prints the date with different format
void Date::printDate(){

  if (month < 10 && day < 10){
    cout << "Date: " << "0" << month << "/0" << day <<"/"<< year;
  }

  else if (month > 10 && day < 10){
    cout << "Date: " << month <<"/0"<<day<<"/"<<year; 
  }

  else if (month < 10 && day > 10){
    cout << "Date: " << "0" << month << "/" << day << "/"<< year;
  }

  else{
    cout << "Date: " << month << "/" << day << "/" << year;
  }
}

//This function converts a given date into days
int Date::convertToDays (int d, int m, int y){
  int leapYearDays;
  int Days = 0;
  for (int i = 0; i < y; i++){
    for(int j= 0; j < 12; j++){
      Days += months[j];
    }
  }

  for (int i = 0; i < m; i++)
    Days += months[i];
  
  Days += d;
  leapYearDays = y /4;
  Days += leapYearDays;

  return Days;
}

// Overloading the - operator
Date Date :: operator-(Date &right){

  Date temp;

  // Computations if two similar dates are subtracted to one another.
  if(right.year == this -> year && right.month == this -> month && right.day == this -> day){
    temp.day=0;
    temp.month=0;
    temp.year=0;
    return temp;
  }
  
  //Computations if the object passed as an argument has greater values
  else if (right.year > this -> year && right.month > this -> month && right.day > this -> day){
    temp.day = right.day - this -> day;
    temp.month = right.month - this -> month;
    temp.year = right.year - this -> year;
    return temp;
  }

  // Computations if the days are equal to each other
  else if (right.day == this -> day){
    if (right.month == 1){
      right.day += 31;
      right.month = 12;
      right.year--;   
    }

    // If the last day of march is reached
    // the leap year test will run
    else if (right.month == 3){
      if (isALeapYear(right.year)){
        right.day += 29;
        right.month--;
      }
      else{
        right.day += 28;
        right.month--;
      }
    }

    // If the end of the month with 30 days is reached
    else if (right.month == 4 || right.month == 6 || right.month == 9 || right.month == 11){
      right.day += 31;
      right.month--;
    }

    // If the end of the month with 31 days is reached
    else if(right.month == 5 || right.month == 7 || right.month == 8 || right.month == 10|| right.month == 12){
      right.day += 30;
      right.month--; 
    }

    temp.day = right.day - this -> day;
    temp.month = right.month - this -> month;
    temp.year = right.year - this -> year;

    return temp; 
  }

  // If the calling object's date is not greater than the year
  else if (right.year > this -> year){
    if (right.day > this -> day)
      temp.day = right.day - this-> day;
    else{
      if (right.month == 4 || right.month == 6 || right.month == 9 || right.month == 11){
        right.day += 31;
        right.month--; 
      }

      else if (right.month == 1 || right.month == 5 ||
      right.month == 7 || right.month == 8||right.month == 10|| right.month == 12){
            right.day += 30;
            right.month -=1; 
          }
      
      else if(right.month == 3){
        if(isALeapYear(right.year))
        right.day += 29;
        else
        right.day += 28;
        right.month -=1;
      }
    }

    if (right.month > this -> month)
      temp.month = right.month - this-> month;
    else{
      right.month += 12;
      right.year--;
    }

  }

  else if (right.year < this -> year){
    if (right.day < this -> day)
      temp.day = this-> day - right.day;
    else{
      if (this -> month == 4 || this ->month == 6 || this ->month == 9 || this ->month == 11){
        this ->day += 31;
        this ->month--; 
      }

      else if (this ->month == 1 || this ->month == 5 ||
      this ->month == 7 || this ->month == 8 || this ->month == 10|| this ->month == 12){
            this ->day += 30;
            this ->month -=1; 
          }
      
      else if(this ->month == 3){
        if(isALeapYear(this ->year))
        this ->day += 29;
        else
        this ->day += 28;
        this ->month -=1;
      }
    }

    if (right.month < this -> month)
      temp.month = this-> month - right.month;
    else{
      this ->month += 12;
      this ->year--;
    }

  }

  temp.day = abs(right.day - this -> day);
  temp.month = abs(right.month - this -> month);
  temp.year = abs(right.year - this -> year);
  
  return temp;
}

// Overloading the ++ postfix operator
Date Date :: operator++(int){

  day++;
  
  // for the months that have 31 days, the incrementation will set the day to the first
  // and increment the month to 1
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
    if(day == 32){
      day = 1;
      month++;
    }
  }

  // if the last day of the year is reached, the we start another new year again
  else if(month == 12 && day == 32){
    day = 1;
    month = 1;
    year++;
  }

  // for the months that have 30 days, the incrementation will set the day to the first
  // and increment the month to 1 
  else if (month == 4 || month == 6 || month == 9 || month == 11){
    if (day == 31){
      day = 1;
      month++;
    }
  }

  // In a case where we're dealing with february
  else if (month == 2 && day == 30){

    if (isALeapYear(year)){
      day = 1;
      month++;
    }
    else{
      day = 2;
      month++;
    }
  }
  return *this;
} 

// Overloading the ++ prefix operator
Date Date :: operator++(){

  day++;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
    if(day == 32){
      day = 1;
      month++;
    }
  }
  else if(month == 12 && day == 32){
    day = 1;
    month = 1;
    year++;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11){
    if (day == 31){
      day = 1;
      month++;
    }
  }
  else if (month == 2 && day == 30){

    if (isALeapYear(year)){
      day = 1;
      month++;
    }
    else{
      day = 2;
      month++;
    }
  }
  return *this;
} 

// Overloading the -- postfix operator
Date Date :: operator--(int){

   if(day==1){

    // if may / july / august / october and december
    if(month==5||month==7||month==8||month==10||month==12){
      day+=29;
      month-=1;
    }
    
    // February / april / june / september and november
    else if(month==2||month==4||month==6||month==9||month==11){
    day+=30;
    month-=1;
    }

    // if end of march
    else if(month==3){
      if(year%400==0||(year%4==0 && year%100!=0)){
        day+=28;
        month-=1;
        }
      else{
        day+=27;
        month-=1;
      }
    }

    // if January
    else if(month==1){
      month+=11;
      day+=30;
      year-=1;
    }
  }
  else
    day--;
    
  return *this;
}

//Overloading the -- prefix operator
Date Date :: operator--(){
  
  
   if(day==1){

    // if may / july / august / october and december
    if(month==5||month==7||month==8||month==10||month==12){
      day+=29;
      month-=1;
    }
    
    // February / april / june / september and november
    else if(month==2||month==4||month==6||month==9||month==11){
    day+=30;
    month-=1;
    }

    // if end of march
    else if(month==3){
      if(year%400==0||(year%4==0 && year%100!=0)){
        day+=28;
        month-=1;
        }
      else{
        day+=27;
        month-=1;
      }
    }

    // if January
    else if(month==1){
      month+=11;
      day+=30;
      year-=1;
    }
  }
  else
    day--;
    
  return *this;
}

// This function checks if the date is valid.
bool Date :: isValid(int d, int m, int y) {
  // check the ranges of day, month, year
  if (d <= 0 || d > 31)
    return false;
  if (m <= 0 || m > 12)
    return false;
  if (y < 0)
    return false;
  // if the month is february
  if (m == 2) 
  {
    // if d > 29 then not valid
    if (d > 29)
      return false;
    // if not a leap year but d = 29 
    if (!isALeapYear(y) && d == 29) 
    {
      return false;
    }
  }
  // if april/june/september/november
  else if (m == 4 || m == 6 || m == 9 || m == 11) 
  {
    if (d == 31)
     return false;
  }
  // return as valid date
  return true;
}

// this function increments the day using the ++ operator
Date Date :: addDays(int d){
  for(int i=0;i<d;i++)
      operator++();
  
  return *this;
}

Date Date :: SubstractDays(int d){
  for(int i=0;i<d;i++)
      operator--();
  
  return *this;
}

//This function return the day name of a date
string Date::dayName(int d, int m, int y){

  int b=0;
  if(isALeapYear(y)){
    months[1]=29;
  }
  b=(d += m < 3 ? y--: y-2, 23*m /9+d+4+y/ 4-y/ 100+y/ 400) % 7;

  return week[b];
}

//This function prints the date with the name of the day and month included
void Date :: printDate2(){

  string name = dayName(day,month,year);
  cout << name << ", " << monthName[month-1] << " " << day << ", " << year;
}

// This function checks how many days are left before the end of the year
void Date :: daysRemaining(){
  int daysRemaining = 0;

  // if jan / march / may / july / august / october
  if (month == 1 || month == 3|| month == 5 || month == 7 || month == 8 || month == 10)
    daysRemaining = 31 - day;

  // if december
  else if (month == 12){
    daysRemaining = 31 - day;
    cout << "We have " << daysRemaining << " days until the end of the year " << year;
    return;
  }

  // february case
  else if (month == 2){
    if (isALeapYear(year))
      daysRemaining = 29 - day;
    else
      daysRemaining = 28 - day;
  }

  // if april / june / september / november
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    daysRemaining = 31 - day;

  for (int i = month; i < 12; i++)
    daysRemaining += months[i];
  
  cout << "We have " << daysRemaining << " days until the end of the year " << year;
}

// This function checks how many days have passed in the current year
void Date :: passedDays(){

  int daysPassed = 0;

  // if it is January
  if (month == 1){
    if(day == 1) // first day
      cout << day << " day has passed this year " << year;
    
    else{
    daysPassed = day;
    cout << daysPassed << " days have passed this year " << year;
    return;
    }
  }
  else{

    if (isALeapYear(year))
      months[1] = 29;

    daysPassed += day - 1;

    for (int i = 0; i < month-1; i++)
      daysPassed += months[i];
    
    cout << daysPassed << " days have passed this year " << year;
  }
}

//tomohiko Sakamoto is an algorithm that returns how many days the beginning
//of the months are offset compared to January 1st of a given year;
int Date :: tomohikoSakamoto(){

  // this array represents how many days the beginning
  // of the months are offset compared to January 1st
  // Example at t[1], we see that the first day of 
  // february will have three days ahead of January 1st
  static int t[]={0,3,2,5,0,3,5,1,5,6,2,4};
  year-=month<3;

  // the value returned checks and adjust +1 to the returned value
  // after checking if the year is a leap year
  return (year+year/4-year/100+year/400+t[month-1]+day)%7;
 }

// This function prints the calender of the current month

void Date :: printCalender(){
        
  if(isALeapYear(year))
    months[1]=29;
  
  cout<<" ----------"<<monthName[month-1]<<","<<year<<"-------------- \n\n";
  cout<<"  Sun\tMon  Tue  Wed  Thu  Fri  Sat \n\n";

  int current=tomohikoSakamoto();
  int i;
  for (i = 0; i < current; i++)
    cout << "     ";
  for (int j = 1; j <= months[month-1]; j++){
    printf("%5d", j);
    if (++i > 6){
      i = 0;
      printf("\n");
    }
  }
  if (i)
    printf("\n");
    
    current = i;

  return;
}