#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,string,greater<int>>arr;
    for(int i=0;i<n;i++){
        string s;
        int a;
        cin>>s>>a;
        
        arr.insert({a,s});
        // arr[pair].first=a;
    }

    for(auto&pair:arr){
        cout<<pair.second<<":"<<pair.first<<endl;
    }
    
}