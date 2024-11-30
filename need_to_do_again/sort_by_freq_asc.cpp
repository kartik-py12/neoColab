// Single File Programming Question
// Problem Statement



// Raj wants to learn a sequence of integers. His task is to count the frequency of each unique integer in the sequence and then sort them based on their frequencies in ascending order. If two integers have the same frequency, sort them in ascending order of their values.



// For this goal, your task is to implement the logic of the merge sort and a recursive function.



// Example 1



// Input: 

// nums = {1, 1, 2, 2, 2, 3}

// Output: 

// {3,1,1,2,2,2}

// Explanation: 

// '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.



// Example 2

// Input: 

// nums = {3, 2, 1, 3, 2}

// Output: 

// {1,2,2,3,3}

// Explanation: 

// '3' and '2' both have a frequency of 2, so they are sorted based on their actual values, with the smaller value coming first.

// Input format :
// The first line of input contains an integer, n, representing the number of integers in the sequence.

// The second line of input contains n space-separated integers, nums[i], representing the elements of the sequence.

// Output format :
// The output displays a single line containing the sorted integers separated by space according to their frequencies and values.

// Code constraints :
// 1 <= n <= 25

// 1 <= nums[i] <= 100

// Sample test cases :
// Input 1 :
// 6
// 1 1 2 2 2 3
// Output 1 :
// 3 1 1 2 2 2 
// Input 2 :
// 5
// 3 2 1 3 2
// Output 2 :
// 1 2 2 3 3 

// You are using GCC
//62
//72


#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    map<int,int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        auto it=arr.find(a);
        if(it!=arr.end()){
            arr[a]++;
        }else{
        arr.insert({a,1});
        }
    }
    
    vector<pair<int,int>> freq(arr.begin(),arr.end());
    sort(freq.begin(),freq.end(),compare);
    
    for(auto it:freq){
        for(auto i=0;i<it.second;i++){
            cout<<it.first<<" ";
        }
    }
    
}