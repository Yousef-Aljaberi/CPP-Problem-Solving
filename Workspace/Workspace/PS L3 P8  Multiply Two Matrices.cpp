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

void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
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
    int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

    FillArryWithRandomNumber(Matrix1, 3, 3);
    FillArryWithRandomNumber(Matrix2, 3, 3);

    cout << "\n Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\n Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);


    MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);

    cout << "\n Results\n";
    PrintMatrix(MatrixResults, 3, 3);


    return 0;
}