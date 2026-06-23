#include<iostream>
using namespace std;
string ReadPassWord(string Message)
{
	string PassWord = "";
	cout << Message << endl;
	cin >> PassWord;
	return PassWord;
}
int Count = 0;
bool GusPassWord(string PassWord)
{
	string GusWord = "";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				GusWord = GusWord + char(i);
				GusWord = GusWord + char(j);
				GusWord = GusWord + char(k);

				cout << "Trail [" << ++Count << "] :" << GusWord << endl;
				if (GusWord == PassWord)
				{
					cout << "\npassword is " << GusWord << "\n";
					cout << "Found after " << Count << " Trail(s)\n" << endl;
					return true;

				}
				GusWord = "";

			}
		}

	}
}
int main()
{
	GusPassWord(ReadPassWord("Enter a 3_letter PassWord (All Capital "));
}