#include <bits/stdc++.h>
using namespace std;


void toh(int n,char from,char to,char with){
    if(n>0){
        toh(n-1,from,with,to);
        cout<<"Moved disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(n-1,with,to,from);
    }
}


int main(){
    int n;
    cin>>n;
    toh(n,'A','C','B');

}