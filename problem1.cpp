#include <iostream>
#include <string>
using namespace std;
//Amanda Koziol
//Secion 109
//TA Michael Luzzolinio

int imputs()
{
	string noun1;
	cout <<"Enter a noun"<< endl;					//Asking for noun 1
	cin >> noun1;							//Assigns the input string to noun1

	string adj1;
	cout <<"Enter an adjective" <<endl;				//Asking for adjective 1
	cin >>adj1;							//Assigns the input string to adj1

	string noun2;
	cout <<"Enter another noun"<< endl;				//Asking for noun 2
	 cin >>noun2;							//Assigns the input string to noun2

	string adj2;
	cout <<"Enter another adjective"<<endl;			//Asking for adjective 2
	cin >> adj2;							//Assigns the input string to adj2

	cout << "It was the " << adj1;
	cout << " of " << noun1;
	cout << ", it was the " << adj2;
	cout <<" of " << noun2 <<endl;

}



int main()
{
	string question;
	cout << "Do you want to play a game? (y) or (n)" <<endl;
	cin>> question;
    while (question == "Y" or question =="y")
    {
        imputs();
        cout <<"Would you like to play again?" <<endl;
        cin>> question;
    }

	if (question == "N")
	{
		cout <<"good bye" <<endl;
	}

}
