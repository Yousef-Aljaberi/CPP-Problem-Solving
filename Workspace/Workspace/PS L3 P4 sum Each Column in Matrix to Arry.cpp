#include<iostream>
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
int SumCol(int arr[3][3], short ColNumber, short Rows)
{
    int sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        sum += arr[i][ColNumber];
    }

    return sum;
}

void SumEachColumnInArry(int arr[3][3], int sumArry[], short Rows, short Cols)
{

    for (int j = 0; j < Cols; j++)
    {
        sumArry[j] = SumCol(arr, j, 3);
    }


}



void printArry(int arr[3], int len)
{
    cout << "The following are sum of each Column in the matrix \n";

    for (int i = 0; i < len; i++)
    {
        cout << " \n Col " << i + 1 << " Sum = " << arr[i] << "\n";

    }
}

int main()
{
    srand((unsigned)time(NULL));
    int RandomArry[3][3];
    int SumArry[3];
    FillArryWithRandomNumber(RandomArry, 3, 3);

    cout << "The following is element in the matrix \n";

    printMatrix(RandomArry, 3, 3);

    SumEachColumnInArry(RandomArry, SumArry, 3, 3);

    printArry(SumArry, 3);

    return 0;
}