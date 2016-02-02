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
string Encryption_function(string message, int* encrypt, int len);
void Storing_message(string msg, int len, int* key);
string Decryption_function();

int main()
{//This is where the magic happens
	string message;
	int* encrpyt_ratio;
	message = Input_function();
	int length = message.length();
	encrpyt_ratio = new int[length];
	message = Encryption_function(message, encrpyt_ratio, length);
	Storing_message(message, length, encrpyt_ratio);
	message = Decryption_function();
	cout << "The message is:\n" << message << endl;
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
	cout << "You have entered: " << message << "\nIs this correct?\nyes(y), no(n)\n";
	cin >> response;
	if (response == 'y' | response == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Encryption_function(string message, int* encrypt, int len)
{//This function is used to encrypt the message.
	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		int encrypter_factor = rand() % 10 + 1;
		message[i] = message[i] + encrypter_factor;
		encrypt[i] = encrypter_factor;
	}
	return message;
}

void Storing_message(string msg, int len, int* key)
{//This function is used to store the encrypted message for future use. It store the encrypted message to a file and the key to another.
	ofstream output;
	output.open("Encrypted_Message.txt", ios::out | ios::app);
	output << msg;
	output << endl;
	output.close();
	output.open("Key_File.txt", ios::out | ios::app);
	for (int i = 0; i < len; i++)
	{
		output << key[i] << " ";
	}
	output << endl;
	output.close();
}

string Decryption_function()
{//This function is used to decrypt the encrypted message on the next end.
	ifstream input1, input2;
	input1.open("Encrypted_Message.txt");
	input2.open("Key_File.txt");
	string msg, tmp;
	while (!input1.eof())
	{
		getline(input1, tmp);
		int len = tmp.length();
		int* key = new int[len];
		for (int j = 0; j < len; j++)
		{
			input2 >> key[j];
		}
		for (int i = 0; i < len; i++)
		{
			tmp[i] = tmp[i] -  key[i];
		}
		if (msg == "")
		{
			msg = tmp;
		}
		else
		{
			msg = msg + " " + tmp;
		}
	}
	input1.close();
	input2.close();
	return msg;
}