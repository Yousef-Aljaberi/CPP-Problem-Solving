#include<iostream>
using namespace std;

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDiagElement = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagElement)
            {
                return false;
            }

            else if (Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
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
    int matrix[3][3] = { {2,0,0}
                        ,{0,1,0}
                        ,{0,0,1} };

    PrintMatrix(matrix, 3, 3);



    if (IsSparceMatrix(matrix, 3, 3))
    {
        cout << "Yes: matrix is Scalar." << endl;
    }
    else
        cout << "No: matrix is not Scalar." << endl;
}