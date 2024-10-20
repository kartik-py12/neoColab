// Single File Programming Question
// Problem Statement



// Dhruv is a professor who wants to develop a program to manage student information using a class called Student. The program should allow Dhruv to input details about multiple students, such as their names, the number of subjects they have, and their marks in each subject. 



// To calculate and display the average marks for each student, Dhruv intends to use pointers to objects in his program. Help Dhruv to write a program.

// Input format :
// The first line of input consists of an integer n, representing the number of students.

// For each student, the following details should be entered:

// The first line of input consists of a string, representing the name of the student.
// The second line of input consists of an integer m, representing the number of subjects for that student.
// The last line of input consists of m double values, representing the marks obtained in each subject separated by space.
// Output format :
// For n students, the program should display the following for each student:

// The first line of output displays the name of the student.
// The next line of output displays the average marks obtained by the student as a double value rounded off to two decimal places.


// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// 1 ≤ m ≤ 10

// 1.0 ≤ marks ≤ 100.0

// Sample test cases :
// Input 1 :
// 3
// John Doe
// 5
// 80.5 90.0 75.5 85.0 92.0
// Jane Smith
// 4
// 88.0 92.5 76.0 85.5
// Alice Johnson
// 3
// 70.0 65.5 80.0
// Output 1 :
// Student Details:
// Name: John Doe
// Average marks: 84.60
// Name: Jane Smith
// Average marks: 85.50
// Name: Alice Johnson
// Average marks: 71.83
// Input 2 :
// 2
// Pinky 
// 3 
// 98.0 76.0 43.0
// Rosy
// 4
// 98.0 61.0 54.0 37.0
// Output 2 :
// Student Details:
// Name: Pinky 
// Average marks: 72.33
// Name: Rosy
// Average marks: 62.50


// You are using GCC
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student{
    private:
        string name;
        vector <double> marks;
        int num;
    public:
        Student(string n,vector<double>&arr,int len):name(n),marks(arr),num(len) {}
        
        void avg(){
            double sum=0;
            double avg=0;
            cout<<"Name: "<<name<<endl;
            for(int i=0;i<num;i++){
                sum+=marks[i];
                avg=sum/num;
            }
            cout<<"Average marks: "<<fixed<<setprecision(2)<<avg<<endl;
        }
};

int main(){
    int nStud;
    cin>>nStud;
    cout<<"Student Details:"<<endl;
    while(nStud){
        string n;
        int len;
        cin.ignore();
        getline(cin,n);
        // cin.ignore();
        cin>>len;
        // cin.ignore();
        vector<double> arr(len);
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        // cin.ignore();
        Student st(n,arr,len);
        st.avg();
        nStud--;
    }
}