#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;
    while(true){
        int ele;
        cin>>ele;
        if(ele==-1){
            break;
        }
        arr.push_back(ele);
    }
    int max=101;
    bool found =false;
    for(int ele:arr){
        if(ele%2==0  && ele<max){
            max=ele;
            found =true;
        }
    }
    if(!found){
        cout<<"No even number found";
    }else{
    cout<<max<<endl;
    }
}