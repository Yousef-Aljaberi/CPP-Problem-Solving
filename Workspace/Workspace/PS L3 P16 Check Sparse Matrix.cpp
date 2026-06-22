#include<iostream>
using namespace std;


bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int ZerosCount = 0;
    int OtherCount = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == 0)
            {
                ZerosCount++;
            }
            else
            {
                OtherCount++;
            }
        }
    }
    return (ZerosCount > OtherCount);
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << Matrix[i][j] << "     ";
        }
        cout << endl;
    }
}





int main()
{
    int matrix[3][3] = { {2,6,0},{4,0,0},{0,0,1} };

    PrintMatrix(matrix, 3, 3);

    if (IsSparceMatrix(matrix, 3, 3))
    {
        cout << "Yes: The matrix is Sparce." << endl;
    }
    else
    {
        cout << "No: The matrix is Not Sparce." << endl;

    }
}
