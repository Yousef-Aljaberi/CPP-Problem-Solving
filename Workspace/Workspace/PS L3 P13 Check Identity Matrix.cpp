#include<iostream>
using namespace std;

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1)
            {
                return false;
            }

            else if (i != j && Matrix[i][j] != 0)
                return false;




        }
    }
    return true;
}



void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "     ";
        }
        cout << endl;
    }
}



int main()
{
    int matrix[3][3] = { {1,0,0}
                        ,{0,1,0}
                        ,{0,0,1} };

    PrintMatrix(matrix, 3, 3);
    if (IsIdentityMatrix(matrix, 3, 3))
    {
        cout << "Yes: matrix is identity." << endl;
    }
    else
        cout << "No: matrix is not identity." << endl;
}