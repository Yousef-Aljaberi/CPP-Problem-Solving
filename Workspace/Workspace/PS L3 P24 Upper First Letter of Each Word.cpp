#include<iostream>
#include<string>
#include"MyLibe.h"
using namespace std;



string UpperFirstLeeterOfEachWord(string text)
{
	bool IsFirstLetter = true;
	for (short i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && IsFirstLetter)
		{
			text[i] = toupper(text[i]);
		}

		IsFirstLetter = (text[i] == ' ' ? true : false);
	}
	return text;
}


int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter a Text");
	text = UpperFirstLeeterOfEachWord(text);
	cout << "String after conversion: \n";
	cout << text << endl;
	


	system("paus>0");;

}
