#include "finite_scheme.h"



finite_scheme::finite_scheme()
{
	in = scheme();
	lmax = calc_lmax(in);
	l2 = calc_l2(in);
}

finite_scheme::get_print()
{

	for (i = 0, i < 9, i++)
	{
		
		cout << "x = " << x << " fwd scheme: " << fwd(x, delta_x) << " bwd scheme: " << back(x, delta_x) << " center scheme: " << center(x, delta_x) << " f'x: " << f_prime_x(x) << " step size :" << delta_x << endl;
		x += 0.1;
	}
}

finite_scheme::print_error()
{
	for (i = 0, i < 9, i++)
	{
		
		cout << "x = " << x << " \t fwd error: " << f_error /*<< "\t bwd error: " << b_error */ << "\t center scheme: " << c_error << "\t f'x: " << f_prime_x(x) << "\t step size :" << delta_x << endl;
		x += 0.1;
	}
}



double finite_scheme::get_lmax()
{
	return lmax;
}

double finite_scheme::get_l1()
{
	return l1;
}

double finite_scheme::get_l2()
{
	return l2;
}


bool comp(double a, double b) {

	return abs(a) < abs(b); // comparison for Lmax to return largest absolute value
}

double finite_scheme::calc_lmax(vector<double> in)
{
	vector<double>::iterator max = max_element(begin(in), end(in),comp); 
	double lmax = *max;
	return lmax;
}

double finite_scheme::calc_l1(vector<double> in)
{
	return 0.0;
}

double finite_scheme::calc_l2(vector<double> in)
{
	double sum = 0.0;
	for (double x : in) {
		sum += x * x;
	}
	//return sqrt(sum);  // check whether to extend square root sum. 
	return sum;
}

double finite_scheme::f(double x){ return 3 * pow(x, 3) + 2 * x + 1; }

vector<double> finite_scheme::scheme()
{
	cout << "------------------------------------------------ Lab1 Room 20 ----------------------------------------------------------\n\n";
	cout << "                                                 scheme loop\n\n";

	do
	{
		discreet_value = scheme_function(x, delta_x);
		error = discreet_value - f_prime_x(x);
		error_v.push_back(error);
		cout << "x" << x << "delta_x " << delta_x << "f_prime_x " << f_prime_x(x) << "error " << error << "discreet value " << discreet_value << endl;
		cout << "\n";
		x += delta_x;
	} while (x <= 1);

	return error_v;
}

double finite_scheme::scheme_function(double x, double delta_x) { return ((f(x + delta_x) - f(x - delta_x)) / delta_x) * 0.5; };


	



