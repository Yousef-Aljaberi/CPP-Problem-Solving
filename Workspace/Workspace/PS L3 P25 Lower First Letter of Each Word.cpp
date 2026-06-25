#include<iostream>
#include<string>
#include"MyLibe.h"
using namespace std;


string LowerFirstLetterOfEachWord(string text)
{
	bool IsFirstLetter = true;
	for (short i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && IsFirstLetter)
		{
			text[i] = tolower(text[i]);
		}
		IsFirstLetter = (text[i] == ' ' ? true : false);
	}
	return text;
}


int main()
{
	string text = InPut::PrintMessageAndReadText("Please enter  your string:\n");
	text = LowerFirstLetterOfEachWord(text);
	cout << "\nText after conversion:\n";
	cout << text;

}