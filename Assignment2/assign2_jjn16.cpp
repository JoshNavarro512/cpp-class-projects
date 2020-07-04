// File Name: assign2_jjn16.cpp
//
// Author: Joshua Navarro
// Date: 9/19/2018
// Assignment Number: 2
// CS 2308.004 Fall 2018
// Instructor: Jill Seaman
//
// This Program records arrivals and departures of lab staff into research lab


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;




// Events struct

struct Employees
{
	int    id;
	string name,
		   time;

};

// Function Prototypes
void idSort(Employees dataArray[], int );
void timeSort(Employees dataArray[], int );
int idSearch(Employees dataArray[], int size, int value);
int presence(Employees dataArray[], int size, int value);

// Global Const

const int ARRAY_SIZE = 100,
		  NUM_OPTIONS = 5 ;


int main()
{

	Employees dataLog[ARRAY_SIZE];

	ifstream inputFile;
	int number,
		choice;
	int count = 0;


	// Open the file.
    inputFile.open("dataset100.txt");



    // Read the numbers from the file and
    // and put them into struct array.
    while ( inputFile >> dataLog[count].id)
    {

	    inputFile >> dataLog[count].name;
		inputFile >> dataLog[count].time;

        count++;
	}



	// Display Menu and gets Choice from the user
	do
   {
      // Display the menu.
      cout << "\nMenu" 										 << endl;
	  cout << " "											 << endl;
	  cout << "1. Display events sorted by ID"               << endl;
	  cout << "2. Display events sorted by time"             << endl;
	  cout << "3. Lookup a person by ID"                     << endl;
	  cout << "4. Lookup the presence of the person by ID"   << endl;
	  cout << "5. Quit the Program"						     << endl;
	  cout << " "											 << endl;
	  cout << "Enter your choice: "                          << endl;
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > NUM_OPTIONS)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;

      }

      // Validate and process the user's choice.
      if (choice != NUM_OPTIONS)
      {

         // Respond to the user's menu selection.
         switch (choice)
         {
            case 1:

				idSort(dataLog, count);
				for (int index = 0; index < count; index++)
				{
					cout << setw(5) << dataLog[index].id << " " << setw(10) << dataLog[index].name
					     << " " << setw(10) << dataLog[index].time << endl;
				}
                break;
            case 2:
                timeSort(dataLog, count);
				for (int index = 0; index < count; index++)
				{
					cout << setw(5) << dataLog[index].id << " " << setw(10) << dataLog[index].name
					     << " " << setw(10) << dataLog[index].time << endl;
				}
                break;
            case 3: int value,
						positionNum;
            		idSort(dataLog, count);
            		cout << "Enter id of a person to look for: " ;
            		cin  >> value;
            		positionNum = idSearch( dataLog, count, value);

            		cout << "\nThe name of the person with ID " << value << " is: " << dataLog[positionNum].name << endl;
                break;
            case 4: int idValue,
						numFound;
            		idSort(dataLog, count);
            		cout << "Enter id of a person to look for: " ;
            		cin  >> idValue;
            		numFound = presence( dataLog, count, idValue);


            		if ( numFound % 2 == 0)
            			cout << "The person with ID: " << idValue << " is absent from the lab" << endl;
            		else
            		    cout << "The person with ID: " << idValue << " is present in the lab" << endl;

                break;
         }

      }
   } while (choice != NUM_OPTIONS);



   // Close the file.
   inputFile.close();




	return 0;

}




//***********************************************************
// isSort: Sorts the struct array by ID number
//
// param-1 the struct array
// param-2 size of array based on how many were in the file
//
//***********************************************************

void idSort(Employees dataArray[], int size)
{
   bool swap;
   Employees temp;

   do
   {
      swap = false;
      for (int i = 0; i < (size - 1) ; i++)
      {
         if (dataArray[i].id > dataArray[i + 1].id)
         {
            temp = dataArray[i];
            dataArray[i] = dataArray[i + 1];
            dataArray[i + 1] = temp;
            swap = true;
         }

      }

   } while (swap) ;

}


//***********************************************************
// isSort: Sorts the struct array by Time
//
// param-1 the struct array
// param-2 size of array based on how many were in the file
//***********************************************************

void timeSort(Employees dataArray[], int size)
{
   bool swap;
   Employees temp;

   do
   {
      swap = false;
      for (int i = 0; i < (size - 1) ; i++)
      {
         if (dataArray[i].time > dataArray[i + 1].time)
         {
            temp = dataArray[i];
            dataArray[i] = dataArray[i + 1];
            dataArray[i + 1] = temp;
            swap = true;
         }

      }

   } while (swap) ;

}



//***********************************************************
// idSearch: Looks for a person by ID number
//
// param-1 the struct array
// param-2 size of array based on how many were in the file
// param-3 the ID number from the user
//***********************************************************


int idSearch(Employees dataArray[], int size, int value)
{
   int first = 0,             // First array element
       last = size - 1,       // Last array element
       middle,                // Mid point of search
       position = -1,
	   timesFound = 0;         // Position of search value
   bool found = false;        // Flag

   while (!found && first <= last)
   {
      middle = (first + last) / 2;     // Calculate mid point
      if (dataArray[middle].id == value)      // If value is found at mid
      {
         found = true;
         position = middle;
         timesFound++;
      }
      else if (dataArray[middle].id > value)  // If value is in lower half
         last = middle - 1;
      else
         first = middle + 1;           // If value is in upper half
   }
   return position;
}


//***********************************************************
// function name: short description of what the function does.
//
// param-1 description of first parameter (if any)
// param-2 description of second parameter (if any)
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************


int presence(Employees dataArray[], int size, int value)
{

   int counter = 0;
    for(int i = 0; i < size; i++)
        if(dataArray[i].id == value)
            counter++;


    return counter;

}
