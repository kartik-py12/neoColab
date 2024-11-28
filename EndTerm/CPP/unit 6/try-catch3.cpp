// Single File Programming Question
// Problem Statement



// You are developing a login system for a website that requires users to provide a username and password. 



// The system has specific password requirements: it must have at least 6 characters and contain at least one digit.



// Write a program to accept username and password and throw an exception if the password has less than 6 characters or does not contain a digit.

// Input format :
// The input consists of two strings representing username and password in separate lines.

// Output format :
// The output displays whether the password is valid or not.



// Refer to the sample output for the exact text.

// Sample test cases :
// Input 1 :
// Sam
// sam123
// Output 1 :
// Password is Correct
// Input 2 :
// Sandy
// sansan
// Output 2 :
// Password must have at least one digit
// Caught by Exception 
// Invalid Password Format!
// Input 3 :
// Mano
// 2313
// Output 3 :
// Password must be at least 6 characters long
// Caught by Exception 
// Invalid Password Format!

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main(){
    string name,pass;
    cin>>name;
    cin>>pass;
    bool digit=false;
    int count=0;
    for(char c:pass){
        count++;
        if(isdigit(c)){
            digit = true;
        }
    }
    try{
        if(!digit){
            throw runtime_error("Password must have at least one digit");
        }
        else if(count<6){
            throw runtime_error("Password must be at least 6 characters long");
        }
        else{
            cout<<"Password is Correct";
        }
    }catch(runtime_error&e){
        cout<<e.what()<<endl;
        cout<<"Caught by Exception"<<endl;
        cout<<"Invalid Password Format!";
    }
}
