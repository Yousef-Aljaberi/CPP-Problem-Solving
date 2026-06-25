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

int  SumOfMatrix(int matrix[3][3], short Rows, short Cols)
{

    int sum = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;

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

    cout << "Sum of matrix is :  " << SumOfMatrix(Matrix1, 3, 3);


}