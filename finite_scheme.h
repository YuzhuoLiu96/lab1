using namespace std;
#include<vector>;
#include<algorithm>;
#include<iostream>;

class finite_scheme
{
	double lmax;
	double l2;
	double l1;
	double x = 0;
	double delta_x = 0.1;
	double error;
	double discreet_value;
	vector<double> error_v;
	vector<double> discreet_values;
	vector<double> in;


public:
	finite_scheme();
	~finite_scheme();
	double get_lmax();
	double get_l1();
	double get_l2();
	void get_print()
	void print_error()
	
	// functions to get norms;

private:

	// functions to calculate norms;
	double calc_lmax(vector<double> in);
	double calc_l1(vector<double> in);
	double calc_l2(vector<double> in);
	double f(double x);// can this be made more flexible by passing in functions as args?
	double f_prime_x(double x) {return 9 * pow(x, 2) + 2; }; // f'(x);
	vector<double> scheme();
	double scheme_function(double x, double delta_x);

};

