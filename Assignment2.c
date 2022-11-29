// Class October 12th.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Nathan Malicki
    Systems Programming
    10/12/22
    Assignment 2 ***important***

    This code has functions for initializing Dynamic arrays and functions that perform logical operations on arrays
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//init functions ==============================================================================================================================================================

//creates an array where the user submits the data
void arrayInit(int* a, int size) {
    int i;
    printf("Enter 1 number per line\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]); //stores the input at the respective index
    }
}

//creates an array where each index has i stored in it
void arrayInitSeq(int* a, int size) {
    int i;
    for (i = 0; i < size; i++) {
        a[i] = i;
    }
}

//creates an array where each index had a random number from 1 to 100 stored in it
void arrayInitRandom(int* a, int size) {
    int i;
    for (i = 0; i < size; i++) {
        a[i] = rand() % 100; //random number from 1 to 100 is generated and stored in each index
    }
}

//assignment functions=========================================================================================================================================================

//uses pointers to swap data at addresses so the results are seen in main without returning
void swapInts(int* a, int* b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

//returns the smallest value in the array
int findMin(int* a, int size) {
    int i;
    int min = a[0];
    for (i = 1; i < size; i++) {
        if (a[i] < min) //compares each index to the current min, if it is smaller the new value is stored in min
            min = a[i];
    }
    return min;
}

//returns the maximum value in the array
int findMax(int* a, int size) {
    int i;
    int max = a[0];
    for (i = 1; i < size; i++) {
        if (a[i] > max) //compares each index to the current max, if it is larger the new value is stored in max
            max = a[i]; 
    }
    return max;
}

//prints the two smallest values in the arrays
void findMinAnd2ndMin(int* a, int size) {
    int i = 1;
    int min = a[0];
    int min2;
    while (a[i] == min) { //makes sure there is a value in min2 that is not the same as min
        i++;
    }
    if (a[i] < min) { 
        min2 = min;
        min = a[i];
    }
    else {
        min2 = a[i];
    }

    for (; i < size; i++) {
        if (a[i] < min) { //compares each the value of a at index i to min, if it is larger the old min now becomes min2
            min2 = min;
            min = a[i];
        }
        else {
            if (a[i] != min && a[i] < min2) //if the value at the index is larger than min the program checks if the value at the index is smaller than the current min2
                min2 = a[i];
        }
    }
    printf("min: %d, second min: %d\n", min, min2); //output as a print statement
}

//prints the two largest values in the array
void findMaxAnd2ndMax(int* a, int size) {
    int i = 1;
    int max = a[0];
    int max2 = 1;

    while (a[i] == max) {
        i++;
    }
    if (a[i] > max) { //makes sure there is a value in max2 that is not the same as max
        max2 = max;
        max = a[i];
    }
    else {
        max2 = a[i];
    }
    for (; i < size; i++) {
        if (a[i] > max) { //compares each the value of a at index i to max, if it is larger the old max now becomes max2
            max2 = max;
            max = a[i];
        }
        else {
            if (a[i] != max2 && a[i] > max2) //if the value at the index is smaller than max the program checks if the value at the index is larger than the current max2
                max2 = a[i];
        }
    }
    printf("second max: %d, max: %d\n", max2, max); //output as a print statement
}

//prints the array using a simple for loop, output is on one line with each index seperated by a comma and a newline at the end
void arrayPrint(int *a, int size){
    int i;
    printf("Printing your array \n");
    for (i = 0; i < size; i++) {
        if(i != size - 1) //checks if the value is not the last
            printf("%d, ", a[i]);
        else
            printf("%d\n", a[i]); //creates a newline at the end of the output instead of another comma
    }
}
//prints the array backwards using a simple for loop, output is on one line with each index seperated by a comma and a newline at the end
void arrayPrintBackwards(int* a, int size){
    int i;
    printf("Printing your array \n");
    for (i = size - 1; i >= 0; i--) { //starts with size - 1 and goes down to zero
        if (i != 0) //checks if the value is not the last
            printf("%d, ", a[i]);
        else
            printf("%d\n", a[i]); //creates a newline at the end of the output instead of another comma
    }
}

//prints the array recursively, output is on one line with each index seperated by a comma and a newline at the end
void arrayPrintRecursive(int* a, int size, int i) {
    if (i  < size - 1) { //end condition
        printf("%d, ", a[i]);
        arrayPrintRecursive(a, size, i + 1); //calls the function again, but with a higher i to move to the next index
    }
    else{ //when the last index is reached it puts a newline, function is not called
        printf("%d\n", a[i]);
        printf("Printed Recursively\n");
    }
}

//prints the array recursively backwards, output is on one line with each index seperated by a comma and a newline at the end - prints a[0] after else print statement
void arrayPrintRecursiveBackwards(int* a, int size, int i) {
    if (i > 0) { //end condition
        printf("%d, ", a[i]);
        arrayPrintRecursiveBackwards(a, size, i - 1); // calls the function again, but with a lower i to move to the next lowest index
    }
    else { //when the last index is reached it puts a newline
        printf("%d\n", a[i]); 
        printf("Printed Recursively Backwards\n");
        
    }
}

//prints the array recursively backwards, output is on one line with each index seperated by a comma and a newline at the end - prints a[0] after else print statement
void arrayPrintRecursiveBackwards2(int* a, int size, int i) {
    if (i < size) { //end condition
        arrayPrintRecursiveBackwards2(a, size, i + 1); //calls the function again, but with a higher i to move to the next index
        if (i != 0)
            printf("%d, ", a[i]);
        else {
            printf("%d\n", a[i]);
            printf("Printed Recursively\n");
        }
    }
}

//sorts the array in ascending order
void bubbleSortAscending(int* a, int size) {
    int i, j;
    for (j = 0; j < size - 1; j++) { //runs multiple rounds of bubble sort
        for (i = 0; i < size - 1; i++) { //one round of bubble sort, bring the largest unsorted value to the correct index
            if (a[i] > a[i + 1]) //swaps value if it is out of order
                swapInts(&a[i], &a[i + 1]);
        }
    }
    printf("Ascending Bubble Sort\n");
}

//sorts the array in descending order
void bubbleSortDescending(int* a, int size) {
    int i, j;
    for (j = 0; j < size - 1; j++) { //runs multiple rounds of bubble sort
        for (i = 0; i < size - 1; i++) { //one round of bubble sort, bring the smallest unsorted value to the correct index
            if (a[i] < a[i + 1]) //swaps value if it is out of order
                swapInts(&a[i], &a[i + 1]);
        }
    }
    printf("Descending Bubble Sort\n");
}

//returns index of target searched for (-1 if not in array)
int linearSearch(int* a, int size, int target) {
    int i;
    for (i = 0; i < size; i++) { //checks each index for the target value
        if (a[i] == target)
            return i;
    }
    return -1;
}

//returns index of target searched for (-1 if not in array) - complexity: log(n)
int binarySearch(int* a, int size, int target) {
    int upperRange = size;
    int lowerRange = 0;
    int mid;

    bubbleSortAscending(a, size);
    arrayPrint(a, size);

    while (upperRange >= lowerRange) {
        mid = (lowerRange + upperRange) / 2;
        if (a[mid] == target) //target found and returned
            return mid;
        else { //cuts search space in half based on relative position of target to mid
            if (a[mid] > target)
                upperRange = mid - 1;
            else
                lowerRange = mid + 1;
        }
        //computes new range after limits are changed.
    }

    return -1;
}

//puts the elements of array a in reverse order
void arrayReverse(int* a, int size) {
    int i;
    for (i = 0; i < (size - (size % 2)) / 2; i++) //computes the number of steps needed to swap based on array length and if length is odd/even
        swapInts(&a[i], &a[size - 1 - i]); //swaps every index 
    printf("Array Reversed\n");
}

//returns the number of occurances of target
int count(int* a, int size, int target) {
    int i;
    int count = 0;
    for (i = 0; i < size; i++) { //checks if each index is an occurance of the target, increments if so
        if (a[i] == target)
            count++;
    }
    return count;
}

//prints an array where at index is the number of times that index i was in array a
void counting(int* a, int size) {
    int cSize = findMax(a, size) + 1;
    int* c;
    int i;
    c = (int*) calloc(cSize, sizeof(cSize));

    for (i = 0; i < size; i++) {
        c[a[i]]++;
    }
    arrayPrint(c, cSize);
    free(c); //natasha said to do this
}

//3.5 functions==============================================

//prints a sorted version of a
void unstableCountingSort(int* a, int size) {
    int i, j;

    int cSize = findMax(a, size) + 1;
    int* c;
    c = (int*)calloc(cSize, sizeof(cSize));

    for (i = 0; i < size; i++) {
        c[a[i]]++;
    }

    printf("Printing C\n");
    arrayPrint(c, cSize);

    for (j = 0; j < cSize; j++) {
        for (i = 0; i < c[j]; i++) {
            printf("%d, ", j); //prints each index the number stored at that index
        }
    }
    printf("\n");
    free(c); //natasha said to do this
}
//4.0 functions===========================================

//
void stableCountingSort(int* a, int size) {
    int i;

    int* b;
    b = (int*)calloc(size, sizeof(size));

    int pSize = findMax(a, size) + 1;
    int* p;
    p = (int*)calloc(pSize, sizeof(pSize));

    //fills the position array with values
    p[0] = count(a, size, 0) - 1;
    for (i = 1; i < pSize; i++) {
        p[i] = count(a, size, i) + p[i - 1];
    }
    arrayPrint(p, pSize);

    //creates the sorted stable counting array
    for (i = size - 1; i > -1; i--) {
        b[p[a[i]]] = a[i];
        p[a[i]]--;    
    }

    printf("Sorted Array\n");
    arrayPrint(b, size);
    free(b); //natasha said to do this
}
//sorts values in ascending order and stops running rounds when the array is sorted
void efficientBubbleSort(int* a, int size) {
    int sorted = 0;
    int i;
    while(sorted != 1) { //runs multiple rounds of bubble sort
        for (i = 0; i < size - 1; i++) { //one round of bubble sort, bring the largest unsorted value to the correct index
            if (a[i] > a[i + 1]) //swaps value if it is out of order
                swapInts(&a[i], &a[i + 1]);
        }
        
        sorted = 1;
        for (i = 0; i < size - 1; i++) { 
            if (a[i] > a[i + 1]) //checks if values are sorted
                sorted = 0;
        }
    }
    printf("Ascending Bubble Sort\n");
}

//============================================================================================================

int main(){
    int* a;
    int size;
    int find;
    int menu = -1;

    //sets the size of the array that will be made
    printf("How many numbers do you want to have in the array?\n");
    scanf("%d", &size);

    //creation of the array of *size* given by user
    a = (int*)calloc(size, sizeof(int));
    
    while (menu == -1) { //choses the method for array initialization
        printf("\nPlease enter a number from 1-3 that corresponds with how you would like an array to be made\n");
        printf("(1) You input array\n");
        printf("(2) 0 to size - 1 (0, 1, 2, ..., size - 1)\n");
        printf("(3) Random Value (0-99) at each index\n");

        scanf("%d", &menu);
        printf("\n");

        switch (menu) {

        case 1:
            arrayInit(a, size);
            break;
        case 2:
            arrayInitSeq(a, size);
            break;
        case 3:
            arrayInitRandom(a, size);
            break;
        default:
            arrayInit(a, size);
        }
    }

    menu = -1;

    arrayPrint(a, size); //output the array so the user knows what their array is before they do an operation on it
    
    //lets you keep calling functions until you exit with an input of 0
    while (menu != 0){
        //function menu
        printf("\nPlease enter a number from 1-17 to run the corresponding function\n");
        printf("\t(0)  Exit Menu\n");
        printf("====================Minimums and Maximums=====================\n");
        printf("\t(1)  Find the minimum value of array\n");
        printf("\t(2)  Find the maximum value of array\n");
        printf("\t(3)  Find the minimum and second minimum values of array\n");
        printf("\t(4)  Find the maximum and second maximum values of array\n");
        printf("=========================Array Printing=======================\n");
        printf("\t(5)  Simple Print array\n");
        printf("\t(6)  Backwards Print array\n");
        printf("\t(7)  Recursive Print array\n");
        printf("\t(8)  Recursive Backwards Print array\n");
        printf("============================Searches==========================\n");
        printf("\t(9)  Linear Search\n");
        printf("\t(10) Binary Search\n");
        printf("==========================Bubble Sort=========================\n");
        printf("\t(11) Ascending Bubble Sort\n");
        printf("\t(12) Descending Bubble Sort\n");
        printf("====================Reverse and Counting======================\n");
        printf("\t(13) Reverse the Array\n");
        printf("\t(14) Count the values of the array and print\n");
        printf("========================3.5 Function==========================\n");
        printf("\t(15) Unstable Counting Sort\n");
        printf("========================4.0 Functions=========================\n");
        printf("\t(16) Stable Counting Sort\n");
        printf("\t(17) Efficient Bubble Sort\n");
        printf("\nFunction you want to run: ");

        scanf("%d", &menu);
        printf("\n");
        
        //logic of menu selection
        switch (menu) {
            case 0: //breaks the while loop and stops the menu from showing up again
                printf("Exiting menu\n");
                break;
            case 1:
                printf("Min: %d \n", findMin(a, size));
                break;
            case 2:
                printf("Max: %d \n", findMax(a, size));
                break;
            case 3:
                findMinAnd2ndMin(a, size);
                break;
            case 4:
                findMaxAnd2ndMax(a, size);
                break;
            case 5:
                arrayPrint(a, size);
                break;
            case 6:
                arrayPrintBackwards(a, size);
                break;
            case 7:
                arrayPrintRecursive(a, size, 0);
                break;
            case 8: //two different version have a submenu to select between them
                printf("What version do you want to run (1) or (2)?\n");
                scanf("%d", &find);
                if (find == 1)
                    arrayPrintRecursiveBackwards(a, size, size - 1);
                else
                    arrayPrintRecursiveBackwards2(a, size, 0);
                break;
            case 9: //input for choosing which number to search for
                printf("What number do you want to find?\n");
                scanf("%d", &find);
                printf("Value was at index %d in the array\n",linearSearch(a, size, find));
                break;
            case 10: //input for choosing which number to search for
                printf("What number do you want to find?\n");
                scanf("%d", &find);
                printf("Value was at index %d in the array\n", binarySearch(a, size, find));
                break;
            case 11:
                bubbleSortAscending(a, size);
                arrayPrint(a, size);
                break;
            case 12:
                bubbleSortDescending(a, size);
                arrayPrint(a, size);
                break;
            case 13:
                arrayReverse(a, size);
                arrayPrint(a, size);
                break;
            case 14:
                counting(a, size);
                break;
            case 15:
                unstableCountingSort(a, size);
                break;
            case 16:
                stableCountingSort(a, size);
                break;
            case 17:
                efficientBubbleSort(a, size);
                arrayPrint(a, size);
                break;
            default: //catches any other value and makes the user input again
                printf("!!!Not a valid input!!!\n");
                break;
        }
        Sleep(1500); //waits a second after the function output before printing the menu again
        printf("---------------------------------------------------------------------------\n");
    }

    printf("\nArray has been freed\n");
    //shows that the array has been freed
    free(a);
    arrayPrint(a, size);
}
