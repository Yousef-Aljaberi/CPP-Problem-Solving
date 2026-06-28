#include<iostream>
#include<string>
#include<vector>
#include"MyLibe.h"

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


string ReversWordsInString(string text)
{

	vector <string> vWords;
	vWords = SplitWord(text," ");
	string text2 = "";
	vector<string>::iterator iter = vWords.end();
	
	while (iter != vWords.begin())
	{
		--iter;
		text2 += *iter + " ";
	}

	text2 = text2.substr(0, text.length() - 1);


	return text2;

}

int main()
{

	string text = InPut::PrintMessageAndReadText("Please enter your string");

	cout << "\n\nString after reversin words: \n";
	cout << "\n" << ReversWordsInString(text);

	
}