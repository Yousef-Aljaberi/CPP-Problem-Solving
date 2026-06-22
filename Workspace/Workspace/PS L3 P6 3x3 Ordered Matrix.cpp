#include<iostream>
using namespace std;

void FillMatrixWithOrderdNumbers(int arr[3][3], int Rows, int Cols)
{
    static int Num = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = Num;
            Num++;
        }
    }



}
void printMatrix(int arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "      ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3];
    FillMatrixWithOrderdNumbers(arr, 3, 3);
    printMatrix(arr, 3, 3);
    return 0;
}