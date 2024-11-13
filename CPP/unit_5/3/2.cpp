// Single File Programming Question
// Problem Statement



// Tao, a game developer, is designing a new scoring system for his trivia game, where players earn points based on the letters they input. Players receive 10 points for each uppercase letter (A-Z) but lose 5 points for lowercase letters (a-z) or any other characters.



// To implement this scoring functionality, Tao will create an abstract class named Base, featuring a pure virtual function virtual void game() = 0; The derived class, Derived, will implement this function to read four characters and calculate the player's score according to the specified rules:

// For each character:

// If the character is uppercase (A-Z), add 10 to the score.
// If the character is lowercase (a-z) or any other character, subtract 5 from the score.
// Input format :
// The input consists of four characters representing a, b, c, and d, separated by a space.

// Output format :
// The output displays an integer, total score in the format: "Score: X" where X is the calculated total score based on the input characters.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The input should be a valid letter from the English alphabet (A to Z or a to z).

// Sample test cases :
// Input 1 :
// A F K R
// Output 1 :
// Score: 40
// Input 2 :
// A b D f
// Output 2 :
// Score: 10
// Input 3 :
// a b c d
// Output 3 :
// Score: -20

// You are using GCC
#include <iostream>
// #include <vector>
using namespace std;
int main(){
    char a,b,c,d;
    int score=0;
    cin>>a>>b>>c>>d;
    if(isupper(a)){
        score+=10;
    }
    if(isupper(b)){
        score+=10;
    }
    if(isupper(c)){
        score+=10;
    }
    if(isupper(d)){
        score+=10;
    }
    if(islower(a)){
        score-=5;
    }
    if(islower(b)){
        score-=5;
    }
    if(islower(c)){
        score-=5;
    }
    if(islower(d)){
        score-=5;
    }
    
    cout<<"Score: "<<score;
}