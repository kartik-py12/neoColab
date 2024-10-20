//print all non fibonacci element of an array given by user

#include <iostream>
using namespace std;

int binary(int arr[],int size,int key){
    int low=0;
    int high=1000;
} 

int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(arr1[i]>max){
            max=arr1[i];
        }
    }
    int a=0;
    int b=1;
    int arr[100]={0};
    arr[1]={1};
    int i=2;

    while(true){
        int c=a+b;
        a=b;
        b=c;
        if(c<1000){
            arr[i]=c;
            i++;
        }
        else{
            break;
        }

    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl;
    for(int i=0;i<n;i++){
        bool found =false;
        for(int j=0;j<max;j++){
            if(arr1[i]==arr[j]){
                found =true;
            }
        }
        if(!found){
            cout<<arr1[i]<<" ";
        }
    }
}