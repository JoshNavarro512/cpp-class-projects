#include <iostream>
#include <cstring>

using namespace std;


// Function Prototypes
void upper( char line[], int LENGTH);
void lower( char line[], int LENGTH);
void flip( char line[], int LENGTH);



int main()
{
	const int LENGTH = 200;
	char line[LENGTH];
	
	// Read a string into a character array
	cout << "Enter string:  ";
	cin.getline(line, LENGTH);
	
	// Call functions 
	cout << "All Upper" << endl;
	upper(line, LENGTH);
	cout << endl;
	cout << "All Lower" << endl;
	lower(line, LENGTH);
	cout << endl;
	cout << "Flipped" << endl;
	flip( line, LENGTH);
	
	return 0;
}


void upper(char line[], int LENGTH)
{
	
  int i=0;

  char c;
  while (line[i])
  {
    c=line[i];
    putchar (toupper(c));
    i++;
  }
  
}

void lower(char line[], int LENGTH)
{
  int i=0;
  char c;
  while (line[i])
  {
    c=line[i];
    putchar (tolower(c));
    i++;
  }
	
}


void flip(char line[], int LENGTH)
{
  int i=0;
  char c;
  while (line[i])
  {
    c=line[i];
    if (islower(c)) c=toupper(c);
    else
    	c=tolower(c);
    	
    putchar (c);
    i++;
  }

}
