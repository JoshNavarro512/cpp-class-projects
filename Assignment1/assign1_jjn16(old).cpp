// File Name: assign1_jjn16.cpp
// 
// Author: Joshua Navarro
// Date: 8/23/2018
// Assignment Number: 1
// CS 2308.004 Fall 2018
// Instructor: Jill Seaman 
// 
// Helps a student keep track of monthly budget by keeping of table of expenses 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// struct to make the different categories 
struct category
{
	string name;
	float allocatedAmount,
	      amountSpent,
		  over_under;
};

// Function Prototypes
void showOverUnder(category tableFields[], int);
void displayTable(category tableFields[], int);
int computeSelection(category tableFields[], int);

// Constant Variables
const float HOUSING_ALLOCATED = 500,
            UTILITIES_ALLOCATED = 150,
            TRANSPORTATION_ALLOCATED = 50,
            FOOD_ALLOCATED = 250,
            ENTERTAIMENT_ALLOCATED = 150,
            MISCELLANEOUS_ALLOCATED = 50;
const int   ARRAY_SIZE = 6;

int main()
{
	
    // For under/over starting values 
	float spent_base = 0,
		  housing_base = HOUSING_ALLOCATED,
		  utilities_base = UTILITIES_ALLOCATED,
		  transportation_base = TRANSPORTATION_ALLOCATED,
		  food_base = FOOD_ALLOCATED,
		  entertaiment_base = ENTERTAIMENT_ALLOCATED,
		  miscellaneous_base = MISCELLANEOUS_ALLOCATED;

	
    // Allocating the struct array with base data 
	category tableFields[ARRAY_SIZE];
	tableFields[0] = {"Housing", HOUSING_ALLOCATED, spent_base, housing_base};
	tableFields[1] = {"Utilities", UTILITIES_ALLOCATED, spent_base, utilities_base};
	tableFields[2] = {"Transportation", TRANSPORTATION_ALLOCATED, spent_base, transportation_base};
	tableFields[3] = {"Food", FOOD_ALLOCATED, spent_base, food_base};
	tableFields[4] = {"Entertainment", ENTERTAIMENT_ALLOCATED, spent_base, entertaiment_base};
	tableFields[5] = {"Miscellaneous", MISCELLANEOUS_ALLOCATED, spent_base, miscellaneous_base};
	
	
	// Calling the table function to display the table at the beginning of the program
	displayTable(tableFields, ARRAY_SIZE);
	
	// Takes user info and changes the table
	computeSelection(tableFields, ARRAY_SIZE);
	
	
	
	
	
	
	return 0;
}




//***********************************************************
// function name: displayTable
//
// param-1 tablr array
// param-2 array size
// 
// Displays Budget Table 
//***********************************************************
void displayTable( category table[], int size)
{
	
	
	// Table
	cout << fixed << showpoint << setprecision(2);
	cout << left <<setw(30) << "    Category" << setw(15) << "Allocated" << setw(10) << "Spent" << setw(10) << "over/under" << endl;
	cout << "_________________________________________________________________" << endl;
	cout << "1. " << setw(27) << table[0].name << setw(30) << setw(15) << table[0].allocatedAmount << setw(10) << table[0].amountSpent << setw(10) << table[0].over_under << endl;
	cout << "2. " << setw(27) << table[1].name << setw(30) << setw(15) << table[1].allocatedAmount << setw(10) << table[1].amountSpent << setw(10) << table[1].over_under << endl;
	cout << "3. " << setw(27) << table[2].name << setw(30) << setw(15) << table[2].allocatedAmount << setw(10) << table[2].amountSpent << setw(10) << table[2].over_under << endl;
	cout << "4. " << setw(27) << table[3].name << setw(30) << setw(15) << table[3].allocatedAmount << setw(10) << table[3].amountSpent << setw(10) << table[3].over_under << endl;
	cout << "5. " << setw(27) << table[4].name << setw(30) << setw(15) << table[4].allocatedAmount << setw(10) << table[4].amountSpent << setw(10) << table[4].over_under << endl;
	cout << "6. " << setw(27) << table[5].name << setw(30) << setw(15) << table[5].allocatedAmount << setw(10) << table[5].amountSpent << setw(10) << table[5].over_under << endl;
	
	
	
}






//***********************************************************
// function name: computeSelection
//
// param-1 table array
// param-2 array size
//
//Takes user updates the Budget table accordingly 
//***********************************************************
int computeSelection(category table[], int size)
{
	int   choice_input =0;
	float amount;
	

	    
	    	
	while (choice_input != 8)
	{
	    //  Asks user what category the want 
		cout << "\nEnter the number of a category to record money spent or" << endl;
		cout << "7 to display the table or \n" << "8 to quit." << endl;
		cout << "  " << endl;
	    cin  >> choice_input;
	    
        // Validates user input to make sure they entered a number 1 - 8	    
		while ((choice_input < 1) || (choice_input > 8))
		{
			cout << "Please Enter numers 1-8: ";
			cin  >> choice_input;
	    }
	    


        // Switch to process the user input for what category they wnat to add expenses to 
		if (choice_input != 8)
		{
		    
		    
			switch (choice_input)
			{
				case 1: cout << "Enter the amout to add to that category: ";
	                    cin  >> amount;
				        table[0].amountSpent += amount;
				        table[0].over_under -= amount;
					    break;
				case 2: cout << "Enter the amout to add to that category: ";
	                    cin >> amount;
				        table[1].amountSpent += amount;
				        table[1].over_under -= amount;
					    break;
				case 3: cout << "Enter the amout to add to that category: ";
	                    cin >> amount;
						table[2].amountSpent += amount;
						table[2].over_under -= amount;
						break;
				case 4: cout << "Enter the amout to add to that category: ";
	        			cin >> amount;
						table[3].amountSpent += amount;
						table[3].over_under -= amount;
						break;
				case 5: cout << "Enter the amout to add to that category: ";
	        			cin >> amount;
						table[4].amountSpent += amount;
						table[4].over_under -= amount;
						break;	
				case 6: cout << "Enter the amout to add to that category: ";
	        			cin >> amount;
						table[5].amountSpent += amount;
						table[5].over_under -= amount;
						break;	
				case 7: displayTable(table, size);
						break;		
			}
	    }
	    
		
	}
	
	showOverUnder(table, ARRAY_SIZE );
}

//***********************************************************
// function name: showOverUnder
//
// param-1 table array
// param-2 array size
//
// Adds up the over/under amount for it to be displayed if 8 is pressed 
//
//***********************************************************

void showOverUnder(category table[], int ARRAY_SIZE )
{
	int   monthlyBudget  = 1150;
	float monthlySpent;
	
	monthlySpent = table[0].amountSpent + table[1].amountSpent + table[2].amountSpent + table[3].amountSpent + table[4].amountSpent + table[5].amountSpent;
	
	cout << "\nThis month you spent a Total of $" << monthlySpent << endl;
	
	if ( monthlySpent < monthlyBudget )
	{
		cout << "For the month you are under budget by $" << monthlyBudget - monthlySpent << endl;
		
	}
	else 
	{
		cout << "For the month you are over budget by $" << monthlyBudget - monthlySpent << endl;
	}
	
}










