//tree=>eert
//aaeeeb=>eeeaab

#include <bits/stdc++.h>
using namespace std;



int main(){
    priority_queue<pair<int,char>> pq;
    string ans="";
    string name;
    getline(cin,name);
    unordered_map<char,int> freq;
    for(char ele:name){
        freq[ele]++;
    }
    vector<pair<int,char>>arrf;
    for(auto pair:freq){
        // arrf.push_back(pair.second,pair.first);
        cout<<pair.first<<" : "<<pair.second<<endl;
        pq.push({pair.second,pair.first});
    }

    while(!pq.empty()){
        auto temp=pq.top();
        int freq=temp.first;
        char ch=temp.second;

        ans+=string(freq,ch);
        pq.pop();
    }
    cout<<ans;
}