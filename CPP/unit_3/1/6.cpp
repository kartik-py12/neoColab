// Single File Programming Question
// Problem Statement



// Tisha wants to write a program that welcomes a person and says hello to them. 



// Program Approach



// The user must enter the name of the person. 
// It should then create objects of the classes Welcome and Hello, which have default constructors to print "Welcome" and "Hello" respectively. 
// Finally, the program should display the person's name after each greeting.


// Company Tags: Deloitte 

// Input format :
// The input consists of the name as a string.

// Output format :
// The output displays the messages "Welcome " and "Hello " followed by the person's name entered by the user and separated by a newline.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// Length of string ≤ 20 characters

// Sample test cases :
// Input 1 :
// John
// Output 1 :
// Welcome John
// Hello John


// You are using GCC
#include <iostream>
#include <string>
using namespace std;

class Welcome{
    private:
        string name;
    public:
        Welcome(string n):name(n){
            cout<<"Welcome "<<name<<endl;
        }
};

class Hello : public Welcome{
    private:
        string name;
    public:
        Hello(string n):Welcome(n),name(n){
            cout<<"Hello "<<name;
        }
};

int main(){
    string name;
    cin>>name;
    Hello hello(name);
}