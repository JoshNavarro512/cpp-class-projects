// This program gets a list of names from the user and 
// gives the first and last person on the list in alphabetical order

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Setting the max and min number students that
// can be entered
const int MIN_SUTDENTS = 1,
		  MAX_STUDENT = 20;

int main()
{

	// Define variables
	int num_students;
	ifstream inputFile;
	string studentName,
		   firstStudent,
		   lastStudent;
	
	// open file 
	inputFile.open("LineUp.txt");
	
		
	// Get the number of student that are going to be entered
	cout << "Enter the number of students has to be between 1 and 20: ";
	cin  >> num_students;
	
	// Validate if the number of students is correct
	while (num_students < 1 || num_students > 20)
	{
		cout << "Number must be between 1 and 20. " 
			 << "Re-enter the number of students: ";
		cin  >> num_students;
	}
	
	// Setting up the loop for the number of students
	for (int i = 1; i <= num_students; i++)
	{
		inputFile >> studentName;
		
		// Grab the first name 
		if ( i == 1)
		{
			firstStudent = studentName;
			lastStudent = studentName;
		}
		else		// Compare each name to the next and replace 
		{
			if (studentName < firstStudent) 		// less beacuse A is a smaller than Z ASCII
				firstStudent = studentName;
			else if (studentName > lastStudent)		// more beacause Z is bigger than A
				lastStudent = studentName;
		}
		
		
	}
	
	// Display the fisrt and last student 
	cout << "First student is " << firstStudent << endl; 
	cout << "Last Student is " << lastStudent << endl;
	
	inputFile.close(); // close the file 
	return 0;
}
