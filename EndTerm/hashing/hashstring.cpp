// Single File Programming Question
// Problem Statement



// Rekha is exploring string hashing techniques and wants to implement a basic string (vehicle names) hashing program. 



// She needs your help to design this program. The program should calculate a hash value for each input string using a hashing function and print the hash values until she decides to exit.



// Note

// hashValue = (hashValue * 31) + ch, where 'ch' represents the integer value of the character.
// hashValue% HASH_TABLE_SIZE is an operation involving the modulo operator (%).
// Input format :
// The input consists of strings of vehicle names, separated by a line.

// The input continues until Rekha enters 'exit' as a string, indicating the end of the input.

// Output format :
// For each input string (excluding 'exit'), the output displays an integer, which is the hash value.

// The hash values are printed as one per line.

// Code constraints :
// Hash table size = 100

// Length of the string = 100 characters

// Each input string consists of lowercase and uppercase letters

// Sample test cases :
// Input 1 :
// Van
// exit
// Output 1 :
// 63
// Input 2 :
// Bus
// Car
// Van
// exit
// Output 2 :
// 68
// 8
// 63


// You are using GCC
#include <bits/stdc++.h>
#define HASH_TABLE_SIZE 100
using namespace std;

unsigned int customHash(string key) {
    //Type your code here
    unsigned int hashVal=0;
    for(char ch:key){
        hashVal=(hashVal*31)+ch;
    }
    return hashVal%HASH_TABLE_SIZE;
}

int main() {
    //Type your code here
    string s;
    cin>>s;
    while(s!="exit"){
        cout<<customHash(s)<<endl;
        cin>>s;
    }    
    return 0;
}