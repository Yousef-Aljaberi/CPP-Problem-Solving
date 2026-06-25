#include<iostream>
#include<cstdio>
#include"MyLibe.h"

int CountCapitalLetters(string text)
{
	int Count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
			Count++;
	}
	return Count;
}

int CountSmallLetters(string text)
{
	int Count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (islower(text[i]))
			Count++;
	}
	return Count;
}



int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter String\n");

	int CapitalLetters = 0, SmallLetters = 0;
	CapitalLetters = CountCapitalLetters(text);
	SmallLetters = CountSmallLetters(text);
	cout << "\nString length =     " << text.length();
	cout << "\n Capital letters  count =	" << CapitalLetters << endl;
	cout << "\n Small letters  count =	" << SmallLetters << endl;


}
