#include<iostream>
#include<cstdio>
#include"MyLibe.h"

string UpperAllLetterOfString(string text)
{
	for (short i = 0; i < text.length(); i++)
	{
		
			text[i] = toupper(text[i]);
		
	}
	return text;
}

string LowerAllLetterOfString(string text)
{
	for (short i = 0; i < text.length(); i++)
	{
		
			text[i] = tolower(text[i]);
		
	}
	return text;

}

int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter Your Text");

	text = UpperAllLetterOfString(text);
	cout << "\n String after upper\n";
	cout << text << endl;

	text = LowerAllLetterOfString(text);
	cout << "\n String after lower\n";
	cout << text << endl;

}