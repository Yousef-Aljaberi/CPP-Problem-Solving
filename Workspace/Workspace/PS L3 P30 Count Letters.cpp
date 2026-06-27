#include<iostream>
#include<string>
#include"MyLibe.h"
using namespace std;

short CountLetters(string text,char TargetChar)
{
	short count = 0;
	for (short i = 0; i < text.length(); i++)
	{
		if (text[i] == TargetChar)
			count++;
	}
	return count;
}


int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter Your String");
	char TargetChar = InPut::PrintMessageAndReadChar("Enter charecter\n");

	cout << "Letter '" << TargetChar << "' Count = " << CountLetters(text, TargetChar);
} 