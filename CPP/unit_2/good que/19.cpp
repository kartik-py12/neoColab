// Single File Programming Question
// Problem Statement



// John and Michael play a game of multiplication. The game starts with an integer p initialized to 1. They take turns multiplying p by one of the numbers from 1 to 9 in a sequence. John always starts by multiplying p by 1 and then passes the result to Michael. Michael multiplies the number by 2 and passes the result back to John. John then multiplies by 3, and so on, increasing the multiplier by 1 with each turn.



// Before the game starts, they draw an integer N. The winner is the player who first reaches or exceeds p >= N during their turn. Write a class MultiplicationGame with a member function void game(int) to simulate this scenario and determine the winner.



// Example 



// Input: N=10

// Output:

// 10 Michael wins



// Explanation

// If N is 10:

// John starts with p = 1, multiplies by 1 (John's turn), resulting in p = 1.

// Michael multiplies p = 1 by 2, resulting in p = 2.

// John multiplies p = 2 by 3, resulting in p = 6.

// Michael multiplies p = 6 by 4, resulting in p = 24.

// Since 24 is greater than 10, Michael wins.



// Company Tags: Accenture 

// Input format :
// The input consists of an integer N.

// Output format :
// The output prints the value of N and the name of the winner, separated by a space.



// Refer to the sample outputs for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 20

// Sample test cases :
// Input 1 :
// 10
// Output 1 :
// 10 Michael wins
// Input 2 :
// 3
// Output 2 :
// 3 John wins


// You are using GCC
#include <iostream>
using namespace std;

class multiplicationGame{
    private:
        int n;
    public:
        multiplicationGame(int num):n(num) {}
        
        int game(){
            int p=1;
            for(int i=1;i<=n;i++){
                p*=i;

                if(p>=n){
                    if(i%2==0){
                        cout<<n<<" Michael wins";
                        return 0;
                    }
                    if(i%2!=0){
                        cout<<n<<" John wins";
                        return 0;
                    }
                }
            }
        }
};

int main(){
    int num;
    cin>>num;
    multiplicationGame mg(num);
    mg.game();
    return 0;
}