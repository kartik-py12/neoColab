// Single File Programming Question
// Problem Statement



// You are tasked with creating a GradeBook class to automate grade storage for students. The GradeBook class should have the following features:



// Private members: courseName and instructorName with corresponding get and set methods.
// A default constructor that allows creating an object without initial values and a setData method to set courseName and instructorName.
// A displayMessage method to display the course and instructor details.
// Utilize string data types for data handling.


// The program should take input for the course name and instructor name and display them as is.

// Input format :
// The input consists of two strings: the course name and instructor name, each on a separate line.

// Output format :
// The output displays a welcome message for the grade book. The welcome message includes the course name and the instructor's name.



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ length of grade and instructor's names ≤ 100 characters

// Sample test cases :
// Input 1 :
// CS50
// David Mallon
// Output 1 :
// Welcome to the grade book for CS50!
// This course is presented by: David Mallon
// Input 2 :
// Computer Science
// Addyson David Vicente Saunders 
// Output 2 :
// Welcome to the grade book for Computer Science!
// This course is presented by: Addyson David Vicente Saunders


// You are using GCC
#include <iostream>
#include <string>
using namespace std;

class GradeBook{
    private:
        string courseName;
        string instructorName;
        
    public:
        GradeBook(){}
        
        void setData(string &course,string &instructor){
            courseName=course;
            instructorName=instructor;
        }
        
        void displayMessage(){
            cout<<"Welcome to the grade book for "<<courseName<<"!"<<endl;
            cout<<"This course is presented by: "<<instructorName;
        }
};

int main(){
    GradeBook gb;
    string course,instructor;
    getline(cin,course);
    getline(cin,instructor);
    
    gb.setData(course,instructor);
    gb.displayMessage();
}