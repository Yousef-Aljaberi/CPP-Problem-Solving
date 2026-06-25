#include<iostream>
#include<string>
#include"MyLibe.h"
using namespace std;

void PrintFirstLetterOfEachWors(string text)
{
	bool IsFirstLetter = true;
	cout << "Firsr Letter Of This String: \n";

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && IsFirstLetter)
		{
			cout << text[i] << "\n";
		}
		IsFirstLetter = (text[i] == ' ' ? true : false);
	}
}

int main()
{
	string Text = InPut::PrintMessageAndReadText("Please Enter Your String");

	PrintFirstLetterOfEachWors(Text);
}