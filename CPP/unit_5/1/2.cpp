// Single File Programming Question
// Problem Statement



// Nila is tasked with developing a program to determine if a given string is a palindrome and display its reversed version. A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward (ignoring spaces, punctuation, and capitalization).



// The program should finally display the result, indicate whether the input string is a palindrome, and print the reversed version of the input string.



// Your task is to implement the isPalindrome and reverseString functions as provided in the given code and design the main function to fulfill the requirements of the palindrome-checking program. Properly manage memory allocation and deallocation to avoid memory leaks and ensure that the program handles strings of various lengths correctly.

// Input format :
// The input consists of a string.

// Output format :
// The output displays whether the input string is a palindrome or not.

// If the input string is a palindrome, the program should display the message: "The input string is a palindrome."

// If the input string is not a palindrome, the program should display the message: "The input string is not a palindrome."

// The program should also display the reversed version of the input string on a separate line, preceded by the message: "Reversed string: [Reversed String]"



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input string should be up to 100 characters long, including spaces and other special characters.

// The input string may contain uppercase and lowercase letters, spaces, punctuation, and numbers.

// Sample test cases :
// Input 1 :
// radar
// Output 1 :
// The input string is a palindrome.
// Reversed string: radar
// Input 2 :
// 12321
// Output 2 :
// The input string is a palindrome.
// Reversed string: 12321
// Input 3 :
// Testing 1 2 3 testing
// Output 3 :
// The input string is not a palindrome.
// Reversed string: gnitset 3 2 1 gnitseT

// You are using GCC
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int newdelete;
    string n;
    getline(cin,n);
    vector<char>arr;
    for(int i=n.length()-1;i>=0;i--){

        arr.push_back(n[i]);
    }
    int count=0;
    for(int i=0;i<n.length();i++){
        if(arr[i]==n[i]){
            count++;
        }
    }
    if(count==n.length()){
        cout<<"The input string is a palindrome."<<endl;
        cout<<"Reversed string:";
        for(char ele:arr){
            cout<<ele;
        }
    }else{
        cout<<"The input string is not a palindrome."<<endl;
        cout<<"Reversed string: ";
        for(char ele:arr){
            cout<<ele;
        }
    }
    
}

