#include <iostream>
#include<iomanip>
using namespace std;






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

bool IsNumberInMatrix(int matrix[3][3], int tragetNumber, short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == tragetNumber)
            {
                return true;
            }
        }


    }

    return false;
}

void PrintIntersectedNumbersInMatrix(int matrix1[3][3], int  matrix2[3][3], short Rows, short Cols)
{
    int Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)    
        {
            Number = matrix1[i][j];
            if (IsNumberInMatrix(matrix2,Number, Rows, Cols))
            {
                cout <<setw(3) << Number << "   ";
            }
        }
    }
}


int main()
{
	int matrix1[3][3] = { {2,6,3},{4,1,67},{0,34,1} };
	int matrix2[3][3] = { {2,6,9},{3,67,74},{33,0,1} };

    cout << "\nMatrix 1: \n";
	PrintMatrix(matrix1, 3, 3);

    cout << "\nMatrix 2: \n";
	PrintMatrix(matrix2, 3, 3);

    cout << "\n\nIntersected Numbers are: \n";
    PrintIntersectedNumbersInMatrix(matrix1, matrix2, 3, 3);


}