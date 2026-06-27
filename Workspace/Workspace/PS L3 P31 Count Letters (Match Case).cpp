#include<iostream>
#include<string>
#include"MyLibe.h";
using namespace std;

char InvertCharecterCase(char L)
{
	return isupper(L) ? tolower(L) : toupper(L);
}


short CountLetter(string text, char TargetLetter,bool NoMatchCase=true)
{
	short Count = 0;
	for (short i = 0; i < text.length(); i++)
	{
		if (NoMatchCase)
		{
			if (text[i] == TargetLetter)
			{
				Count++;
			}
		}
		else if(!NoMatchCase)
		{
			if (tolower(text[i]) == tolower(TargetLetter))
				Count++;
		}
	}
	return Count;
}

int main()
{
	string text = InPut::PrintMessageAndReadText("Please enter string");
	char TargetLetter = InPut::PrintMessageAndReadChar("Enter a Charector");

	cout << "\n\n The letter '" << TargetLetter << "' Count = " << CountLetter(text, TargetLetter);
	cout << "\n\n The letter '" << TargetLetter << "' or '" << InvertCharecterCase(TargetLetter) << "' Count = " << CountLetter(text, TargetLetter, false);
	
}