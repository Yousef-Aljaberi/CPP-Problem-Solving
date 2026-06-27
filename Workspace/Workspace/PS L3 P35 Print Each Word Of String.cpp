#include<iostream>
#include<string>
#include"MyLibe.h"

void PrintEachWordOfString(string text)
{
	int pos = 0;
	string delim = " ";			//delimiter
	string sWord;				//define a string varible

	//use find() functioin to get delimiter position 
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);  //store the word
		if (sWord != "")
		{
			cout << sWord << endl;
		}

		text.erase(0, pos + delim.length()); //erase until position and move to next word.

	}
	if (text != "")
	{
		cout << text << endl;   //it print last word of the string 
	}
	
}



int main()
{
	PrintEachWordOfString(InPut::PrintMessageAndReadText("Please enter text to print each word of it "));
}
