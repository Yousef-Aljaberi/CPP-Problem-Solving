#include<iostream>
#include<cstdio>
#include"MyLibe.h"

char InvertCharecterCase(char L)
{
	return isupper(L) ? tolower(L) : toupper(L);
}

int main()
{
	char L;
	cout << "Enter a charecter" << endl;
	cin >> L;
	L= InvertCharecterCase(L);
	cout << "\n Char after inverting case:\n";
	cout << L << endl;
}