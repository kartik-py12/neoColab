// Single File Programming Question
// Problem Statement



// You are tasked with developing a simple book cataloging program. The program allows the user to enter details of multiple books, such as title, author, and publication year. The program then displays the entered book information.



// Develop a book cataloging program that allows the user to enter the details of multiple books and displays the entered book information. Create a class called Book that stores all the attributes and also uses an array of objects to solve the problem.

// Input format :
// The first line of input consists of an integer n, representing the total number of books.



// For each book, the input consists of the following inputs:

// Title of the book (a string) in the first line.
// Author of the book (a string) in the second line.
// Publication year of the book (an integer) in the third line.
// Output format :
// In the output, each line displays the following information about the book on separate lines:

// Title of the book
// Author of the book
// Publication year of the book


// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 50

// Sample test cases :
// Input 1 :
// 2
// India
// Gandhi
// 1947
// Tiger
// Haritha
// 2005
// Output 1 :
// Book Information:
// Book 1:
// Title: India
// Author: Gandhi
// Publication Year: 1947
// Book 2:
// Title: Tiger
// Author: Haritha
// Publication Year: 2005
// Input 2 :
// 2
// Harry Potter and the Chamber of Secrets
// J.K. Rowling
// 1998
// Harry Potter and the Prisoner of Azkaban 
// J.K. Rowling
// 1999
// Output 2 :
// Book Information:
// Book 1:
// Title: Harry Potter and the Chamber of Secrets
// Author: J.K. Rowling
// Publication Year: 1998
// Book 2:
// Title: Harry Potter and the Prisoner of Azkaban 
// Author: J.K. Rowling
// Publication Year: 1999

// You are using GCC
#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        string title;
        string author;
        int year;
        int num;
    public:
        Book(string t,string a,int y,int n):title(t),author(a),year(y),num(n) {}
        
        void details(){
            cout<<"Book "<<num<<":"<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Publication Year: "<<year<<endl;
        }
};

int main(){
    int n;
    cin>>n;
    cin.ignore();
    cout<<"Book Information:"<<endl;
    for(int i=0;i<n;i++){
        string t,a;
        int y;
        getline(cin,t);
        getline(cin,a);
        cin>>y;
        cin.ignore();
        
        Book book(t,a,y,i+1);
        book.details();
    }
}