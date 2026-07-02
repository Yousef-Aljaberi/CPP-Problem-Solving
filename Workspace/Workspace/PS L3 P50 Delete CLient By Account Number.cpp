#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;
const string FileName = "ClintFile.txt";

struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ConverRecordToLine(stClintData ClintData, string delim="#//#")
{
	string S1 = "";
	S1 += ClintData.AccountNumber + delim;
	S1 += ClintData.PinCode + delim;
	S1 += ClintData.Name + delim;
	S1 += ClintData.PhoneNumber + delim;
	S1 += to_string(ClintData.AccountBalance);
	return S1;


}
string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "Please enter Account Number?   ";
	cin >> AccountNumber;

	return AccountNumber;
}

vector<string> SplitString(string text, string Seperator = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = text.find(Seperator)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		text.erase(0, pos + Seperator.length());
	}
	if (text != "")
	{
		vString.push_back(text);
	}

	return vString;

}


stClintData ConvertLineDataToRecord(string RecordLine)
{
	stClintData Clint;
	vector <string> vClintData;

	vClintData = SplitString(RecordLine);
	Clint.AccountNumber = vClintData[0];
	Clint.PinCode = vClintData[1];
	Clint.Name = vClintData[2];
	Clint.PhoneNumber = vClintData[3];
	Clint.AccountBalance = stod(vClintData[4]);


	return Clint;

}

vector <stClintData> LoadClientDataFromFile(string FileName)
{
	vector<stClintData> Clients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClintData Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineDataToRecord(Line);
			Clients.push_back(Client);
		}


		MyFile.close();
	}

	return Clients;
}

void PrintClient(stClintData Client)
{
	cout << "\nThe following are the client details: \n\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nName	      : " << Client.Name;
	cout << "\nPhone         : " << Client.PhoneNumber;
	cout << "\nAccount Balance:" << Client.AccountBalance;

}


 

bool FindClientByAccountNumber(vector<stClintData> Clients ,stClintData &Client, string sAccountNumber)
{

	for (stClintData C : Clients)
	{
		if (C.AccountNumber == sAccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;

}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClintData> &vClients)
{
	for (stClintData& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
void SaveClientsDataToFile(string FileName, vector<stClintData> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string LineData;

	if (MyFile.is_open())
	{
		for (stClintData C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				LineData = ConverRecordToLine(C);
				MyFile << LineData << endl;
			}
		}
	}
}
bool DeleteClientByAccountNumber( string sAccountNumber, vector<stClintData> &vClients)
{
	stClintData Client;
	char Answer = 'y';
	
	if (FindClientByAccountNumber(vClients, Client, sAccountNumber))
	{
		PrintClient(Client);

		cout << "\n\nAre you sure you want delete this client? (y/n) ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(sAccountNumber,vClients);
			SaveClientsDataToFile(FileName, vClients);
			
			vClients = LoadClientDataFromFile(FileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << sAccountNumber << ") is Not Found.";
		return false;

	}
	
}

int main()
{
	vector<stClintData> Clients = LoadClientDataFromFile(FileName);
	string AccountNumber = ReadClientAccountNumber();
	
	DeleteClientByAccountNumber(AccountNumber,Clients);

}
