#include<iostream>
#include<string>
#include"MyLibe.h"

string TrimLeft(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if(text[i]!=' ')
		{
			return text.substr(i, text.length() - i);
		}
	}

	return "";
		
	
}

string TrimRight(string text)
{
	
	
	for(int i = text.length()-1; i>=0; i--)
	{
		if (text[i] != ' ')
		{
			return text.substr(0, i);
		}
	}
	return "";
	
}

string Trim(string text)
{
	return TrimLeft(TrimRight(text));
}

int main()
{
	string  text = "        Yousif  ameen Aljaberi                    ";
	cout << "\nString     = " << text ;
	cout << "\n\nTrim Left  = " << TrimLeft(text) ;

	cout << "\nTrim Right = " << TrimRight(text) ;

	cout << "\nTrim       = " << Trim(text);
	
}