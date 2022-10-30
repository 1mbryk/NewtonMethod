#pragma  once
#include "main.hpp"

void StartGaussMethod(double **matrix, double *free_member_column, double *solution);
void ToTriangular(double **matrix, double *free_member_column);
void RowDivide(double *row, double &free_member, double num);
void SwapRows(double *&row1, double *&row2);
void RowSumm(double *first_row, double *second_row,
             double &first_free_member, double second_free_member, double coeff);
void ReverseMotion(double **matrix, double *solution, double *free_member_column);
