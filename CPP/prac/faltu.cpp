#include <iostream>
using namespace std;
#include <string>

void car(int model){
    cout<<++model;
}

int main(){
    int carmodel=5;
    car(carmodel);
    cout<<carmodel;
    return 0;
}