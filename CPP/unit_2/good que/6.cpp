// Single File Programming Question
// Problem Statement



// Imagine you are developing a ticketing system for a theater. As part of the system, you need to implement a feature that allows customers to search for available seats based on their preferences. The seat availability data is stored in a 1D array.



// Create a class called ArraySearch and calculate the seat availability. Write the code for the same.



// Note: This is a sample question asked in a HCL interview.

// Input format :
// The first line of the input consists of the number of seats, n.

// The next line of input consists of n space-separated seat numbers as integers.

// The last line of input is the seat number to be searched (m).

// Output format :
// The output prints the status of the seat availability.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ seat numbers ≤ 100

// 1 ≤ m ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 50 40 10 20 30
// 20
// Output 1 :
// Seat is available
// Input 2 :
// 5
// 50 40 30 10 20
// 80
// Output 2 :
// Seat is not available


//using pointer

// You are using GCC
#include <iostream>
using namespace std;

class ArraySearch{
    private:
        int size;
        int *array;
        int find;
        
    public:
        ArraySearch(int n,int arr[],int search){
            size=n;
            array=new int[size];
            for(int i=0;i<size;i++){
                array[i]=arr[i];
            }
            find = search;
        }
        
        ~ArraySearch(){
        //     delete[] array;
        }
        
        void search(){
            bool found =false;
            for(int i=0;i<size;i++){
                if(array[i]==find){
                    cout<<"Seat is available";
                    found=true;
                }
            }
            if(!found){
                cout<<"Seat is not available";
            }
        }
};

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int find;
    cin>>find;
    ArraySearch as(n,arr,find);
    as.search();
    
    // delete[] arr;
}

//using vector


// #include <iostream>
// #include <vector>
// using namespace std;

// class ArraySearch {
// private:
//     vector<int> array; // Use std::vector for automatic memory management
//     int find;

// public:
//     // Constructor with parameter list
//     ArraySearch(const vector<int>& arr, int search) : array(arr), find(search) {}

//     // Search function to find if the element is present
//     void search() const {
//         bool found = false;
//         for (int num : array) {
//             if (num == find) {
//                 cout << "Seat is available" << endl;
//                 found = true;
//                 break;
//             }
//         }
//         if (!found) {
//             cout << "Seat is not available" << endl;
//         }
//     }
// };

// int main() {
//     int n;
//     cin >> n; // Number of seats

//     vector<int> arr(n); // Use std::vector for the array

//     // Read the seat numbers
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int find;
//     cin >> find; // Seat number to be searched

//     // Create an instance of ArraySearch
//     ArraySearch as(arr, find);
//     as.search();

//     return 0;
// }
