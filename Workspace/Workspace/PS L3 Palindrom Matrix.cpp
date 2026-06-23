#include<iostream>
using namespace std;





bool IsPalindromMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
            {
                return false;
            }
        }
        return true;
    }
}
void printMatrix(int Matrix[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
           cout<< Matrix[i][j] << "        ";
        }
        cout << endl;
    }


}
int main()
{
	int Matrix[3][3] = { {1,2,1},{0,5,5},{7,2,7} };
    cout << "Matrix\n";
    printMatrix(Matrix, 3, 3);

    if (IsPalindromMatrix(Matrix, 3, 3))
    {
        cout << "Yes: Matrix is Plindrom" << endl;
    }
    else 
        cout << "No: Matrix is Plindrom" << endl;

}