#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace InPut
{
    int printMessageAndReadNumberFromTo(string message, int from, int to)
    {
        int num = 0;
        do
        {
            cout << message << " From " + to_string(from) + " To " + to_string(to) << endl;
            cin >> num;
        } while (num > to || num < from);
        return num;
    }
    int ReadPositiveNumber(string message)
    {
        int num;
        do
        {
            cout << message << endl;
            cin >> num;
        } while (num < 0);
        return num;
    }
    int ReadNumber(string Message)
    {
        int Number;
        cout << Message << endl;
        cin >> Number;
        while (cin.fail())
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one:" << endl;
            cin >> Number;
        }
        return Number;
    }
    string PrintMessageAndReadText(string message)
    {
        cout << message << endl;
        string text = "";
        getline(cin, text);
        return text;
    }

    char PrintMessageAndReadChar(string message)
    {
        cout << message << endl;
        char char1;
        cin >> char1;
        return char1;
    }
}

namespace OutPut
{
    void GetElementDetails(int arr[], int arrLength, int target)
    {
        cout << "number you are looking for is: " << target << endl;
        for (int i = 0; i < arrLength; i++)
        {
            if (target == arr[i])
            {
                cout << "the number found at position : " << i << "\n";
                cout << "the number found it's order  : " << i + 1 << "\n";
                return;
            }
        }
        cout << "the number is not found :-(\n";
    }
    void PrintArray(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << arr[i] << "\t";
        }
    }
    void PrintStringArray(string arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << "code [" << i + 1 << "] : " << arr[i] << endl;
    }
    string Taps(short NumberOfTaps)
    {
        string tap = "";
        for (int i = 1; i <= NumberOfTaps; i++)
        {
            tap += "\t";
        }
        return tap;
    }


}

namespace Helpers
{
    int RandomNumber(int from, int to)
    {
        int RandomNumber = rand() % (to - from + 1) + from;
        return RandomNumber;
    }
    void FillArrayRandomly(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }
    void CopyReverseArray(int arr1[], int arr2[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr2[i] = arr1[arrLength - 1 - i];
        }
    }
    string WordGeneration()
    {
        string word = "";
        word = char(RandomNumber(65, 90));
        word += char(RandomNumber(65, 90));
        word += char(RandomNumber(65, 90));
        word += char(RandomNumber(65, 90));
        return word;
    }
    string CodeGeneration()
    {
        string code = WordGeneration() + "-";
        code += WordGeneration() + "-";
        code += WordGeneration() + "-";
        code += WordGeneration();
        return code;
    }
    void FillStringArray(string arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = CodeGeneration();
    }
    bool IsInArray(int searchValue, int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (searchValue == arr[i])
                return true;
        }
        return false;
    }
    bool IsPrimeNumber(int num)
    {
        int M = round(num / 2);
        for (int i = 2; i <= M; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    bool IsPalindrome(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] != arr[arrLength - i - 1])
                return false;
        }
        return true;
    }
    bool IsOddNumber(int number)
    {
        return (number % 2 == 1);
    }
    bool IsEvenNumber(int number)
    {
        return (number % 2 == 0);
    }
    bool IsPositiveNumber(int number)
    {
        return (number > 0);
    }
    bool IsNegativeNumber(int number)
    {
        return (number < 0);
    }
    void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }



}