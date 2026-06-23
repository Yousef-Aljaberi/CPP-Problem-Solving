#include<iostream>
#include"MyLibe.h"
#include <iomanip>
using namespace std;


void FillArryWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] =Helpers::RandomNumber(1, 100);
        }
    }

}

void printMatrix(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "        ";
        }
        cout << endl;
    }


}
int main()
{
    srand((unsigned)time(NULL));
    int RandomArry[3][3];
    FillArryWithRandomNumber(RandomArry, 3, 3);

    cout << "The following is a 3x3 random matrix: \n";

    printMatrix(RandomArry, 3, 3);
    return 0;
}