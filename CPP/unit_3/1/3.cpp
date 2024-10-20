// Single File Programming Question
// Problem Statement



// Meena is creating a Calendar application that uses the Date class to represent dates. The Date class has the following requirements:



// The class stores the day (dd), month (mm), and year (yy) as integer values.
// It has a constructor that initializes the date to 31st December 2022 by default.
// Another constructor allows the user to specify a custom date.
// The class has a display method to print the date in the format dd-mm-yy.


// Input Constraints:



// The day (dd) value is between 1 and 31. If invalid, it defaults to 30.
// The month (mm) value is between 1 and 12. If invalid, it defaults to 12.
// The year (yy) value is between 2023 and 2998. If invalid, it defaults to 2023.


// Write a program to fulfill these requirements.

// Input format :
// The input consists of three integers from the user representing the day (d), month (m), and year (y) respectively.

// Output format :
// The code will display two lines of output.

// The initial date in the format dd-mm-yy (before setting with user input).
// The updated date in the format dd-mm-yy (after setting with user input).


// Refer to the sample output for formatting specifications.

// Code constraints :
// The day (d) should be between 1 and 31.

// The month (m) should be between 1 and 12.

// The year (y) should be between 2023 and 2998.

// Sample test cases :
// Input 1 :
// 1 07 2023
// Output 1 :
// 31-12-2022
// 1-7-2023
// Input 2 :
// 0 14 3023
// Output 2 :
// 31-12-2022
// 30-12-2023


// You are using GCC
#include <iostream>
using namespace std;

class Date{
    private:
        int dd;
        int mm;
        int yy;
    
    public:
        Date():dd(31),mm(12),yy(2022) {}
        
        Date(int day,int month,int year){
            
            if(day>=1 && day<=31){
                dd=day;
            }else{
                dd=30;
            }
            
            if(month>=1 && month<=12){
                mm=month;
            }else{
                mm=12;
            }
            
            if(year>=2023 && year<=2998){
                yy=year;
            }else{
                yy=2023;
            }
        }
        
        void display(){
            cout<<dd<<"-"<<mm<<"-"<<yy<<endl;
        }

};


int main(){
    int day,month,year;
    cin>>day>>month>>year;
    Date autodate;
    autodate.display();
    
    Date customdate(day,month,year);
    customdate.display();
}