// Single File Programming Question
// Problem Statement



// In the kingdom of Geometria, there were two skilled architects, Lily and Max, known for their exceptional ability to design unique rectangles. They created a remarkable Rectangle class that could compare the size of rectangles using the overloaded '==' operator.



// One day, the kingdom organized a grand architectural competition, and Lily and Max were invited to participate with their awe-inspiring rectangles. As the competition unfolded, they proudly presented their creations, each trying to prove the equality of their rectangles using the operator overloading concept.



// The kingdom's people marveled at the elegant display of mathematical prowess, witnessing the magical operator determine whether the rectangles were equal in size or not.



// Write a program to accomplish the above-given scenario.

// Input format :
// The first line consists of two space-separated integers, representing the width and height of Rectangle 1.

// The second line consists of two space-separated integers, representing the width and height of Rectangle 2.

// Output format :
// The output consists of a single line with one of the following messages:

// "Rectangle 1 and Rectangle 2 are equal in size." if Rectangle 1 and Rectangle 2 have the same width and height.

// "Rectangle 1 and Rectangle 2 are not equal in size." if Rectangle 1 and Rectangle 2 have different widths or heights.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ width, height ≤ 1000

// Sample test cases :
// Input 1 :
// 10 20
// 10 20
// Output 1 :
// Rectangle 1 and Rectangle 2 are equal in size.
// Input 2 :
// 10 20
// 30 40
// Output 2 :
// Rectangle 1 and Rectangle 2 are not equal in size.
// Input 3 :
// 10 20
// 20 10
// Output 3 :
// Rectangle 1 and Rectangle 2 are not equal in size.


// You are using GCC
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    if(a==c&b==d){
        cout<<"Rectangle 1 and Rectangle 2 are equal in size.";
    }
    else{
        cout<<"Rectangle 1 and Rectangle 2 are not equal in size.";
    }
}