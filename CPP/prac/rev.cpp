// take a number from user like 543678 rev it sort it asc print it then print odd numbers
// sort with  Bubble sort, Insertion sort, Selection sort,
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<"reversed number"<<endl;
    vector<int>arr;
    while(n>0){
        int temp=n%10;
        cout<<temp;
        arr.push_back(temp);
        n/=10;
    }
    cout<<endl;
    cout<<"array before sorting: ";
    for(int i:arr){
        cout<<i<<" ";
    }
    

}