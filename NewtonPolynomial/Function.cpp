#include "Function.hpp"

double FirstEquation(double x1, double x2)
{
    return (x1 - x2 - 6 * log10(x1) - 1);
}
double SecondEquation(double x1, double x2)
{
    return x1 - 3 * x2 - 6 * log10(x2) - 2;
}
double FirstDeriveX1(double x1, double x2)
{
    return 1 - 6 / (x1 * log(10));
}
double FirstDeriveX2(double x1, double x2)
{
    return -1;
}
double SecondDeriveX1(double x1, double x2)
{
    return 1;
}
double SecondDeriveX2(double x1, double x2)
{
    return -3 - 6 / (x2 * log(10));
}


