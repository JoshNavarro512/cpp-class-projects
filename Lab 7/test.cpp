
#include <iostream>

using namespace std;

// Function prototype
int *getRandomNumbers(int);

int main()
{
   int *numbers = nullptr;  // To point to the numbers
   int n;
   
   cout << "Enter size: ";
   cin  >> n;
   
   // Get an array of five random numbers
   numbers = getRandomNumbers(n);
   
   // Display the numbers
   for (int count = 0; count < n; count++)
      cout << numbers[count] << endl;

   // Free the memory
   delete [] numbers;
   numbers = nullptr;
   return 0;
}


int *getRandomNumbers(int size)
{
   int *array = nullptr;    // Array to hold the numbers
   
   // Return nullptr if size is zero or negative
   if (size <= 0)
      return nullptr;
   
   // Dynamically allocate the array
   array = new int[size];
   
   
   // Populate the array with random numbers
   for (int count = 0; count < size; count++)
      array[count] = count + 1;
      
   // Return a pointer to the array
   return array;
}
