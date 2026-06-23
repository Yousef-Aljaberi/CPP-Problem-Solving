#include<iostream>
#include"MyLibe.h"
using namespace std;
void FillArryWithRandomNumber(int matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
           matrix[i][j] = Helpers::RandomNumber(1, 100);
        }
    }
}


bool IsNumberInMatrix(int matrix[3][3], int tragetNumber, short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == tragetNumber)
            {
                return true;
            }
        }


    }

    return false;
}

void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout<<arr[i][j]<<"   ";
        }
        cout << endl;
    }
}




int main()
{
    int Matrix1[3][3];
    FillArryWithRandomNumber(Matrix1, 3, 3);
     
    PrintMatrix(Matrix1, 3, 3);

    int targetNumber = InPut::ReadNumber("Enter number to check in matirx: ");

    if (IsNumberInMatrix(Matrix1, targetNumber, 3, 3))
    {
        cout << "Yes The Element Is Found." << endl;
    }
    else
        cout << "No: The Element Is Not Found." << endl;
}

