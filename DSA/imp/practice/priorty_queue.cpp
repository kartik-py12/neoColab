//jatin 120 
//kartik 140
//shubham 130
//output first kartik then shubham then jatin acc to there marks

#include <bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin>>n;
     cin.ignore();
     priority_queue<pair<int,string>> pq;
     for(int i=0;i<n;i++){
        int marks;
        string name;
        getline(cin,name);
        cin>>marks;
        cin.ignore();
        pq.push({marks,name});
     }

     while(!pq.empty()){
        auto temp=pq.top();
        int ma=temp.first;
        string na=temp.second;
        cout<<na<<" "<<ma<<endl;
        pq.pop();
     }
}