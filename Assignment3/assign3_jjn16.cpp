// File Name: assign1_jjn16.cpp
// 
// Author: Joshua Navarro	
// Date: 10/1/2018
// Assignment Number: 3
// CS 2308.004 Fall 2018
// Instructor: Jill Seaman 
// 
// This program uses pointers and dynamic memory allocation

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



// Function Prototypes 
void leftCircleShift (int *, int );
void displayArray( int *, int );
double litersForKm ( double , double , double *);
int *duplicateArray (int *, int);
int *subArray(int *, int *);
string *arrayOfPtrs ( string *  , int );



//double litersForKm ( double mpg, double km, double *1p100km);
//int subArray(int *begin, int *end);
//string arrayOfPtrs ( );

// Global constants 
int const    ARRAY_SIZE  = 10;
const double GALLON_LITERS     = 3.785411784,
             MILES__KILOMETERS = 1.609344;
                  


int main()
{
	 
	int array[ARRAY_SIZE] = {1 , 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	
	
	// Testing Function 1 -> leftCircleShift
	cout << "Testing leftCircleShift:" << endl;
	cout << "test data array : 1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "Expected result : 2 3 4 5 6 7 8 9 10 1" << endl;
	leftCircleShift ( array , ARRAY_SIZE);
	displayArray( array, ARRAY_SIZE );
	cout << "\nshift again:" << endl;
	cout << "Expected result : 3 4 5 6 7 8 9 10 1 2" << endl;
	leftCircleShift ( array , ARRAY_SIZE);
	displayArray( array, ARRAY_SIZE );
	
	
	
	
	// Testing Function 2 -> litersForKm
	double km   = 10.0,
		   km2  = 700.0;
	double mpg  = 25.0,
		   mpg2 = 33.60;
	double kpl;
	double *lp100km;
	
	lp100km = &kpl;
	
	                             
	double litToKm = litersForKm ( mpg, km, lp100km);
	
	cout << fixed << showpoint << setprecision (2);
	cout << "\n\nTesting litersForKm:" << endl;
	cout << "testing for 25.0mpg and 10.0km" << endl;
	cout << "Expected result: 9.41 Lp100km and 0.94 liters" << endl;
	cout << "Actual results: " <<  kpl   << " and " <<  litToKm    << " liters" << endl;
	
	double litToKm2 = litersForKm ( mpg2, km2, lp100km);
	cout << "testing for 33.60mpg and 700.0km" << endl;
	cout << "Expected result: 7.00 Lp100km and 49.00 liters" << endl;
	cout << "Actual results: " <<  kpl   << " and " <<  litToKm2    << " liters" << endl;
	
	
	
	// Testing FUNCTION 3 
	int array2[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 3};
	int *arraySec;
	
	arraySec = subArray( array2 + 3, array2 + 5 );
	
	cout << "\ntesting subArray;" << endl;
	cout << "test data: 1 2 3 4 5 6 7 8 3" << endl;
	cout << "start: index 3 finish: index 5" << endl;
	cout << "Expected result: 4 5 6" << endl;
	cout << "Actual Result:   " ;
	for ( int i = 0; i < 3; i++)
	 cout << *(arraySec + i) << " " ;
	 
	 
	// Testing FUNCTION 4 
	
	int nameSize = 4;
	string names[nameSize] = { "echo", "charlie", "bravo", "alpha" };  
	string *newNames;
	
	newNames = names;
	  
	cout << "\n\ntesting data: echo charlie bravo alpha " << endl;
	cout << "Expected Result: echo charlie bravo alpha" << endl;
	cout << "Actual Result: ";  
	
	
	

	
	
	return 0;
}




// Functions 


//***********************************************************
// function name: displayArray displays the arrays that it is passed 
//
// param-1 pointer to array
// param-2 ssize of the array
//*********************************************************** 
void displayArray( int *arr, int size)
{
	// Display the array 
	cout << "Actual Result   : " ;
	for (int i = 0; i < ARRAY_SIZE ; i++)
	{
		cout << *(arr + i) << " ";
		
	}
}


//***********************************************************
// function name:leftCircleShift moves whats in the first index 
// to the last index and shifts the array to the left 
//
// param-1 pointer to array
// param-2 ssize of the array
//***********************************************************
void leftCircleShift (int *arr, int size )
{
	int temp;
	temp = *arr;
    for(int i=0; i < size-1; i++)
    {
        *(arr + i) = *( arr + (i+1) );
    }
    *(arr + (size-1) )= temp;
    
}


//***********************************************************
// function name: litersForKm  - coverts MPG to KPL
//
// param-1 mpg given 
// param-2 km given 
// param-3 pointer 
// returns: returns kilometeres per gallon
//***********************************************************
double litersForKm ( double mpg, double km, double *lp100km)
{
	double lp100 = (100 * GALLON_LITERS) / (MILES__KILOMETERS * mpg);
	double lp1km = lp100/100;
	*lp100km = lp100;
	
	
	return lp1km * km;
}



//***********************************************************
// function name: short description of what the function does.
//
// param-1 description of first parameter (if any)
// param-2 description of second parameter (if any)
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************
int *duplicateArray (int *arr, int size) 
{
   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address
   newArray = new int [size];  //allocate new array
   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];  //copy to new array
   return newArray;
}


//***********************************************************
// function name: short description of what the function does.
//
// param-1 description of first parameter (if any)
// param-2 description of second parameter (if any)
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************
int *subArray(int *begin, int *end)
{ 
	
	int *result = duplicateArray( begin , *(end) );
	return result;

}



//***********************************************************
// function name: short description of what the function does.
//
// param-1 description of first parameter (if any)
// param-2 description of second parameter (if any)
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************

string *arrayOfPtrs ( string *array  , int size )
{
	string *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address
   newArray = new string [size];  //allocate new array
   for (int index = 0; index < size; index++)
      newArray[index] = array[index];  //copy to new array
   return newArray;
}



//***********************************************************
// function name: short description of what the function does.
//
// param-1 description of first parameter (if any)
// param-2 description of second parameter (if any)
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************


