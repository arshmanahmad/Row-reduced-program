#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
void displayMatrix(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void rowReduce(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS - 1; i++)
    {
        // Row interchange if necessary
        if (matrix[i][i] == 0)
        {
            for (int j = i + 1; j < ROWS; j++)
            {
                if (matrix[j][i] != 0)
                {
                    for (int k = 0; k < COLS; k++)
                    {
                        swap(matrix[i][k], matrix[j][k]);
                    }
                    break;
                }
            }
        }
        // Gauss elimination
        for (int j = i + 1; j < ROWS; j++)
        {
            // Calculate the ratio to make the element below the diagonal zero
            int ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < COLS; k++)
            {
                // Subtract the product of the ratio and the corresponding element in the pivot row

                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }
}
int main()
{
    int matrix[ROWS][COLS] = {{1, 1, -1}, {2, 3, -1}, {3, 1, -5}};
    cout << "Matrix before row reduction:" << endl;
    displayMatrix(matrix);
    cout << "\nMatrix after row reduction (echelon form):" << endl;
    rowReduce(matrix);
    displayMatrix(matrix);
    //  return 0;
}
