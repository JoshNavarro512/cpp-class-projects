// Serial Number: 46
//
// Author: Joshua Navarro
//
// Due Date: 4/24/2019
// Programming Assignment Number 6
//
// Spring 2019 - CS 3358 - 252
//
// Instructor: Husain Gholoom
//
// Creates Char array and sorts or find characters

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <string.h>
//#include <windows.h>
using namespace std;


// Function Prototypes
void displayArray (char array1[], int array_size);
void selectionSort(char array2, int array_size);
int sequentialSearch(char array1[], int array_size, int value);




int main()
{
    // Set random seed to time
    unsigned seed;
    seed = time(0);
    srand(seed);

    int arraySize;
    int func1;
    time_t  startT,
            endT;

    cout << "Enter the size of the array: ";
    cin  >> arraySize;


    if (arraySize > 0)
    {


        char charArray[arraySize];
        char charArray2[arraySize];
        char charArray3[arraySize];
        char charArray4[arraySize];
        char charArray5[arraySize];
        for (int i = 0; i < arraySize; i++)
            {
                charArray[i] = (rand() % (126 - 33 + 1)) + 33;
            }

        cout << "Array elements are: ";
        displayArray(charArray, 20);

        strcpy(charArray2, charArray);
        strcpy(charArray3, charArray);
        strcpy(charArray4, charArray);
        strcpy(charArray5, charArray);


        cout << "Sequential Search " << endl;
        cout << "Searching for 80" << endl;
        startT = time(0);
        func1 = sequentialSearch(charArray, arraySize, 80);
        endT = time(0);
        if (func1 == -1)
        {
            cout << 80 << " Was Not Found" << endl;
        }
        else
        {
            cout << 80 << " Was Found" << endl;
        }
        cout << "Start Time: " << startT << endl;
        cout << "End Time  : " << endT << endl;
        cout << "Actual CPU clock time: " << (startT - endT) <<  endl;
        cout << "Total Number of Comparisons: " << func1 + 1 << endl;
        cout << "Array Elements: ";
        displayArray(charArray, arraySize);

        /*******************
        *  Selection Sort  *
        *******************/




        cout << "Selection Sort:" << endl;
        cout << "\nstart Time: " ;








    }
    else
    {
        cout << "\n*** Error - Invalid input - Size must be > 0 ***" << endl;
    }




    cout << "\n\nBenchmark Algorithm Implemented by: Joshua Navarro" << endl;
    cout << "4-24-2019" << endl;

    return 0;
}


// Functions
void displayArray (char array1[], int array_size)
{
    for (int i = 0; i < array_size; i++)
            cout << array1[i] << " ";
    cout << endl;
}

// Sequential Search
int sequentialSearch(char array1[], int array_size, int value)
{
    static int index = 0;
    static int position = -1;
    static bool found = false;

//    Sleep(10);

    if(index < array_size && !found)
    {
        if(array1[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
        sequentialSearch(array1, array_size, value);
    }

    return position;

}


// Selection Sort
void selectionSort(char array2, int array_size)
{



}




















