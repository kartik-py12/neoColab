// Single File Programming Question
// Problem Statement



// You are working as a program developer at a renowned sports academy. As part of the academy's performance evaluation system, you are tasked with sorting the athletes based on their heights in descending order.



// Write a program that takes an array of athlete names and their corresponding heights as input. Your program should use the quick sort algorithm to sort the athletes' names in descending order based on their heights.

// Input format :
// The first line of input consists of an integer N, representing the number of athletes.

// The following N lines consist of the athlete's name and height, separated by space.

// Output format :
// The output prints the athletes' names sorted in descending order based on their heights.

// Code constraints :
// N == names.length == heights.length

// names[i] consists of lower and upper case English letters.

// All the values of heights are distinct.

// Sample test cases :
// Input 1 :
// 6
// Mary 180
// John 165
// Emma 170
// Joey 157
// Tom 169
// Cruise 175
// Output 1 :
// Mary Cruise Emma Tom John Joey 
// Input 2 :
// 3
// Alice 155
// Bob 185
// David 150
// Output 2 :
// Bob Alice David 


#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    cin.ignore();
    priority_queue<pair<int,string>> pq;
    for(int i=0;i<n;i++){
        string name;
        int marks;
        cin>>name>>marks;
        pq.push({marks,name});
    };
    
    while(!pq.empty()){
        auto temp=pq.top();
        string name=temp.second;
        int marks=temp.first;
        cout<<name<<" ";
        pq.pop();
    }
}