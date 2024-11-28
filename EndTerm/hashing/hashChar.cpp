// Single File Programming Question
// Problem Statement



// John is working on a data storage system that requires efficient indexing and retrieval of data using a custom hashing algorithm. 



// He is looking for assistance in designing a program to calculate hash values for given text keys. Help him solve this program using the hash function.



// Note:

// The hash value is calculated as follows:

// Initialize 'hashVal' to 0.
// For each character 'ch' in the 'text' (the ASCII value of the character),
// Update 'hashVal' using the formula: hashVal = 37 * hashVal + ch.
// Finally, return 'hashVal % tSize' as the hash index.
// Input format :
// The first line of input consists of the string text, representing the text-based key.

// The second line consists of an integer tSize, representing the size of the hash table.

// Output format :
// The output displays an integer representing the calculated hash index.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ |text| ≤ 102

// 1 ≤ tSize ≤ 109

// The text key contains lowercase and uppercase letters without any space.

// Sample test cases :
// Input 1 :
// Testing 
// 1000
// Output 1 :
// 98
// Input 2 :
// Hashfunction 
// 10000
// Output 2 :
// 2970

// You are using GCC
#include <bits/stdc++.h>
using namespace std;

unsigned int hashCalc(string key, int tableSize) {
    //Type your code here
    unsigned int hashVal=0;
    for(char ch:key){
        hashVal=37*hashVal+ch;
    }
    return hashVal%tableSize;
}

int main() {
    //Type your code here
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<hashCalc(s,n);
    return 0;
}