#include<iostream>
#include<iomanip>
#include"MyLibe.h"
using namespace std;



void FillArryWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Helpers::RandomNumber(1, 100);
        }
    }

}

int MaxNumberInMatrix(int matrix[3][3], short Rows, short Cols)
{
    int Max = matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (matrix[i][j] > Max)
            {
                Max = matrix[i][j];
            }
        }
    }

    return Max;
}



int MinNumberInMatrix(int matrix[3][3], short Rows, short Cols)
{
    int Min = matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (matrix[i][j] < Min)
            {
                Min = matrix[i][j];
            }
        }
    }

    return Min;
}


void printMatrix(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "        ";
        }
        cout << endl;
    }


}

int main()
{
    srand((unsigned)time(NULL));
    int matrix[3][3];
    FillArryWithRandomNumber(matrix, 3, 3);

    cout << "Matrix1: \n";
    printMatrix(matrix, 3, 3);

    cout << "\nMax number  is  :  " << MaxNumberInMatrix(matrix, 3, 3);

    cout << "\nMinMum Number is:  " << MinNumberInMatrix(matrix, 3, 3);
}