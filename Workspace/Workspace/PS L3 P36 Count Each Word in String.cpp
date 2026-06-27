#include<iostream>
#include<string>
#include"MyLibe.h"

short CountEachWordOfString(string text)
{
	short Count = 0;

	short pos = 0;
	string delim = " ";
	string sWord;
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			Count++;
		}
		text.erase(0, pos + delim.length());
	}

	if (text != "")
	{
		Count++;
	}
	return Count;
}

int main()
{
	cout << "\nNumber of Words in this string are/is: " << CountEachWordOfString(InPut::PrintMessageAndReadText("Please emter text to count how many words are in this text"));
}