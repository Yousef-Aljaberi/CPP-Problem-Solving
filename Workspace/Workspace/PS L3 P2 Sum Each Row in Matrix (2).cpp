#include<iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;

    return randnum;
}
void FillArryWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
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

int SumRow(int arr[3][3], short RowNumber, short Cols)
{
    int sum = 0;
    for (int j = 0; j < Cols; j++)
    {
        sum += arr[RowNumber][j];
    }

    return sum;
}

void printEachRowSum(int arr[3][3], int Rows, int Cols)
{
    cout << "The following are sum of each row in the matrix \n";

    for (int i = 0; i < Rows; i++)
    {
        cout << " \n Row " << i + 1 << " Sum = " << SumRow(arr, i, 3) << "\n";

    }
}

int main()
{
    srand((unsigned)time(NULL));
    int RandomArry[3][3];
    FillArryWithRandomNumber(RandomArry, 3, 3);

    cout << "The following is a 3x3 random matrix: \n";
    printMatrix(RandomArry, 3, 3);



    printEachRowSum(RandomArry, 3, 3);
    return 0;
}