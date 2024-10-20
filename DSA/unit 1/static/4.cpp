/*
Single File Programming Question
Problem Statement



You're an instructor managing a list of exam scores for a group of students. The scores are stored in an array, and you need to sort this array in ascending order so that you can easily identify the highest and lowest scores. You'll use two different sorting algorithms: bubble sort and selection sort.



Bubble sort is selected if the array is nearly sorted. An array is considered nearly sorted if at most one pair of elements is out of order. The selection sort is chosen if the array is not nearly sorted.

Input format :
The first line of input contains an integer n, representing the number of students.

The second line contains n space-separated integers, representing the exam scores of students.

Output format :
The first line of output prints which sort algorithm is used, either "Using Bubble Sort" or "Using Selection Sort".

The second line prints the sorted exam scores in ascending order.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ n ≤ 20

1 ≤ exam score ≤ 100

Sample test cases :
Input 1 :
6
64 78 85 92 99 73
Output 1 :
Using Bubble Sort
Sorted Exam Scores: 64 73 78 85 92 99 
Input 2 :
5
32 91 53 76 28
Output 2 :
Using Selection Sort
Sorted Exam Scores: 28 32 53 76 91
*/

// You are using GCC
#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    //Type your code here
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n-1;i++){
        int maxIndex=i;
        
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[maxIndex]){
                maxIndex=j;
            }
        }
        if(maxIndex!=i){
            int temp =arr[i];
            arr[i]=arr[maxIndex];
            arr[maxIndex]=temp;
        }
              
    }   
}

bool isNearlySorted(int scores[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (scores[i] > scores[i + 1]) {
            count++;
            if (count > 1) {
                return false;
            }
        }
    }
    return true;
}

void sortArray(int scores[], int n) {
    if (isNearlySorted(scores, n)) {
        printf("Using Bubble Sort\n");
        bubbleSort(scores, n);
    } else {
        printf("Using Selection Sort\n");
        selectionSort(scores, n);
    }
}

void printArray(int scores[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int examScores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &examScores[i]);
    }

    sortArray(examScores, n);
    
    printf("Sorted Exam Scores: ");
    printArray(examScores, n);

    return 0;
}