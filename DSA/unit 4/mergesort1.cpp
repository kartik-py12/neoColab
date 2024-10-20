// Single File Programming Question
// Problem Statement



// In a mystical land known as Eldoria, ancient wizards use magical runes to cast powerful spells. These runes are represented by single characters, each possessing a unique magical property. However, the wizards have a challenge: they need these magical runes sorted in a specific order for their spells to work correctly.



// Write a program to help the wizards of Eldoria sort their magical runes based on their potency. Each rune is represented by a single character, and each character holds a unique level of magical power, determined by its position in the ASCII table.



// Your task is to implement a merge sorting logic and recursive function to arrange these magical runes in descending order of their magical potency.

// Input format :
// The first line of input consists of an integer n, representing the number of magical runes to be sorted.

// The second line contains n space-separated characters, each representing a magical rune.

// Output format :
// The output displays a single line containing the magical runes sorted in descending order of their magical potency, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 25

// Each character in the array is a single uppercase letter or a single lowercase letter.

// Sample test cases :
// Input 1 :
// 8
// G h I J K L m n
// Output 1 :
// n m h L K J I G 
// Input 2 :
// 6
// a Z A B M Z
// Output 2 :
// a Z Z M B A 



//sorting question using # include <algorithm> sort(start,end) [without merge sort]

// You are using GCC
// #include <stdio.h>
// #include<algorithm>
// using namespace std;

// #define MAX_ARRAY_LENGTH 100

// int main() {
//     int n;
//     scanf("%d", &n);

//     char arr[n];
//     for (int i = 0; i < n; i++)
//         scanf(" %c", &arr[i]);
    
//     sort(arr,arr+n);

//     for (int i = n-1; i >= 0; i--)
//         printf("%c ", arr[i]);

//     return 0;
// }



/// with merge sort

