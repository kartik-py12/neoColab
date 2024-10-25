//

#include <bits/stdc++.h>
using namespace std;

class mystack{
    int max;
    int top;
    vector<int>arr;

    public:
        mystack(int n):max(n),top(-1){}

        void push(int x){
            arr.push_back(x);
            top++;
        }

        void pop(){
            
        }

        int display(){
            if(top<0){
                cout<<"No students available for Interviews"<<endl;
                return 0;
            }
            for(int ele:arr){
                cout<<ele<<" ";
            }cout<<endl;
        }
};


int main(){
    int n;
    cin>>n;
    mystack s1(n);
    while(n!=4){
        if(n==1){
            int id;
            int status;
            cin>>id>>status;
            if(status==1){
                s1.push(id);
            }
        }else if(n==2){
            s1.pop();
        }else if(n==3){
            s1.display();
        }else{
            cout<<"Invalid option"<<endl;
        }
        cin>>n;
    }
}