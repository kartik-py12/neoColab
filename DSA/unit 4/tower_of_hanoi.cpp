// Single File Programming Question
// Problem Statement



// During an archaeological expedition, a team discovers the "Disk of Light," an artefact consisting of concentric rings with unique symbols. To unlock its powers, they must perform the "Tower of Wisdom" ritual.



// In this ritual:

// There are three pedestals: Source (A), Auxiliary (B), and Illuminated (C).
// Disks are stacked on the Source pedestal, smaller ones on top of larger ones.
// Only one disk can be moved at a time.
// A disk can only be placed on top of a larger disk or an empty pedestal.


// Write a program to assist the archaeological team in calculating the total number of times each ring of the Disk of Light is moved during the Tower of Wisdom ritual.



// Note: This kind of question will be helpful in clearing TCS recruitment.

// Input format :
// The input consists of an integer n denoting the number of disks.

// Output format :
// The output displays the sequence of moves required to solve the puzzle.

// The last line of output displays the total number of times the disk is moved.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 0 < n ≤ 8

// Sample test cases :
// Input 1 :
// 3
// Output 1 :
// Move disk 1 from A to C
// Move disk 2 from A to B
// Move disk 1 from C to B
// Move disk 3 from A to C
// Move disk 1 from B to A
// Move disk 2 from B to C
// Move disk 1 from A to C
// Total number of times the disk is moved: 7
// Input 2 :
// 4
// Output 2 :
// Move disk 1 from A to B
// Move disk 2 from A to C
// Move disk 1 from B to C
// Move disk 3 from A to B
// Move disk 1 from C to A
// Move disk 2 from C to B
// Move disk 1 from A to B
// Move disk 4 from A to C
// Move disk 1 from B to C
// Move disk 2 from B to A
// Move disk 1 from C to A
// Move disk 3 from B to C
// Move disk 1 from A to B
// Move disk 2 from A to C
// Move disk 1 from B to C
// Total number of times the disk is moved: 15







// You are using GCC
#include <iostream>
#include <cmath>
using namespace std;
//        n          A           B           C
int toh(int n, char from_rod,char aux_rod,char to_rod){
    if(n>0){
//  Move n-1 Discs from A to B using C
//  Fomrat is (n-1,from,using,to)
        toh(n-1,from_rod,to_rod,aux_rod);
        cout<<"Move disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
//  Format is (n-1 ,from,using,to)
//  Move n-1 Dics from B to C using A
        toh(n-1,aux_rod,from_rod,to_rod);

    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cin>>n;
    toh(n,'A','B','C');
    int count=pow(2,n)-1;
    cout<<"Total number of times the disk is moved: "<<count;
}