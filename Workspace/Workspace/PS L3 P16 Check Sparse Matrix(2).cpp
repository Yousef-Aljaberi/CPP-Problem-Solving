#include<iostream>
using namespace std;

short CountNumberInMatrix(int matrix[3][3], int target, short Rows, short Cols)
{
    int count = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == target)
            {
                count++;
            }
        }


    }
    return count;
}

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix, 0, 3, 3) > (MatrixSize / 2));

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
    int matrix[3][3] = { {2,6,9},{4,0,0},{0,0,1} };

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
