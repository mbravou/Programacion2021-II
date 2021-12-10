#include <iostream>
#include <cmath>

using fptr = double(double);
using fptrderiv = double(double, double, fptr);

double fun(double x);
double g(double x);
double forward(double x, double h, fptr f);
double central(double x, double h, fptr f);
double richardson(double x, double h, fptr f, fptrderiv alg);

int main(int argc, char **argv)
{
	std::cout.precision(15); std::cout.setf(std::ios::scientific);
	const double x = std::atof(argv[1]);

	for (double h = 1.0e-1; h >= 1.0e-15; h/= 10.0) {
		std::cout << h << "\t"
			  << std::fabs(1 - forward(x, h, fun)/std::cos(x)) << "\t"
			  << std::fabs(1 - central(x, h, fun)/std::cos(x)) << "\t"
			  << std::fabs(1 - richardson(x, h, fun, forward)/std::cos(x)) << "\t"
			  << std::fabs(1 - richardson(x, h, fun, central)/std::cos(x)) << "\n";
	}
	return 0;
}

double fun(double x)
{
	return std::sin(x);
}

double g(double x)
{
	return x*x;
}

double forward(double x, double h, fptr f)
{
	return (f(x+h) -f(x))/h;
}

double central(double x, double h, fptr f)
{
	return(f(x+h) - f(x-h))/(2*h);
}

double richardson(double x, double h, fptr f, fptrderiv alg)
{
	double val1 = alg(x, h, f);
	double val2 = alg(x, h/2, f);
	return (4*val2 - val1)/3;
}	
