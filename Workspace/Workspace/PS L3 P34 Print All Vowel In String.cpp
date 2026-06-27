#include<iostream>
#include<string>
#include"MyLibe.h"


bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

}

void CountVowels(string text)
{
	cout << "\nVowels Letters in string is/are: ";
	for (short i = 0; i < text.length(); i++)
	{
		if (IsVowel(text[i]))
		{
			cout << text[i] << "	";
		}
	}

	
}



int main()
{
	string text = InPut::PrintMessageAndReadText("Please enter string");
	
	CountVowels(text);
}