/*
// Problem Statement

// Manish is fascinated by the representation of characters in C. 
Write a program that declares a character variable with the value 'S' 
and print the following pattern with the declared variable using necessary white space characters.

Output
S	S	S
S	S

*/


#include <iostream>

namespace charr{
    char mychar='S';
}

int main(){

    // using string
    std::cout << "using string \n";
    std::string mychar ="S  ";
    std::cout << mychar  << mychar << mychar <<std::endl;
    std::cout << mychar << mychar << "\n";


    // using char
    std::cout << "using char \n";
    std::cout << charr::mychar << "  " << charr::mychar << "  " << charr::mychar << std::endl;
    std::cout << charr::mychar << "  " << charr::mychar << std::endl;

    return 0;
}

