// Single File Programming Question
// Problem Statement



// Mukesh has a certain number of employees, and he wants to record their names and attendance status for a particular day. Each employee can either be "Present" or "Absent." Mukesh also prefers to use pointers to data members to manage the attendance data. Help him with a suitable program.

// Input format :
// The first line contains an integer, MAX_EMPLOYEES, representing the maximum number of employees.

// For each employee (up to MAX_EMPLOYEES employees):

// The input contains a string representing the employee's name. and an integer attendance status (0 for absent or 1 for present), separated by a space.

// Output format :
// The output will be the attendance report.

// For each employee, it will display their name followed by a colon (:) and their attendance status (Present or Absent).



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ MAX_EMPLOYEES ≤ 10

// The name of each employee will be a string of alphanumeric characters without any spaces.

// Attendance status 0 absent and 1 present

// Sample test cases :
// Input 1 :
// 3
// John 1
// Alice 0
// Bob 1
// Output 1 :
// Attendance Report:
// John: Present
// Alice: Absent
// Bob: Present

// You are using GCC
#include <iostream>
using namespace std;

#define Max_Employees 10

struct Employee{
    string name;
    int attendance;
};

int main(){
    int n;
    cin>>n;
    if( n>Max_Employees ){
        cout<<"limit excceded";
        return 1;
    }
    Employee employee[n];
    for(int i=0;i<n;i++){
        cin>>employee[i].name>>employee[i].attendance;
    }
    cout<<"Attendance Report:"<<endl;
    
    // without pointer
    
    
    // for(int i=0;i<n;i++){
    //     if(employee[i].attendance==1){
    //         cout<<employee[i].name<<": Present"<<endl;
    //     }else{
    //         cout<<employee[i].name<<": Absent"<<endl;
    //     }
    // }
    
    
    //with pointer
    for(int i=0;i<n;i++){
        Employee *ptr =&employee[i];
        cout<<ptr->name<<": "<< (ptr->attendance==1 ? "Present":"Absent")<<endl;
    }
    
    
    
}