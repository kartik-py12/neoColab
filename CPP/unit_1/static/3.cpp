// Single File Programming Question
// Problem Statement



// You are developing a module for a text-processing application that will manipulate integers. The module should provide functionalities to set an integer, count the number of digits, find the number of odd digits, and calculate the sum of odd digits in the integer.



// You are tasked with implementing an IntegerManipulator class that performs various operations on a given integer. The class should provide methods to count the number of digits, find the number of odd digits, and calculate the sum of odd digits in the integer.



// Use a Non-inline member function.



// Note: This is a sample question asked in a mPhasis interview.

// Input format :
// The input consists of an integer n.

// Output format :
// The first line displays the number of digits in the number.

// The second line displays the number of odd digits in the integer.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 109

// Sample test cases :
// Input 1 :
// 1124
// Output 1 :
// Number of digits: 4
// Number of odd digits: 2
// Input 2 :
// 2468
// Output 2 :
// Number of digits: 4
// Number of odd digits: 0

    // You are using GCC
    #include <iostream>
    #include <string>
    using namespace std;
    
    class IntegerManipulator{
        private:
            int num;

        public:
            IntegerManipulator(int n):num(n) {}
            
            int countDigits() const;
            int odd() const;    
        
    };
    
int IntegerManipulator::countDigits() const{
    int count=0;
    int temp=num;
    while(temp>0){
        temp/=10;
        count++;
    }
    return count;
}
        
int IntegerManipulator::odd() const{
    int counto=0;
    int temp=num;
    int remp=0;
    while(temp>0){
        int rem=0;
        rem=temp%10;
        if(rem%2!=0){
            counto++;
        }
        temp/=10;

    }
    return counto;
}
    
int main(){
    int n;
    cin>>n;
    
    IntegerManipulator im(n);
    cout<<"Number of digits: "<<im.countDigits()<<endl;
    cout<<"Number of odd digits: "<<im.odd()<<endl;
    
}
