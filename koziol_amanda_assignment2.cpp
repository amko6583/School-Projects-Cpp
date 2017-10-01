//Problem 1

#include <iostream>

using namespace std;

//this function is to find how much population is added for each rate
int populationChange(int rate)
{
	int popCount;
	int time;
	popCount = 0;
	time = 31536000;              //number of seconds in a year

	while(time>rate){
		popCount = popCount+1;
		time = time-rate;
	}
	return popCount;

}
//This function is plugging in each rate, and adding it to the initial population

int newPopulation(int population)
{
  	int births;
    int deaths;
    int immigrants;


	population = 307357870;             //initial US population

	births = populationChange(7);
	population = population+births;

	deaths = populationChange(13);
	population = population-deaths;

	immigrants = populationChange(35);
	population = population+immigrants;



    cout << "The total population of the US is " <<population;
    return population;
}

//Problem 2

int timeCount(int timeinput, int timeinterval)
{
	int clocktime;
	int currenttime;


	currenttime = timeinput;
	clocktime = 0;

	clocktime = timeinput/timeinterval;

	return clocktime;


}

int finaltime(int timeamount)
{
	int time;
	int hours;
	int minutes;
	int seconds;

	time = timeamount;
	hours = timeCount(time, 3600);
	time = time - (hours*3600);
	minutes = timeCount(time, 60);
	time = time - (minutes*60);
	seconds = time;

	//Printing

	cout <<"The time is " << hours << "hours, ";
	cout << minutes <<" minutes, and ";
	cout << seconds <<" seconds."<<'\n';

}
//Problem 3


void temp(float farenheit)
{
	float celsius;
	celsius = (farenheit-32.0)*5/9;
	cout << farenheit << "F";
	cout << " = " << celsius << "C";
}



int main()
{

    //Problem 1
    cout << "Problem 1" << '\n';
    newPopulation(307357870);


    //Problem 2

    cout <<'\n'<<"Problem 2" << '\n';
    int timeinput;
    cout <<"Enter number of seconds between 0 and 86400" << '\n' ;
    cin >> timeinput;
    if (timeinput > 86400)
    	cout << "Invalid input, please enter a number between 0 and 86400" << endl;
        //cin >> timeinput; <<endl;
    else if (timeinput < 0)
    	cout  << "Invalid input, please enter a number between 0 and 86400" <<endl;
    else
    	finaltime(timeinput);


    //Problem 3

    float farenheit;
    cout <<"Enter the temperature in Farenheit" <<'\n';
    cin >> farenheit;
    temp(farenheit);

}


