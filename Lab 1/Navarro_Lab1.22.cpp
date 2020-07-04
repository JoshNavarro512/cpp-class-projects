// This program calculates how many slices a pizza can be 
// divided into based on the size given by the user 

#include <iostream>
#include <cmath>
using namespace std;


// Declare contants 
const float SLICE_AREA = 14.125, PI = 3.14;


main ()

{ 	
	// Declare variables 
	double diameter, radius, pizza_area, num_slices;
	
	// Ask the user for the diameter of the pizza in inches
	cout << "What is the Diameter of the pizza in inches? ";
	cin  >> diameter;
	cout << endl;
	
	// Calculating the radius
	radius = diameter / 2;
	
	// Calculating the area of the whole pizza 
	pizza_area = PI * pow(radius, 2);
	
	num_slices = pizza_area / SLICE_AREA;
	
	cout << "For a pizza with an area of " << pizza_area << " you get " << int(num_slices) << " slices";
	
	
	
	return 0;
}
