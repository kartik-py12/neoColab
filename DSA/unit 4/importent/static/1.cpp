// Single File Programming Question
// Problem Statement



// The Tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of disks N. Initially, these disks are in rod 1. You need to print all the steps of disk movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.



// Note: The disks are arranged such that the top disk is numbered 1 and the bottom-most disk is numbered N. Also, all the disks have different sizes, and a bigger disk cannot be put on top of a smaller disk. 

// Input format :
// The input consists of a single integer N, representing the number of disks initially placed on rod 1.

// Output format :
// The output prints a series of lines representing each move of a disk from one rod to another.

// After all moves are printed, the last line prints the total number of moves made during the Tower of Hanoi puzzle.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 8

// Sample test cases :
// Input 1 :
// 2
// Output 1 :
// move disk 1 from rod 1 to rod 2
// move disk 2 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 3
// 3
// Input 2 :
// 3
// Output 2 :
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3
// 7


// // You are using GCC
// #include <stdio.h>

// int moveDisks(int n, char source, char auxiliary, char destination) {
//     //Type your code here
    
// }

// int main() {
//     int n;
//     scanf("%d", &n);
    
//     int totalMoves = moveDisks(n, '1', '2', '3');
    
//     printf("%d\n", totalMoves);
    
//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n, int source, int destination, int auxiliary) {
    // Base case: When there are no more disks to move
    if (n == 0) {
        return;
    }

    // Recursive step: Move the top n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Move the remaining disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;

    // Recursive step: Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cin >> n;

    // Initialize the three rods
    int source = 1, destination = 3, auxiliary = 2;

    // Solve the puzzle
    towerOfHanoi(n, source, destination, auxiliary);
    
    cout<<(pow(2,n)-1);

    return 0;
}
