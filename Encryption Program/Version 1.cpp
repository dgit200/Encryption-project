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
string Encryption_function(string message, int* encrypt);

int main()
{//This is where the magic happens
	string message;
	int* encrpyt_ratio;
	message = Input_function();
	encrpyt_ratio = new int[message.length()];
	message = Encryption_function(message, encrpyt_ratio);
	system("pause");
	return 0;
}

string Input_function()
{//This function is used to collect the input data to be encrypted
	string Input;
	bool confirmation;
	cout << "Enter the message that you like to be encrypted:\n";
	getline(cin, Input);
	confirmation = Message_is_correct(Input);
	if (confirmation)
	{
		return Input;
	}
	else
	{
		cin.ignore();
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

string Encryption_function(string message, int* encrypt)
{
	srand(time(0));
	int len = message.length();
	for (int i = 0; i < len; i++)
	{
		int encrypter_factor = rand() % 10 + 1;
		message[i] = message[i] + encrypter_factor;
		encrypt[i] = encrypter_factor;
	}
	return message;
}