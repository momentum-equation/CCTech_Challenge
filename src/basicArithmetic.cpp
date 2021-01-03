#include "basicArithmetic.h"

double power(double val, int expo)
{
    int idx {0};
    double result = 1.;
    while(idx < expo)
    {
        result *= val;
        idx++;
    }
    return result;
}

double abs(double val)
{
    if (val < 0)
    {
        val *= (-1);
    } 
    return val;
}

double sqrt(double num)
{
    const double tol {1e-15};
    double guess {0};
    double corr {};
    double err {1};

    while(err > tol)
    {
        corr = 0.5*(guess + num/(small_val+ guess));
        err = abs(corr - guess);
        guess = corr;
    }
    return corr;
}

void swap(size_t& a, size_t& b)
{
	size_t tmp = a;
	a = b;
	b = tmp;
}

void swap(ssize_t& a, ssize_t& b)
{
	ssize_t tmp = a;
	a = b;
	b = tmp;
}

double max(const double& val1, const double& val2)
{
	return (val1 >= val2) ? val1 : val2;
}

double min(const double& val1, const double& val2)
{
	return (val1 <= val2) ? val1 : val2;
}

double determinant(const double& a, const double& b, const double& c, const double& d)
{
	return (a*d - b*c);
}