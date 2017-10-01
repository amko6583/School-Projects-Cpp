//Amanda Koziol
//Assignment 4
//Michael Luzzolino
//Section 109

#include <iostream>
#include <string>
using namespace std;

//Part 1

string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

void listCodonPositions (string string1, string string2)
{
	string human;
	string mouse;
	string unknown;
	human = humanDNA;
	mouse = mouseDNA;
	unknown = unknownDNA;
	int index = 0;
	for (index = 0; index < string2.length();)              //This keeps index less than the length of string 2
	{
        //This compares the user input to groups of four for each string of DNA
		if (string1[0] == string2[index] && string1[1] == string2[index + 1] && string1[2] == string2[index + 2])
        {
            //When they perfectly match, this prints out where they match
			index = index + 1;
			cout << index << " ";   //This prints out everywhere the inputed string equals the known DNA

        }


		else
            //If they don't match, move to the next index
            index = index + 1;

	}
}
void running(string user)
{
	string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
    string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
    string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

    //This runs listCodonPositions for each different DNA and prints out the results
    cout << "Human: ";
    listCodonPositions(user, humanDNA);
    cout << endl;
    cout << "Mouse: ";
    listCodonPositions(user, mouseDNA);
    cout << endl;
    cout << "Unknown: ";
    listCodonPositions(user, unknownDNA);
    cout << endl;

}

//Part 2
float calcSimilarity(string sequence1, string sequence2)
{
    float n;
    float i;
    float score;
    n = 0;                                  //This will be the number of places that the strings are not equal
    i = 0;                                  //index values
    if (sequence1.length()!=sequence2.length())
        return 0;
    	
    while (i<sequence1.length())            //While the index is within the length of the first sequence
    {
        if (sequence1[i]!=sequence2[i])     //This gives the hamming distance
        {
            n = n+1;                        //number of places where the sequence is not the same
            i++;
        }
        else
            i++;							//else, add 1 to the index

    }
    score = (sequence1.length()-n)/sequence1.length();  //This computes the similarity score
    return score;										//Returns score to be used in other functions
}

//Part 3

float compareDNA(string user1, string DNA)				//This is comparing the users input to the different DNA strings
{
    string human;
	string mouse;
	string unknown;
	string compared;
	float score;
	int z;
	float answer;
	float answer1;
	z = user1.length();
	human = humanDNA;
	mouse = mouseDNA;
	unknown = unknownDNA;
	int i = 0;											//Starts index at zero
	int t = z;											//This is the length of the users input, which is needed for calcSimilarity to work correctly
	answer = 0;
	answer1 = 0;
	while (i < (DNA.length()-(z-1)))					//This steps by 1 index, to compare user input
    {
        compared = DNA.substr(i, t);					//This cuts us the long string into a string that is the length of the users
        answer1 = calcSimilarity(user1, compared);
        if (answer1>=answer)
        {
      
        	answer = answer1;
	    }
    	i = i+1;
    	
        
        compared = "";									//resets the portion of the long DNA string being used

    }
    return answer;



}







int main()
{
    //Running Part 1
    float score;
    float results;
    string user;
    cout << "Enter Codon:" <<endl;
    cin >> user;
    while (user != "*")         						//This will run until the user inputs *
    {
        running(user);
        cout << "Enter Codon:" <<endl;
        cin >> user;

    }
    //Part 2
    string sequence1;
    string sequence2;
    cout << "Enter sequence 1:" <<endl;
    cin >> sequence1;
    while (sequence1 != "*")         					//This will run until the user inputs *
    {   cout << "Enter sequence 2:" <<endl;
        cin >> sequence2;
        results = calcSimilarity(sequence1, sequence2);
        cout << results <<endl;
        cout << "Enter sequence 1:" <<endl;
        cin >> sequence1;
    }

    //Part 3
    string user1;
    float human1;
    float mouse1;
    float unknown1;
    float answer1;
    cout <<"Enter user sequence:"<<endl;
    cin >>user1;
    while (user1 != "*")
    {
        human1 = compareDNA(user1, humanDNA);
        mouse1 = compareDNA(user1, mouseDNA);
        unknown1 = compareDNA(user1, unknownDNA);
        if (human1>=mouse1 && human1>=unknown1)				//Comparing human to the other DNA Strings
        {
            cout << "human"<<endl;							//If it is true, print human
        }
        if (mouse1>human1 && mouse1>=unknown1)
        {
            cout << "mouse"<<endl;
        }
        if (unknown1>human1 && unknown1> mouse1)
        {
            cout << "unknown"<<endl;
        }
        
        cout <<"Enter user sequence:"<<endl;
        cin >>user1;

    }
    return 0;






}







