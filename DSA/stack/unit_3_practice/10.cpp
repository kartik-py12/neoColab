// Single File Programming Question
// Problem Statement



// Samantha, a software engineer, needs to develop a function for her text editor that reverses a user-input string. She decides to use a stack using an array to accomplish this task efficiently.



// Given a string entered by the user, Samantha's program should reverse the string using a stack and then display the reversed string. For instance, if the user inputs the string "Hello World", the program should output "dlroW olleH".



// Company Tags: CTS

// Input format :
// The input consists of a string.

// Output format :
// The output prints the reversed string on a single line.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The input string consists of alphabets, numbers and special characters. The maximum length of the string is 100.

// Sample test cases :
// Input 1 :
// JNCAB
// Output 1 :
// BACNJ
// Input 2 :
// Data Structures
// Output 2 :
// serutcurtS ataD
// Input 3 :
// Hello World
// Output 3 :
// dlroW olleH


// You are using GCC
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string n;
    getline(cin,n);

    
    for(int i=n.length()-1;i>=0;i--){
        cout<<n[i];
    }
}