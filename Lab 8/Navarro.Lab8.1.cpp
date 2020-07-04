
#include <iostream>
#include <string>

using namespace std;


int main()
{
	
	string input;
	char tempLetter; 
	
	cout << "Enter a sentence with all the words running together, " 
		 << "but the first character of each word is an uppercase." << endl
		 << "For EXAMPLE - StopAndSmellTheRoses" << endl;
	cin  >> input;



	for (int count = 1; count < input.length() ; count++) // starts at 1 to keep first letter cap 
		{
			tempLetter = input[count];
			
			// if uppercase character is found add a space
			if (isupper(tempLetter))
			{
				input.insert(count, 1 ,' ');  //insert space before caps add 1 beacuse of added space 
				++count; 

				//set everything after 1 to lowercase
				input[count] = tolower(input[count]);
			}
		}

	// display new string
	cout << "New String: " << input << endl;

	return 0;
}

