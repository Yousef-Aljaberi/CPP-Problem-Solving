#include<iostream>
#include<string>
#include"MyLibe.h"

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

}

short CountVowels(string text)
{
	int counter = 0;
	for (short i = 0; i < text.length(); i++)
	{
		if (IsVowel(text[i]))
		{
			counter++;
		}
	}
	return counter;


}



int main()
{
	string text = InPut::PrintMessageAndReadText("Please enter string");
	cout << "\nNumber of vowels is: " << CountVowels(text);

}