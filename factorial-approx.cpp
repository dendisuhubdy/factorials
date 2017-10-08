#include <iostream>
#include <cmath>
#include <cstdlib>

#define E_inverse 0.36787944117
#define E 2.71828182845904
#define pi 3.1415926535897932

long factorial_recursive(long n)
{
	if (n == 0) {
		return 1;
	}
	else 
		return (n*factorial_recursive(n-1));
}

// we don not want to loose precision
// so we use long double

long double factorial_stirling(long double n)
{
	// we speed up the division by doing multiplication of E inverse instead
	long double second_term = pow((n/E), n);
	long double third_term = sqrt(2 * pi * n);
	return (second_term * third_term);
}

// now we compare it with ramanujan's approximation theorem
//

long double factorial_ramanujan(long double n)
{
	long double first_term = sqrt(pi);
	long double second_term = pow((n/E ), n);
	long double third_term = pow((8*pow(n,3) + 4*pow(n,2) + n + (1.0/30.0)), 1.0/6.0);
	return (first_term * second_term * third_term);
}

int main(int argc, char** argv)
{
	long n = atoi(argv[1]);
	long double d = (long double)n;
	if (argc <= 1 ){
		std::cerr << "You need to specify an input number!" << std::endl;
		return 1;
	}
	else {
		long result1 = factorial_recursive(n);
		std::cout << result1 <<std::endl;

		long double result2 = factorial_stirling(d);
		std::cout << result2 << std::endl;

		long double result3 = factorial_ramanujan(d);
		std::cout << result3 << std::endl;
	}
	return 0;
}
