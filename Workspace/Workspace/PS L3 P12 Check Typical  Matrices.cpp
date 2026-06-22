#include<iostream>
#include<cstdio>
#include"MyLibe.h"
using namespace std;

void FillArryWithRandomNumber(int matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            matrix[i][j] = Helpers::RandomNumber(1, 9);
        }
    }
}


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d  ", 2, arr[i][j]);
        }
        cout << endl;
    }
}


bool AreTypicalMatrices(int matrix1[3][3], int matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }

    }

    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];


    FillArryWithRandomNumber(Matrix1, 3, 3);
    FillArryWithRandomNumber(Matrix2, 3, 3);

    cout << "Matrix 1\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\n Matrix 2\n";
    PrintMatrix(Matrix2, 3, 3);

    if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
    {
        cout << "Yes: Matrices are typical.";
    }
    else
    {
        cout << "No: Matrices are not typical.";
    }



}