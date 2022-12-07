// DATE CLASS PROJECT
// OUMAR BARRY
// PROF YOUNES BENKARROUM
// CSC 211
// BMCC
// SPRING 2021
// 05 / 17 / 2021
//--------------------------

#include <iostream>
#include <stdlib.h>
#include "Date.h"

using namespace std;

void displayMenu();

int main() {

  // Create variables
  Date dateObj1, dateObj2, diff;
  int d, d1, m, m1, y, y1, nDays;
  char ans;

  // Do while loop that iterates and shows the menu
  // as long as the the user does not decide to end the program
  do{

    displayMenu();
    cin >> ans;

    // getting input from user
    while(toupper(ans) <'A' || toupper(ans)>'L'){
      cout <<"Please make a choice in the range from A to L: ";
      cin >> ans;
    }

    switch(ans){
      
      case'a':
      case'A': system("clear"); // This functions clears the output console 
        cout << "Enter a year : ";
        cin >> y;
        //input validation for year
        while(y<1753){
          cout << "Year should not be greater than 1753, please enter a valid year :";
          cin >> y;
        }
        dateObj1.setYear(y);

        cout << "Enter a month: ";
        cin >> m;
        
        //input validation for month
        while(m>12||m<1){
          cout<<"Month should be between 1 and 12. Please enter a valid month: ";
          cin>>m;
        }
        dateObj1.setMonth(m);

        cout << "Enter a day : ";
        cin >> d;

        // input validation for day

        // if january / march / may / july / august / october and december
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
          while(d>31||d<1){
            cout<<"Day should be between 1 and 31. Please Enter a valid day: ";
            cin>>d;
          }
        }

        // if april/ june / september and november
        else if(m==4||m==6||m==9||m==11){
          while(d>30 || d<1){
            cout<<"Day should be between 1 and 30. Please Enter a valid day: ";
            cin>>d;
          }
        }

        // case of february with leap year
        else if(m == 2){
          if ((y%400==0)||((y%4==0)&&(y%100!=0))){
            while(d>29 || d<1){
              cout << "Day should be between 1 and 29. Please enter a valid day: ";
              cin >> d;
            }
          }
          
          else{
            while(d>28 || d<1){
              cout << "Day should be between 1 and 28. Please enter a valid day: ";
              cin >> d;
            }
          }
        }
        
        dateObj1.setDay(d);
        cout << "Date Updated !\n\n";
        break;
      
      case 'b':
      case 'B': system("clear");
        dateObj1.printDate();
        cout << endl << endl;
        break;
      
      case 'c':
      case 'C': system("clear");
        dateObj1.printDate2();
        cout << endl << endl;
        break;

      case 'd':
      case 'D': system("clear");
        cout <<"How many days would you like to add to the date ? ";
        cin >> nDays;
        dateObj1.addDays(nDays);
        cout << endl << nDays << " days from now, the date will be ";
        dateObj1.printDate2();
        cout << endl << endl;
        break;
      
      case 'e':
      case 'E': system("clear");
        cout << "How many days would you like to substract from the date ? ";
        cin >> nDays;
        dateObj1.SubstractDays(nDays);
        cout << endl << nDays << " days ago, the date was ";
        dateObj1.printDate2();
        cout << endl << endl;
        break;

      case 'f':
      case 'F': system("clear");
        dateObj1.daysRemaining();
        cout << endl << endl;
        break;

      case 'g':
      case 'G': system("clear");
        dateObj1.passedDays();
        cout << endl << endl;
        break;

      case 'h':
      case 'H': system("clear");
        cout << "Enter a year : ";
        cin >> y;
        while(y<1753){
          cout << "Year should not be greater than 1753, please enter a valid year :";
          cin >> y;
        }
        dateObj2.setYear(y);

        cout << "Enter a month: ";
        cin >> m;
        while(m>12||m<1){
          cout<<"Month should be between 1 and 12. Please enter a valid month: ";
          cin>>m;
        }
        dateObj2.setMonth(m);

        cout << "Enter a day : ";
        cin >> d;
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
          while(d>31||d<1){
            cout<<"Day should be between 1 and 31. Please Enter a valid day: ";
            cin>>d;
          }
        }
        else if(m==4||m==6||m==9||m==11){
          while(d>30 || d<1){
            cout<<"Day should be between 1 and 30. Please Enter a valid day: ";
            cin>>d;
          }
        }
        else if(m == 2){
          if ((y%400==0)||((y%4==0)&&(y%100!=0))){
            while(d>29 || d<1){
              cout << "Day should be between 1 and 29. Please enter a valid day: ";
              cin >> d;
            }
          }
          
          else{
            while(d>28 || d<1){
              cout << "Day should be between 1 and 28. Please enter a valid day: ";
              cin >> d;
            }
          }
        }
        
        dateObj2.setDay(d);
        diff = dateObj1 - dateObj2; // calling the operator -
        d1 = diff.getDay(); // getting the difference of days
        m1 = diff.getMonth(); // getting the difference of months
        y1 = diff.getYear(); // getting the difference of years

        // this function converts the date difference in days and return the number of days
        nDays = diff.convertToDays(d1, m1, y1);

        cout << "The date entered will be reached in " << nDays << " days !\n\n";
        break;

      case 'i':
      case 'I': system("clear");
        dateObj1++;
        cout << "The date has been incremented!\n";
        cout << "The next day will be:\n";
        dateObj1.printDate2();
        cout << endl << endl;
        break;
      
      case 'j':
      case 'J': system("clear");
        // in case the user decides to decrement bellow the january 1st 1753
        if((dateObj1.getYear()==1753) && (dateObj1.getDay()==1) && (dateObj1.getMonth()==1))
           cout<<"Date could not be decremented!\n";
        
        else{
          d1--;
          cout << "The date has been decremented!\n";
          cout<<"The previous day was:\n";
          dateObj1.printDate2();
        }
        cout << endl << endl;
        break;

      case 'k':
      case 'K': system("clear");

        dateObj1.setDay(1);
        dateObj2.setMonth(1);
        dateObj1.setYear(1753);

        cout<<"What month would you like to display? ";
        cin>>m;
        while(m>12||m<1){
          cout<<"Month should be between 1 and 12. Please enter a valid month: ";
          cin>>m;
        }
        dateObj1.setMonth(m);

        cout << "Select the year: ";
        cin >> y;

        while(y<1753){
          cout << "Year should not be greater than 1753, please enter a valid year :";
          cin >> y;
        }
        dateObj1.setYear(y);

        cout << endl << endl;
        dateObj1.printCalender();
        cout << endl << endl;
        break;    
    }
  }while(toupper(ans)!='L');

  cout <<"\n\nYou have now exit the calendar. Goodbye!" << endl;
  
  return 0;
}

// this function just prints the menu on the screen
void displayMenu(){
  
    cout<<"-------------------------------------------------------\n";
    cout<<"             CALENDAR APPLICATION MENU\n";
    cout<<"-------------------------------------------------------\n";
    cout<<"A) Set Date\n";
    cout<<"B) Display Date (mm-dd-yyyy)\n";
    cout<<"C) Display Date (Weekday, Month, Day, Year)\n";
    cout<<"D) Display Future Date\n";
    cout<<"E) Display Previous Date\n";
    cout<<"F) Number Of Days Remaining In Current Year\n";
    cout<<"G) Number Of Days Passed In Current Year\n";
    cout<<"H) Compare Dates\n";
    cout<<"I) Increment Current Date\n";
    cout<<"J) Decrement Current Date\n";
    cout<<"K) Display Monthly Calendar\n";
    cout<<"L) Exit The Calendar\n\n";
    cout<<"Enter your choice: ";
}

//end of the program