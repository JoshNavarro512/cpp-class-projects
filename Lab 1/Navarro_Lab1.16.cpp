// This program calculates the monthly sales and tax 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

main ()
{
	
	// Declare variable 
	double total_cash, sales, county_tax, state_tax, total_tax, year;
	// Define String
	string month; 
	
	// Ask user for the Month
	cout << "Please enter the month: ";
	cin  >> month;
	cout << endl;
	
	// Ask user for the year 
	cout << "Enter the year: ";
	cin  >> year;
	cout << endl;
	
	// Ask for the total cash amount (that is sales plus sales tax)
	cout << "Enter the total sales amount (this is sales plus sales tax): $ ";
	cin  >> total_cash;
	cout << endl;
	
	// Calculate the sales for the month ( total cash / 1.06 ) 
	sales      = total_cash / 1.06;
	
	total_tax  = total_cash - sales;
	
	county_tax = sales * 0.02;
	
	state_tax  = sales * 0.04;
	
	
	// Display output
	cout << "Month: " << month << "	"<< year << endl; 
	cout << "_______________________________" << endl;
	cout << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Total Collected:		$ " << setw(10) << total_cash << endl;
	cout << "Sales:				$ " <<     setw(10) << sales      << endl;
	cout << "County Sales Tax:		$ " << setw(10) << county_tax << endl;
	cout << "State Sales Tax:		$ " << setw(10) << state_tax  << endl;
	cout << "Total Sales Tax:		$ " << setw(10) << total_tax  << endl << endl; 
	
	
	
	return 0;
}
