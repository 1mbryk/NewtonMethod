#include "main.hpp"
using namespace std;

int main()
{
    int iter_amount = 0;
    double *curr_x = new double[SIZE]{INIT_APPROX_1, INIT_APPROX_2};
    double *prev_x = new double[SIZE]{0, 0};
    double *delta_x = new double[SIZE]{0,0};
    double *func_column = new double[SIZE]{0,0};
    double **jacobi_matrix = new double *[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        jacobi_matrix[i] = new double[SIZE];
    }

    cout << '|' << setw(3) << "#" << '|' << setw(12) << "delta x1" << '|' << setw(12) << "delta x2" << '|' << setw(12) << "x1" << '|' << setw(12) << "x2" << '|' << setw(12) << "func 1" << '|' << setw(12) << "func 2"   << '|'<<endl;
    cout <<  "|---+------------+------------+------------+------------+------------+------------|" << endl;
    
    while(true)
    {
        ++iter_amount;
        GetJacobiMatrix(jacobi_matrix, curr_x[0], curr_x[1]);
        GetFunctionColumn(func_column, curr_x[0], curr_x[1]);
        Output(iter_amount, delta_x, curr_x, func_column);
        StartGaussMethod(jacobi_matrix, func_column, delta_x);
        if(abs(curr_x[0] - prev_x[0]) < EPSILON &&
           abs(curr_x[1] - prev_x[1]) < EPSILON)
            break;
        prev_x[0] = curr_x[0];
        prev_x[1] = curr_x[1];
        
        curr_x[0] += delta_x[0];
        curr_x[1] += delta_x[1];
        
    }

   
    
    // // // // // // // // // // // // //
    delete[] curr_x;
    delete[] prev_x;
    delete[] delta_x;
    delete[] func_column;
    for (int i = 0; i < SIZE; ++i)
    {
        delete[] jacobi_matrix[i];
    }
    delete[] jacobi_matrix;
}
