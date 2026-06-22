#include<iostream>
using namespace std;

void FillMatrixWithOrderdNumbers(int arr[3][3], int Rows, int Cols)
{
    static int Num = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Num++;
            arr[i][j] = Num;

        }
    }



}
void printMatrix(int arr[3][3], int Rows, int Cols)
{
    cout << "this is the matrix elements \n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "      ";
        }
        cout << endl;
    }
}

void printTrasposeMatrix(int arr[3][3], int Rows, int Cols)
{
    cout << "the following is traspose matrix \n";
    for (int i = 0; i < Cols; i++)
    {
        for (int j = 0; j < Rows; j++)
        {
            cout << arr[j][i] << "     ";
        }

        cout << endl;

    }

}



int main()
{
    int arr[3][3];
    FillMatrixWithOrderdNumbers(arr, 3, 3);
    printMatrix(arr, 3, 3);
    printTrasposeMatrix(arr, 3, 3);

    return 0;
}