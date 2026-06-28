#include<iostream>
#include<string>
#include<vector>
using namespace std;

string ReplaceWordInString(string text, string StringToReplace, string sReplaceTo)
{
	short pos = text.find(StringToReplace);
	while (pos != std::string::npos)
	{
		text = text.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = text.find(StringToReplace);
	}
}

int main()
{
	string text = "Welcom to Yemen, Yemen is a nice country; it's amazing.";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";



	cout << "\nOriginal String: \n" << text;
	cout << "\n\n String after replace:";
	cout << "\n" << ReplaceWordInString(text, StringToReplace, ReplaceTo);
}