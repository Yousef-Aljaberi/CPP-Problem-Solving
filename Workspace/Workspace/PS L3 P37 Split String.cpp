#include<iostream>
#include<string>
#include<vector>
#include"MyLibe.h"

vector<string> SplitString(string text, string delim)
{
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		vString.push_back(text);

	}

	return vString;
	
}







int main()
{
	vector <string> vString;
	vString = SplitString(InPut::PrintMessageAndReadText("Please enter a string ")," ");
	cout << "Tokens are: " << vString.size() << endl;

	for (string& Word : vString)
	{
		cout << Word << endl;
	}

}