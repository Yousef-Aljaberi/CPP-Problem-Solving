#include<iostream>
#include<string>

using namespace std;

string RemovePunctuations(string text)
{
	string S1 = "";
	for (int i = 0; i < text.length(); i++)
	{
		if (!ispunct(text[i]))
		{
			S1+= text[i];
		}
	}
	return S1;
}


int main()
{
	string text = "Welcom to Yemen, Yemen is a nice country; it's amazing.";
	cout << "\nOriginal string:\n" << text;
	cout << "\n\n Removed Punctuatioin\n";
	cout<<RemovePunctuations(text);
}