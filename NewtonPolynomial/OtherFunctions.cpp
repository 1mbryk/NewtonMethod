#include "OtherFunctions.hpp"
using namespace std;

void GetJacobiMatrix(double **jacobi_matrix, double x1, double x2)
{
    jacobi_matrix[0][0] = FirstDeriveX1(x1, x2);
    jacobi_matrix[0][1] = FirstDeriveX2(x1, x2);
    jacobi_matrix[1][0] = SecondDeriveX1(x1, x2);
    jacobi_matrix[1][1] = SecondDeriveX2(x1, x2);
}

void GetFunctionColumn(double *func_column, double x1, double x2)
{
    func_column[0] = -1 * FirstEquation(x1, x2);
    func_column[1] = -1 * SecondEquation(x1, x2);
}

void Output(int iter_amount, double* delta_x, double* x, double* func_value)
{
    cout << '|' << setw(3) << iter_amount << '|' << setw(12) << delta_x[0]<< '|' << setw(12) << delta_x[1] << '|'<< setw(12) << x[0] << '|' << setw(12) << x[1] << '|' << setw(12) << func_value[0] << '|' << setw(12) << func_value[1] << '|'<<endl;
    
}
