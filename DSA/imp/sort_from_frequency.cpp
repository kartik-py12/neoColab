// Single File Programming Question
// Problem Statement



// You are working for an e-commerce company that wants to analyze customer purchase data. The company is interested in understanding the frequency of items purchased by customers and then displaying these items sorted by their purchase frequency. If two items have the same frequency, the item with the higher value should come first in the output.



// Given a list of purchased items, your task is to count the frequency of each item and then sort these items based on their frequency in descending order using the merge sort algorithm. If two items have the same frequency, sort them in descending order based on their values.



// Example

// Input

// 6

// 1 1 2 3 3 3

// Output 

// 3 3 3 1 1 2 

// Explanation

// Item 3 appears the most frequently (3 times), so it comes first.
// Item 1 appears next (2 times).
// Item 2 appears last (1 time).
// Each item is repeated according to its frequency, and the overall ordering is consistent with the frequency and value sorting criteria.

// Input format :
// The first line of input contains an integer n, the number of items purchased.

// The second line contains n integers where each integer represents an item purchased.

// Output format :
// The output displays the items in a single line separated by spaces. The output should display items sorted first by their frequency (in descending order), and for items with the same frequency, by their values (also in descending order).

// Code constraints :
// max_n = 100

// 1 ≤ n ≤ 25

// 1 <= arr[i] <= 100

// Sample test cases :
// Input 1 :
// 6
// 1 1 2 3 3 3
// Output 1 :
// 3 3 3 1 1 2 
// Input 2 :
// 7
// 2 2 3 1 3 2 3
// Output 2 :
// 3 3 3 2 2 2 1 
// Input 3 :
// 6
// 1 2 3 1 2 3
// Output 3 :
// 3 3 2 2 1 1 



// You are using GCC
#include <bits/stdc++.h>
using namespace std;

bool customSort(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second){
        return a.first>b.first;
    }else{
        return a.second>b.second;
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    
    unordered_map<int,int>freq;
    
    for(int ele:arr){
        freq[ele]++;
    }
    
    vector<pair<int,int>> freqVector(freq.begin(),freq.end());
    
    sort(freqVector.begin(),freqVector.end(),customSort);
    
    for(auto &p :freqVector){
        for(int i=0; i<p.second; i++){
            cout<<p.first<<" ";
        }
    }
}