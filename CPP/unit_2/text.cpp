// #include<iostream>
// using namespace std;
// class Test
// {
//     private:
//     int x;
//     int y;
//     public:
//     Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//     static void fun1() { cout << "Inside fun1()"; }
//     static void fun2() { 
//         cout << "Inside fun2()"; 
//         fun1(); 
//         }
// };
// int main()
// {
//     Test obj;
//     obj.fun2();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int* getPointer() {
//     int num = 10;
//     return &num;
// }
// int main() {
//     int* ptr = getPointer();
//     cout << *ptr;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int *ptr;
//     ptr = new int;
//     delete ptr;
//     *ptr = 5;
//     cout << *ptr;
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main() {
//     char arr[20];
//     int i;
//     for (i = 0; i < 10; i++)
//     *(arr + i) = 65 + i;
//     *(arr + i) = '\0';
//     cout << arr;
//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//     int arr[2][3] = {
//         {1, 2, 3},
//         {4, 5, 6}
//     };
    
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 3; j += 2) {
//             cout << arr[i][j] << " ";
//         }
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class ArrayProcessor {
// public:
//    static void processArray(int arr[][3], int rows) {
//       for (int i = 0; i < rows; i++) {
//          for (int j = 0; j < 3; j++) {
//             cout << arr[i][j] << " ";
//          }
//          cout << endl;
//       }
//    }
// };

// int main() {
//    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
//    ArrayProcessor::processArray(arr, 2);
//    return 0;
// }

// #include <iostream>
// using namespace std;
// class Matrix {
// private:
//     static const int ROWS = 2;
//     static const int COLS = 3;
//     int arr[ROWS][COLS];
// public:
//     void initialize() {
//         for (int i = 0; i < ROWS; ++i) {
//             for (int j = 0; j < COLS; ++j) {
//                 arr[i][j] = i + j;
//                 cout<<arr[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     void printElement(int row, int col) {
//         cout << arr[row][col];
//     }
// };

// int main() {
//     Matrix m;
//     m.initialize();
//     m.printElement(1, 2);
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Main {
// public:
//     int result = 0;
// };

// int main() {
//     const int size = 7;  
//     Main mArr[size];

//     int array[] = {0, 2, 4, 6, 7, 5, 3};

//     for (int n = 0; n < size; n++) {
//         mArr[n].result += array[n];
//     }

//     for (int n = 0; n < size; n++) {
//         cout << mArr[n].result << " ";
//     }

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main(int argc, char const *argv[]){
//     string str;
//     cin>>str;
//     cout<<str;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str = "Hello";
//     str += " World!";
//     cout << str.size();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class MyObject {
// public:
//     int value;
// };

// int main() {
//     MyObject obj1;
//     obj1.value = 5;

//     MyObject obj2;
//     obj2.value = 10;

//     MyObject obj3;
//     obj3.value = 15;

//     MyObject arr[] = {obj1, obj2, obj3};

//     cout << arr[1].value;

//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int main ()
// {
//     char a[10] = "computer";
//     char b[10] = "World";
//     char c[10];
//     int len ;
//     strcpy( c, a);
//     strcat( a, b);
//     len = strlen(a);
//     cout << len;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
    
// int main() {
//     string str = "Hello, World!";
//     str.insert(7, "there ");
//     cout << str;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void fun(int x, int y){
//     x = 20;
//     y = 10;
// }
// int main() {
//     int x = 10;
//     fun (x, x);
//     cout << x;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str = "Programming";
//     str.erase(4, 7);
//     cout << str;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     int data = 5;

//     void printData(int d) {
//         int data = d;
//         cout << data << " ";
//         print();
//     }

//     void print() {
//         cout << data;
//     }
// };

// int main() {
//     MyClass obj;
//     obj.printData(10);
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str("microsoft");

//     for (char& c : str) {
//         c = toupper(c);
//     }

//     cout << str << endl;

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, world!";
    str.insert(5, "beautiful ");
    cout << str;
    return 0;
}