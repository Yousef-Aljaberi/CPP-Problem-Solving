#include<iostream>
#include<cstdio>
#include"MyLibe.h"

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InverAllLettersCase(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = InvertLetterCase(text[i]);
	}
	return text;
}

int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter  Your String\n");
	text = InverAllLettersCase(text);
	cout << "String after invert all letter\n";
	cout << text << endl;
}