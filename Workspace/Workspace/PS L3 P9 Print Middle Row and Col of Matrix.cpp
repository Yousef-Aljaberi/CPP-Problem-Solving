#include<iostream>
#include<cstdio>
#include"MyLibe.h";
using namespace std;

void FillArryWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Helpers::RandomNumber(1, 10);
        }
    }

}

void PrintMiddleRowOfMatrix(int matrix[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
    for (int j = 0; j < Cols; j++)
    {
        printf("%0*d  ", 2, matrix[MiddleRow][j]);
    }
}

void PrintMiddleColOfMatrix(int matrix[3][3], short Rows, short Cols)
{
    short MiddleCols = Cols / 2;
    for (int i = 0; i < Rows; i++)
    {
        printf("%*d  ", 2, matrix[i][MiddleCols]);
    }
}


void PrintMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            printf("%0*d  ", 2, arr[i][j]);
        }
        cout << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3];

    FillArryWithRandomNumber(Matrix1, 3, 3);

    cout << "\n Matrix: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\n Middle Row is: \n";
    PrintMiddleRowOfMatrix(Matrix1, 3, 3);

    cout << "\n Middle Col is: \n";

    PrintMiddleColOfMatrix(Matrix1, 3, 3);






    return 0;
}