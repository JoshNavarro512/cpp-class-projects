#include <iostream>
#include <iomanip>

using namespace std;
	 

class Population

{

private:

int population;
int births;
int deaths;

	 

public:

void setPopulation (int);
void setBirths(int);
void setDeaths(int);

	 

int getPopulation();
double getBirthRate();
double getDeathRate();

	 

Population() : population(0), births(0), deaths(0) {}

};

	

void Population::setPopulation(int p)

{
	population = p;
}
	 

void Population::setBirths(int b)

{
	births = b;
}

	 

void Population::setDeaths(int d)

{
	deaths = d;
}

	 

int Population::getPopulation()

{
	return population;
}

	 

double Population::getBirthRate()

{
	return births / static_cast<double>(population);
}

	 

double Population::getDeathRate()

{
	return deaths / static_cast<double>(population);
}

	 



int main()

{

	Population myTown;             // instantiate one Population object

	int numPeople;
	int numBirths,
	    numDeaths;

	 

// Input, validate, and set values for myTown

	cout << "Enter total population: ";
	cin  >> numPeople;

	while (numPeople < 1)

	{   
		cout << "Value must be greater than 0.  Please re-enter: ";
	    cin  >> numPeople;
	}

	myTown.setPopulation(numPeople); 

	 

	cout << "Enter annual number of births: ";
	cin  >> numBirths;

	while (numBirths < 0)

	{   
		cout << "Value cannot be negative.  Please re-enter: ";
	    cin  >> numBirths;
	}

	myTown.setBirths(numBirths); 

	   

	cout << "Enter annual number of deaths: ";
	cin  >> numDeaths;

	while (numDeaths < 0)

	{   
		cout << "Value cannot be negative.  Please re-enter: ";
	    cin  >> numDeaths;
	}

	myTown.setDeaths(numDeaths);

	 

// Display statistics 

	cout << "\nPopulation Statistics  ";        

	cout << fixed << showpoint  << setprecision(3);

	cout << "\n\tPopulation:  " << setw(7) << myTown.getPopulation();

	cout << "\n\tBirth Rate:  " << setw(7) << myTown.getBirthRate();

	cout << "\n\tDeath Rate:  " << setw(7) << myTown.getDeathRate() << endl;

	 

	return 0;

}

	 


