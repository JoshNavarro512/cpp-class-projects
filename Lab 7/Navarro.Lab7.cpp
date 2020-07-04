// This program gets the number of movies studensts
// watch a month and gives the average

#include <iostream>
#include <algorithm>

using namespace std;

// Funtion Prototypes
int *getNumMovies(int);
void sortList (int *numbers , int numStudents);
void displayList (int *numbers, int); 
double average(int*numbers , int numStudents);


main()
{
	
	int *numbers = nullptr;	 // To point to the numbers 
	int numStudents;
	double averageMovies;
	
	
	// Get the number of Students
	cout << "Enter the number of Students: ";
	cin  >> numStudents;
	// validate the number of students is positive
	while ( numStudents < 0)
	{
		cout << "The number of students has to be positive. Re-enter number: ";
		cin  >> numStudents;
	}
	
	
	// Get an array of n
	numbers = getNumMovies(numStudents);
	// Sort the list
	sortList(numbers, numStudents);
	// Diaplay List 
	displayList(numbers , numStudents);
	averageMovies = average(numbers, numStudents);
	
	
	// Display the average
	cout << "_________________" << endl;
	cout << "Average  " << averageMovies << endl;
	
	// Free the memory
	delete [] numbers;
	numbers = nullptr;
	
	return 0;
}

// This function gets number of movies whatched by each student
int *getNumMovies (int size)
{
	int *array = nullptr;  // Array to hold num movies
	int numMovies;
	
	// Return nullptr of size is zero or negative 
	if (size <= 0)
		return nullptr;
		
	// Dynamically allocate  the array
	array = new int[size];
	
	// Get the number of movies from the user
	cout << "Enter the number of movies per month each student watched: " << endl; 
	for (int count = 0; count < size; count++)
	{
		cout << "Number of movies for student " << (count +1) << ": "; 
		cin  >> array[count];
		
	}
	// Return pointer to the array
	return array;
	
}



// This function sorts the array in ascending order
void sortList (int *numbers ,  int numStudents)
{
	sort(numbers, numbers + numStudents);
}

// This function displays the sorted list
void displayList (int *numbers, int numStudents)
{
	cout << "\nNumber of Movies Watched" << endl;
	cout <<"______________________" << endl;
	for (int i = 0; i < numStudents ; i++)
	{
		cout << *numbers++ << endl;
	}
	
}
// This function calculates the number of movies watched 
// and returns it to the main function
double average(int *numbers, int numStudents)
{
	double average;
	int total;
	
	
	for (int i = 0; i < numStudents ; i++)
	{
		total += *numbers++;
	}
	
	average = total / numStudents;
	return average;
}


































