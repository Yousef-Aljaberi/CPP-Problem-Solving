#include<iostream>
#include<cstdio>
#include"MyLibe.h"
enum enWhatToCount{Capital =1, Small =2 , All=3};

int CountLetters(string text, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return text.length();
	}
	int Counter = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (  WhatToCount==enWhatToCount ::Small&&  islower(text[i]))
			Counter++;

		else if (WhatToCount == enWhatToCount::Capital && isupper(text[i]))
			Counter++;
	}
	return Counter;
}




int main()
{
	string text = InPut::PrintMessageAndReadText("Please Enter String\n");

	cout << "\nString length =     " << CountLetters(text);
	cout << "\n Capital letters  count =	" << CountLetters(text,enWhatToCount::Capital) << endl;
	cout << "\n Small letters  count =	" << CountLetters(text, enWhatToCount::Small) << endl;


	


}
 