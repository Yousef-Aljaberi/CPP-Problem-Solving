#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector <string> SplitWord(string text, string delim)
{
	vector <string> vWords;
	int pos = 0;
	string sWord = "";
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}
		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		vWords.push_back(text);
	}
	return vWords;
}

string LowerAllLetter(string text)
{
	
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	return text ;
}
string JoinString(vector<string>vString, string delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 += s + delim;
	}
	return S1.substr(0, S1.length() - delim.length());

}
string ReplaceWords(string text, string StringToReplace, string sRplaceTo, bool MatchCase = true)
{
	string StringToReplaceLowerCase = LowerAllLetter(StringToReplace);

	vector<string>vString = SplitWord(text, " ");
	string S1;
	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRplaceTo;
			}
			
		}

		else
		{
			if (LowerAllLetter(s) == StringToReplaceLowerCase)
			{
				s = sRplaceTo;
			}		
		}
	}
	
	
	return JoinString(vString, " ");
}



int main()
{
	string  text = "Welcom to Yemen , Yemen is a nice country.";
	string StringToReplace = "yemen";
	string StringReplace = "USA";
	cout << "\nOrignal string\n" << text;

	cout << "\n\nString after  replace with match case:\n";
	cout << ReplaceWords(text, StringToReplace, StringReplace);

	cout << "\n\nString after  replace with don't match case:\n";
	cout << ReplaceWords(text, StringToReplace, StringReplace,false) << "\n\n";


}