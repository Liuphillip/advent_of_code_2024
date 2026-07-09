/*
    advent of code 2024, excercise 1
    author: Phillip Liu, 2026

    instructions:

    1. Pair up the smallest number in the left list with the smallest number 
    in the right list, then the second-smallest left number with the second-smallest 
    right number, and so on.

    2. Within each pair, figure out how far apart the two numbers are; you'll
    need to add up all of those distances.
*/


/*
    plan: 
    1. initialize 2 lists containing the array ints
    2. order lists.
    3. find difference between pairs of the same index.
    4. add differences.

*/
#include <stdio.h>
#include <stdlib.h> // for abs()

void bubbleSort(int arr[], int size) {
    // Outer loop tracks the number of passes
    for (int i = 0; i < size - 1; i++) {
        
        // Inner loop compares adjacent elements
        // (size - i - 1) prevents checking already sorted elements at the end
        for (int j = 0; j < size - i - 1; j++) {
            
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// helper function
void printArr(int arr[], int size){
    for(int i = 0; i < 6; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(void){

    int arr1[6] = {3, 4, 2, 1, 3 ,3};
    int arr2[6] = {4, 3, 5, 3, 9, 3};

    bubbleSort(arr1, 6);
    bubbleSort(arr2, 6);

    int sum = 0;

    for(int i = 0; i < 6; i++){
        sum += abs(arr1[i] - arr2[i]);
    }

    printArr(arr1, 6);
    printArr(arr2, 6);
    printf("Sum is : %d", sum);

    return 0;
}