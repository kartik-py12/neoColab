// Single File Programming Question
// Problem Statement



// Imagine you are designing a program for a construction company that needs to keep track of rectangles being used for various projects. You are tasked with creating a class named Rectangle to represent each rectangle used in the projects. 



// The class should have the following specifications:

// A private static data member named count keeps track of the total number of rectangle objects created. It should be initialized to 0.
// A public static member function named getCount() returns the value of count. 
// A public member function named setDimensions takes in the values of length and width as parameters and sets the corresponding data members for a rectangle object. 
// A public member function named getArea() calculates and returns the area of a rectangle object. 
// Two private data members named length and width store the integer values of the length and width of a rectangle. These data members are specific to each rectangle object.


// Based on the given specifications, your task is to implement the Rectangle class that meets the requirements mentioned above.

// Input format :
// The first integer denotes the number of rectangles, n.

// The next n lines of inputs consist of the length and width of each rectangle separated by space.

// Output format :
// The output displays the total number of rectangles in the first line, followed by the next n lines containing the area of n rectangles.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 3
// 10 20
// 20 30
// 30 40
// Output 1 :
// Total number of rectangles: 3
// Area of rectangle 1: 200
// Area of rectangle 2: 600
// Area of rectangle 3: 1200
// Input 2 :
// 4
// 12 30
// 15 36
// 24 45
// 38 65
// Output 2 :
// Total number of rectangles: 4
// Area of rectangle 1: 360
// Area of rectangle 2: 540
// Area of rectangle 3: 1080
// Area of rectangle 4: 2470

// // You are using GCC
#include <iostream>
using namespace std;

// class Rectangle{
//     private:
//         static int count;
//         int length;
//         int width;
//     public:
//         Rectangle(){
//             count++;
//         }
        
//         static int getcount(){
//             return count;
//         }
        
//         void setDimensions(int l,int w){
//             length=l;
//             width=w;
//         }
        
//         int getArea() const{
//             return length*width;
//         }
        
// };

// int Rectangle::count=0;
// int main(){
//     int n;
//     cin>>n;
//     Rectangle rec[n];
//     for (int i=0;i<n;i++){
//         int len,wid;
//         cin>>len>>wid;
//         rec[i].setDimensions(len,wid);
//     }
//     // int count=Rectangle::getcount();
//     cout<<"Total number of rectangles: "<<Rectangle::getcount()<<endl;
//     for(int i=0;i<n;i++){
//         cout<<"Area of rectangle "<<i+1<<": "<<rec[i].getArea()<<endl;
//     }

// }

int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    cout<<"Total number of rectangles: "<<n<<endl;
    for(int i=0;i<n;i++){
        int length,width;
        cin>>length>>width;
        cout<<"Area of rectangle "<<i+1<<": "<<length*width<<endl;
    }
}
