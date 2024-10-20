// Single File Programming Question
// Problem statement

// ﻿

// Design a banking system to handle account transactions. The system should allow users to deposit and withdraw money from their accounts. Each account is associated with an account holder's name, account number, and balance. 



// Implement the system using a union named AccountData that contains a structure with fields for the account holder's name, account number, and balance. 

// Input format :
// The first line consists of the account holder's name as a string.

// The second line consists of the account number as an integer.

// The third line consists of the initial balance as a double value.

// The fourth line consists of the amount to deposit as a double value.

// The fifth line consists of the amount to withdraw as a double value.

// Output format :
// The first line of output prints "Amount deposited successfully." after processing the deposit.

// The second line of output prints:

// "Amount withdrawn successfully." if the withdrawal is successful.
// "Insufficient balance. Withdrawal failed." if the balance is insufficient.
// The third line of output prints "Account details:".

// The fourth line of output prints "Account holder's name: <name>", where <name> is the account holder's name.

// The fifth line of output prints "Account number: <number>", where <number> is the account number.

// The sixth line of output prints "Balance: <balance>", where <balance> is the remaining balance after transactions, formatted to two decimal places.



// Refer to sample input and output specifications

// Code constraints :
// The account holder's name should not exceed 50 characters.

// The initial balance, deposit amount, and withdrawal amount should be non-negative double values.

// Sample test cases :
// Input 1 :
// John Doe
// 123456
// 5000
// 1000
// 500
// Output 1 :
// Amount deposited successfully.
// Amount withdrawn successfully.
// Account details:
// Account holder's name: John Doe
// Account number: 123456
// Balance: 5500.00
// Input 2 :
// Alice Smith
// 987654
// 8000
// 1500
// 10000
// Output 2 :
// Amount deposited successfully.
// Insufficient balance. Withdrawal failed.
// Account details:
// Account holder's name: Alice Smith
// Account number: 987654
// Balance: 9500.00

// You are using GCC
#include <iostream>
#include <iomanip>

using namespace std;

union AccountData{
    struct{
        char name[51];
        int accountNumber;
        double balance;
    }account;
};

int main(){
    AccountData accountdata;
    double balance=accountdata.account.balance;
    cin.getline(accountdata.account.name,51);
    // cin>>accountdata.account.name;   it will not take name after space only john
    cin>>accountdata.account.accountNumber;
    cin>>balance;
    double deposit;
    cin>>deposit;
    double withdraw;
    cin>>withdraw;
    balance+=deposit;
    cout<<"Amount deposited successfully."<<endl;
    if(balance>withdraw){
        balance-=withdraw;
        cout<<"Amount withdrawn successfully."<<endl;
    }else{
        cout<<"Insufficient balance. Withdrawal failed."<<endl;
    }
    
    cout<<"Account details:"<<endl;
    cout<<"Account holder's name: "<<accountdata.account.name<<endl;
    cout<<"Account number: "<<accountdata.account.accountNumber<<endl;
    cout<<"Balance: "<<fixed<<setprecision(2)<<balance;
}