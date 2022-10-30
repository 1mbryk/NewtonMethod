#include "GaussMethod.hpp"
using namespace std;

void StartGaussMethod(double **matrix, double *free_member_column, double *solution)
{
    ToTriangular(matrix, free_member_column);
    ReverseMotion(matrix, solution, free_member_column);
}

void ToTriangular(double **matrix, double *free_member_column)
{
    double coeff = 0;
    if (matrix[0][0] < matrix[1][0])
    {
        SwapRows(matrix[0], matrix[1]);
        swap(free_member_column[0], free_member_column[1]);
    }
    for (int i = 0; i < SIZE; ++i)
    {
        if (matrix[i][i] != 0 && matrix[i][i] != 1)
            RowDivide(matrix[i], free_member_column[i], matrix[i][i]);

        for (int j = i + 1; j < SIZE; ++j)
        {
            if (matrix[j][i])
            {
                coeff = ((0 - matrix[j][i]) / matrix[i][i]);
                RowSumm(matrix[j], matrix[i], free_member_column[j], free_member_column[i], coeff);
            }
        }
    }
}

void RowDivide(double *row, double &free_member, double num)
{
    for (int i = 0; i < SIZE; ++i)
        row[i] /= num;

    free_member /= num;
}

void SwapRows(double *&row1, double *&row2)
{
    double *temp = row1;
    row1 = row2;
    row2 = temp;
}

void RowSumm(double *first_row, double *second_row,
             double &first_free_member, double second_free_member, double coeff)
{
    for (int i = 0; i < SIZE; ++i)
        first_row[i] += second_row[i] * coeff;

    first_free_member += second_free_member * coeff;
}

void ReverseMotion(double **matrix, double *solution, double *free_member_column)
{
    for (int i = SIZE - 1; i >= 0; --i)
    {
        solution[i] = free_member_column[i];
        for (int j = SIZE - 1; j > i; --j)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }
}
