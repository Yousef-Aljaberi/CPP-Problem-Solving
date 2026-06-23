#include<iostream>
#include<string>
using namespace std;
string readWord()
{
	string text;
	cout << "please enter a text\n";
	getline(cin, text);
	return text;
}
string Encrypt(string text, short Key)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] + Key);
	}
	return text;
}
string Decrypt(string text, short key)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] - key);
	}
	return text;

}

int main()
{
	const short Key = 2;
	string text = readWord();
	string textAfterEncryption = Encrypt(text, Key);
	string textAfterDecryption = Decrypt(textAfterEncryption, Key);
	cout << "text Before Encryption: " << text <<
		"\ntext After Encryption: " << textAfterEncryption <<
		"\ntext After Decryption: " << textAfterDecryption << endl;

}