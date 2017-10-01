//Amanda Koziol
//Homework 6
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//Part 1
int howManyLines(string userFile1)
{
    int numberOfLines = 0;
    string line;
    ifstream myfile(userFile1);

    while (getline(myfile, line))
        ++numberOfLines;										//This counts the number of lines in a given file
    cout << "Number of lines: " <<setw(7)<< numberOfLines <<endl;	//setw sets the number of values in the printed number
    return numberOfLines;
}




//Part 2
int countMatchingRecords(string userFile1, int lowScore1, int highScore1)			//Takes in a user inputed file, the low value for scores, and a high value
{
	int numberOfRecords = 0;
	string line;
	int x;
	int count = 1;
	ifstream myfile(userFile1);
    while (getline(myfile, line))
    {
		if (count%3 ==0)
		{
			x = stoi(line);
			if(x <= highScore1 && x >= lowScore1)										//If the students score is within the range
			{	
				numberOfRecords = numberOfRecords +1;								//Add to total count of number of records
    		}			
		}

    	count++;
	}
    cout << "Number of Records: " <<setw(7)<< numberOfRecords <<endl;			//Prints the number of records that lie within the set range
    return numberOfRecords;
}






//Part3

string gradeFromScore(string userFile)					//This function assigns a letter grade to each students numerical grade
{
    int numberOfLines = 0;
    string line;
    int x;
    int count = 1;
    string grades = "";
    ifstream myfile(userFile);							//opens the user inputed txt file
    while (getline(myfile, line))
    {
    	if (count%3 == 0)
    	{
	    	x = stoi(line);								//Turns the line from a string to an integer
    		if(x<= 100 && x>=90)
    			grades = grades + "A";
    		if(x< 90 && x>=80)
    			grades = grades + "B";
    		if(x< 80 && x>=70)
    			grades = grades + "C";
    		if(x< 70 && x>=60)
    			grades = grades + "D";
    		if(x< 60 && x>=0)
    			grades = grades + "F";
        	numberOfLines = numberOfLines + 1;    		//Each time that a letter grade is assigned, add 1 to the number of lines
   		}
    
    	count = count + 1;
	}			
    cout << "Number of Grades: " <<setw(7)<< numberOfLines <<endl;

    return grades;
}



int convertToLetterGrade(string userFile3, string outputName)
{
	ofstream outputFile(outputName);
	string letterGrade = gradeFromScore(userFile3);				//Assigns the string with the letter grades assigned in gradeFromScore
	int index = 1;
	int x;
	int numberOfLines;
	string line;
	string firstName = "";
	string lastName = "";
	int counter = 0;
    ifstream myfile(userFile3);
	while (getline(myfile, line))							//Takes three lines at a time from the user inputed list
	{ 
		if(index%3 == 1)
			firstName = line;    	
		if(index%3 ==2)
		{
			outputFile << line << ", " <<firstName << endl;		//Adds the last name and first name on one line
		}

		if(index%3 ==0)
		{
			x = stoi(line);
		   	outputFile << x << endl;								//Adds the numerical score
			outputFile << letterGrade[counter] <<endl;				//Adds the letter grade
			counter = counter + 1;
		}
    	
    	index = index + 1;										//moves up one in the letterGrade string
    }
    return counter;
}






int main()
{
	//Part 1
	string userFile;
	cout << "Enter File: " <<endl;
	cin >> userFile;
	howManyLines(userFile);

	//Part2
	string recordsFile;
	int lowScore;
	int highScore;
	cout << "Enter File: " <<endl;
	cin >> recordsFile;
	cout << "Enter Low Score: "<<endl;
	cin >> lowScore;
	cout << "Enter High Score: "<<endl;
	cin >> highScore;
	countMatchingRecords(recordsFile,lowScore,highScore);

	//Part3
	string userFile2;
	string outputName2;
	cout << "Enter File: " <<endl;
	cin >> userFile2;
	cout << "Enter Output Name: " <<endl;
	cin >> outputName2;
	convertToLetterGrade(userFile2, outputName2);


	return 0;
}

