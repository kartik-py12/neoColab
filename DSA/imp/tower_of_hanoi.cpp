#include<bits/stdc++.h>
using namespace std;

void toh(int n,char from,char to,char help){
    if(n>0){
        toh(n-1,from,help,to);
        cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(n-1,help,to,from);
    }
}

int main(){
    int n;
    cin>>n;
    toh(n,'A','C','B');
}

