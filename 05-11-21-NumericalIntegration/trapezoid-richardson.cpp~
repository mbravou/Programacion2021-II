#include <cmath>
#include <iostream>

// definition
double fun(double x);
using fptr = double(double);
double trapezoid(double a, double b, double h, fptr f);
template <typename typealg>
double richardson(double a, double b, double h, fptr f, typealg alg);

// main
int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double xmin = std::atof(argv[1]);
    const double xmax = std::atof(argv[2]);
    const double h = std::atof(argv[3]);

    const double exact = -std::cos(xmax) + std::cos(xmin);
    for (double h = 1.0e-1; h >= 1.0e-8; h /= 2.0) {
        std::cout << h << "\t"
                  << std::fabs(1 - trapezoid(xmin, xmax, h, fun)/exact) << "\t"
                  << std::fabs(1 - richardson(xmin, xmax, h, fun, trapezoid)/exact) << "\n";
    }
    return 0;
}

// implementation
double fun(double x)
{
	return std::sin(x);
}

double trapezoid(double a, double b, double h, fptr f)
{
	const int n = std::floor((b-a)/h);
	double result = 0.0;
	for(int i = 1; i <= n-1; ++i) {
		double xi = a + i*h;
		result += f(xi);
	}
	result += 0.5*(f(a) + f(b));
	result *= h;
	
	return result;
}

template <typename typealg>
double richardson(double a, double b, double h, fptr f, typealg alg)
{
  double val1 = alg(a, b, h, f);
  double val2 = alg(a, b, h/2, f);
  return (4*val2 - val1)/3;
}

