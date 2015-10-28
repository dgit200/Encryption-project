// Dwight Thomas Encryption Program //

#include <string.h>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

string Input_function();
bool Message_is_correct(string message);

int main()
{//This is where the magic happens
	string message;
	message = Input_function();
	system("pause");
	return 0;
}

string Input_function()
{//This function is used to collect the input data to be encrypted
	string Input;
	bool confirmation;
	cout << "Enter the message that you like to be encrypted:\n";
	cin.clear();
	cin.ignore();
	getline(cin, Input);
	confirmation = Message_is_correct(Input);
	if (confirmation)
	{
		return Input;
	}
	else
	{
		Input = Input_function();
		return Input;
	}
}

bool Message_is_correct(string message)
{// This function runs a confirmation to ensure the data entered was correct
	
	char response;
	cout << "You have enter: " << message << "\nIs this correct?\nyes(y), no(n)\n";
	cin >> response;
	if (response == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}