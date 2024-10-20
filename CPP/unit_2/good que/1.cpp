//double pointer to pointer


// Single File Programming Question
// Problem Statement



// Saru is analyzing product data and needs to count the vowels in a string of characters provided by the user. Your task is to write a program that counts the number of vowels in the input string using pointer to pointer concept.

// Input format :
// The input consists of characters one by one, separated by spaces.

// The input terminates when -1 is entered.

// Output format :
// The output prints the total number of vowels in the entered characters.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// The input string will not exceed 1000 characters in length.

// The input can contain spaces, lowercase alphabets, and the termination sequence -1.

// Sample test cases :
// Input 1 :
// a b c d e f g h i j -1
// Output 1 :
// 3
// Input 2 :
// v h l -1
// Output 2 :
// 0

// You are using GCC
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void count(char **str,int &vowel){
    char *ptr=*str;
    while(*ptr!='\0'){
        char ch=*ptr;
        ch=tolower(ch);

        if(ch=='a'||ch=='e'||ch=='o'||ch=='u'||ch=='i'){
            vowel++;
        }
        ptr++;
    }
}

int main(){
    char *input=new char[1000];
    char **str=&input;
    
    int index=0;
    char ch;
    while(cin>>ch && ch!='-'){
        input[index]=ch;
        index++;
    }
    input[index]='\0';
    
    cin.ignore();
    cin.get(ch);
    
    int vowel=0;
    count(str,vowel);
    
    cout<<vowel;
    
    delete[] input;
    return 0;
}