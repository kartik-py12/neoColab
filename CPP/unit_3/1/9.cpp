// Single File Programming Question
// Problem Statement



// Akil wants to write a program that creates a Person object and allows the user to enter the name and age of that person. The program should then display the name and age of the created object.



// Approach

// Define a Person class with private member variables: name and age.
// Implement a default constructor that displays a message indicating it has been called.
// Implement a display() member function that prints the name and age of the current object.
// Implement the setName() and setAge() member functions to set the name and age of the object.
// Input format :
// The first line consists of the name of the person as a string.

// The second line consists of the age of the person as an integer.

// Output format :
// The output displays the following messages:

// "Default constructor is called" (displayed once when the Person object is created)

// "Name of current object: [name]" (displays the name entered by the user)

// "Age of current object: [age]" (displays the age entered by the user).



// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// Length of name ≤ 100 characters

// 19 ≤ age ≤ 80

// Sample test cases :
// Input 1 :
// Akil
// 23
// Output 1 :
// Default constructor is called
// Name of current object: Akil
// Age of current object: 23
// Input 2 :
// Jaanu
// 24
// Output 2 :
// Default constructor is called
// Name of current object: Jaanu
// Age of current object: 24


// You are using GCC
#include <iostream>
using namespace std;

#include <string>
class Person{
    private:
        string name;
        int age;
    public:
        Person(){
            cout<<"Default constructor is called"<<endl;
            
        }
        
        void setName(string n){
            name=n;
        }
        
        void setAge(int a){
            age=a;
        }
        
        void display(){
            cout<<"Name of current object: "<<name<<endl;
            cout<<"Age of current object: "<<age<<endl;
        }
};

int main(){
    string name;
    int age;
    cin>>name;
    cin>>age;
    Person person;
    person.setName(name);
    person.setAge(age);
    person.display();
};