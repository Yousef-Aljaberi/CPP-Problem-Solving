#include<iostream>
#include"MyLibe.h"
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
    int matrix[3][3] = { {2,6,3},{4,1,0},{0,0,1} };

    PrintMatrix(matrix, 3, 3);
    int targetNumber = InPut::ReadNumber("Enter the Number To Count The Matrix\n");
    int NumberOfReapeated = CountNumberInMatrix(matrix, targetNumber, 3, 3);

    cout << "The Number: " << targetNumber << " Count in Matrix is:  " << NumberOfReapeated << endl;

}
