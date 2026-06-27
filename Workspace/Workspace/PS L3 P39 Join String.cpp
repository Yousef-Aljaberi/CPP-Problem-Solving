#include<iostream>
#include<vector>
#include<string>

using namespace std;

string JoinString(vector <string> vString, string delim)
{
	string S1 = "";
	for (string& Word : vString)
	{
		S1 += Word + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}


int main()
{
	vector <string> vString = { "Yousif","Ameen","Ahmed","Mosad","Saeed" };
	cout << "\nVector after join\n" << JoinString(vString, ", ");
}