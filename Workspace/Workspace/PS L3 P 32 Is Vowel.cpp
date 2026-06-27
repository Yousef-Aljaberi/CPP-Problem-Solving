#include<iostream>
#include<string>
#include"MyLibe.h";
using namespace std;




bool IsVowel(char Ch1)
{
	Ch1 =  tolower(Ch1);
	return((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

}


int main()
{
	char TargetLetter = InPut::PrintMessageAndReadChar("Please enter char to see is it vowel or not");

	if (IsVowel(TargetLetter))
	{
		cout << "YES: Letter '" << TargetLetter << "' is Vowel" << endl;
	}
	else
	{
		cout<<"No: Letter '" << TargetLetter << "' is Not Vowel" << endl;
	}

}