// This program will accept the four sales figures from each division 
// as parameters and determine which is the highest of the four
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function Prototypes
double getSales(string);
void findHighest(double, double, double, double);

int main()
{
	double NE, SE, NW, SW;


	// Call function getSales for each division.
	NE = getSales("Northeast");
	SE = getSales("Southeast");
	NW = getSales("Northwest");
	SW = getSales("Southwest");


	// Call function findHighest 
	findHighest(NE, SE, NW, SW);
	return 0;
}

// Get sales function gets passed the division name and asks the user
// to enter the sales

double getSales(string Division)
{
	double Sales;

	do
	{
		cout << "Enter the quarterly sales for the " << Division << " division: ";
    	cin  >> Sales;

    	if (Sales < 0.00)
    	cout << "Sales figures cannot be negatve. Please re-enter.\n";

    } while (!(Sales > 0.00));
    return Sales;
}

// This function finds the division with the highest sales 

void findHighest(double NE, double SE, double NW, double SW)
{
	double Hightest;
 
 	cout << "\nThe ";

	if (NE > SE && NE > NW && NE > SW)
	{
		Hightest = NE;
		cout << "Northeast ";
	}
	else if (SE > NE && SE > NW && SE > SW)
	{
		Hightest = SE;
		cout << "Southeast ";
	}
	else if (NW > SE && NW > NE && NW > SW)
	{
		Hightest = NW;
		cout << "Northwest ";
	}
	else
	{
		Hightest = SW;
		cout << "Southwest ";
	}
    
	cout << fixed << showpoint << setprecision(2);
	cout << "division had the highest sales this quarter.\n" 
	     << "Their sales were $" << Hightest ;
}
