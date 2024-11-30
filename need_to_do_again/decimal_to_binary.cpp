#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        stack<int>q;
        int temp=i;
        while(temp>0){
            int rem=temp%2;
            q.push(rem);
            temp/=2;
        }
        while(!q.empty()){
            cout<<q.top();
            q.pop();
        }
        cout<<" ";
    }   
}