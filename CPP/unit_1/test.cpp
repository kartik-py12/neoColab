// // // // // // // // #include <iostream>
// // // // // // // // using namespace std;

// // // // // // // // class MyMath {
// // // // // // // // public:
// // // // // // // //   static int multiply(int a, int b) {
// // // // // // // //     return a * b;
// // // // // // // //   }
// // // // // // // // };

// // // // // // // // int main() {
// // // // // // // //   int result = MyMath::multiply(5, 7);
// // // // // // // //   cout << result;
// // // // // // // //   return 0;
// // // // // // // // }

// // // // // // // // #include <iostream>
// // // // // // // // #include <iomanip>
// // // // // // // // using namespace std;

// // // // // // // // int main() {
// // // // // // // //   double value = 1234.56789;
// // // // // // // //   cout << setw(10) << setfill('*') << value;
// // // // // // // //   return 0;
// // // // // // // // }

// // // // // // // #include <iostream>
// // // // // // // using namespace std;

// // // // // // // inline int divide(int a, int b) {
// // // // // // //     if (b == 0) {
// // // // // // //         cout << "Error: Division by zero!";
// // // // // // //         return 0;
// // // // // // //     }
// // // // // // //     return a / b;
// // // // // // // }
// // // // // // // int main() {
// // // // // // //     int result = divide(10, 2);
// // // // // // //     cout << result;
// // // // // // //     return 0;
// // // // // // // }


// // // // // // #include<iostream>
// // // // // // using namespace std;

// // // // // // void print(int i) {
// // // // // //     cout << i;
// // // // // // }
// // // // // // void print(double f) {
// // // // // //     cout << f;
// // // // // // }
// // // // // // int main() {
// // // // // //     print(5);
// // // // // //     print(500.263);
// // // // // //     return 0;
// // // // // // }

// // // // // #include <iostream>
// // // // // using namespace std;

// // // // // int multiply(int a, int b) {
// // // // //     return a * b;
// // // // // }

// // // // // double multiply(double a, double b) {
// // // // //     return a * b;
// // // // // }

// // // // // int main() {
// // // // //     int intResult = multiply(2, 3);          
// // // // //     double doubleResult = multiply(2.5, 3.5); 
// // // // //     cout << "Result: " << intResult << endl;
// // // // //     cout << "Result: " << doubleResult;
// // // // //     return 0;
// // // // // }

// // // // #include <iostream>
// // // // using namespace std;

// // // // int globalVariable = 5;

// // // // void multiplyByTwo(int num) {
// // // //     int result = num * 2;
// // // //     cout << "Result inside function: " << result << endl;
// // // // }

// // // // int main() {
// // // //     multiplyByTwo(7);
// // // //     cout << "Result outside function: " << globalVariable;
// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // using namespace std;

// // // void increment(int num) {
// // //     ++num;
// // //     cout << "Inside increment: " << num << endl;
// // // }

// // // int main() {
// // //     int value = 5;
// // //     increment(value);
// // //     cout << "Inside main: " << value << endl;
// // //     return 0;
// // // }

// // #include <iostream>
// // using namespace std;

// // int gcd(int a, int b) {
// //     if (b == 0)
// //         return a;
// //     else
// //         return gcd(b, a % b);
// // }
// // int main() {
// //     int number1 = 54;
// //     int number2 = 24;
// //     int result = gcd(number1, number2);
// //     cout << result;
// //     return 0;
// // }

// #include <iostream>
// using namespace std;

// void modifyValue(int& num) {
//     num *= 2;
// }

// int main() {
//     int value = 10;
//     modifyValue(value);
//     cout << value;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void increment(int& num) {
//     num++;
// }

// int main() {
//     int x = 5;
//     increment(x);
//     cout << "After increment: x = " << x;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int func(void *Ptr);
// int main(){
//     char *Str = "abcdefghij";
//     func(Str);
//     return 0;
// }
// int func(void *Ptr){
//     cout << Ptr;
//     return 0;
// }   


#include <iostream>
using namespace std;

int main() {
    char p[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; 
    char* q;

    q = p;  

    cout << *q;          
    cout << *(q + 1);    
    cout << *(q + 2);    
    cout << *(q + 3);    
    cout << *(q + 4);    
    cout << *(q + 5);    

    q = q + 6;

    cout << *p;
    return 0;
}