// Single File Programming Question
// Problem Statement



// Manish needs a Counter class to track player scores in a game. The class should use a default constructor to initialize the score to 0, provide a method to set an initial score, increment the score, and return the current score. Ensure that after creating an instance with the default constructor, the initial value can be set and verified.

// Input format :
// The first line of input consists of an integer, N representing the initial value for the counter.

// The second line of input consists of an integer 'random' that increments N.

// Output format :
// The first line of output prints the initial value.

// The second line of output prints the incremented value.



// Refer to the sample output for formatting specifications.

// Code constraints :
// -107 ≤ N, random integer ≤ 107

// Sample test cases :
// Input 1 :
// 1
// 100
// Output 1 :
// 1
// 101
// Input 2 :
// -5070
// 777
// Output 2 :
// -5070
// -4293


// You are using GCC
#include <iostream>
using namespace std;

class Counter{
    private :
        int score;

    public:
        int result=0;
        Counter():score(0){}
        
        void setscore(int uscore){
            score=uscore;
        }
        
        void currentscore(int nscore){
            // score+=nscore;
            result=nscore+score;
        }
        
        void display(){
            cout<<score<<endl;
            cout<<result;
        }
};

int main(){
    int uscore,nscore;
    cin>>uscore;
    cin>>nscore;
    Counter c1;
    c1.setscore(uscore);
    c1.currentscore(nscore);
    c1.display();
    
}
