#include<iostream>
using namespace std;
int ReadNumber(string Message)
{
	int n = 0;
	do
	{
		cout << Message << endl;
		cin >> n;
	} while (n <= 0);
	return n;
}


int  RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enum enCharType { smallLetter = 1, CapitalLetter = 2, SpecialC = 3, Number = 4 };

char GetRandomChar(enCharType charType)
{
	switch (charType)
	{
	case enCharType::CapitalLetter:
	{	return char(RandomNumber(65, 90));
	break;
	}
	case enCharType::smallLetter:
	{	return char(RandomNumber(97, 122));
	break;
	}
	case enCharType::SpecialC:
	{	return char(RandomNumber(33, 47));
	break;
	}
	case enCharType::Number:
	{	return char(RandomNumber(48, 57));
	break;
	}
	}
}


string generateWord(enCharType charType, short Lenght)
{
	string word = "";
	for (int i = 1; i <= Lenght; i++)
	{
		word += GetRandomChar(charType);
	}
	return word;
}

string GenerateKey()
{
	string key = "";
	key = key + generateWord(CapitalLetter, 4) + '_';
	key = key + generateWord(CapitalLetter, 4) + '_';
	key = key + generateWord(CapitalLetter, 4) + '_';
	key = key + generateWord(CapitalLetter, 4);
	return key;
}
void GenerateKeys(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		cout << "Key [" << i << "] : " << GenerateKey() << endl;
	}

}
int main()
{
	GenerateKeys(ReadNumber("Please enter the of keys you want to generate"));
}


