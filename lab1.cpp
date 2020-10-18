#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include "finite_scheme.h"
using namespace std;
vector<double> center_error;
vector<double> forward_error;
vector<double> backward_error;

vector<vector<double>> forward_MainError;

// create a name for the file output
auto f= [](double x) { return 3 * pow(x, 3) + 2 * x + 1; }; // orig func.//return 9 * pow(x, 2) + 2; // f'(x);
auto center = [&](double x, double delta_x) {return ((f(x + delta_x) - f(x - delta_x)) / delta_x)*0.5; };
auto f_prime_x = [](double x) {return 9 * pow(x, 2) + 2; }; // f'(x);
auto fwd = [&](double x, double delta_x) {return (f(x + delta_x) - f(x)) / delta_x; };
auto back = [&](double x, double delta_x) {return  (f(x) - f(x - delta_x)) / delta_x; };


int main()

{
	ofstream outputFile;
	ofstream fs;
	string filename = "exampleOutput.csv";

	cout << setprecision(10);
	
	double x =0 ;
	double delta_x = 0.1;
	double c_error;
	double b_error;
	double f_error;

	
	fs.open(filename);

//	Write a C++ program which solves the above problem on a uniform grid
//of spacing h = 0.1

	fs << "x" << ", " << "fwd" << ", " << "fwd error" << ", " << "back" << ", " << "back error" << ", " << "center" <<
		", " << "center error" << ", " << "f'(x)" << " ," << "dx" << endl;

 // for (int j = 0; j < 1; j++)
	//{
 //        cout << j;
 //         


	//	 do
	//	 {

	//		 

	//		 c_error = center(x, delta_x) - f_prime_x(x);
	//		 f_error = fwd(x, delta_x) - f_prime_x(x);
	//		 b_error = back(x, delta_x) - f_prime_x(x);

	//		 /*	cout << "x = " << x  << " fwd scheme: " <<  fwd(x,delta_x) << " bwd scheme: " <<  back(x,delta_x) << " center scheme: " <<  center(x,delta_x) <<
	//	   " f'x: " << f_prime_x(x) << " step size :" << delta_x << endl;*/


	//	 cout << "x = " << x <<" \t fwd error: " << f_error /*<< "\t bwd error: " << b_error */ << "\t center scheme: " << c_error << "\t f'x: " << f_prime_x(x) << "\t step size :" << delta_x << endl;



	//		 fs << x << ", " << fwd(x, delta_x) << ", " << f_error << ", " /*<< back(x, delta_x) << ", " << b_error */<< ", " << center(x, delta_x) <<
	//			 ", " << c_error << ", " << f_prime_x(x) << " ," << delta_x << endl;


	//		center_error.push_back(abs(c_error));
	//		forward_error.push_back(abs(f_error));
	//		 x += delta_x;
	//	 } while (x < 1 + delta_x);
	//		


	//	 finite_scheme fd = finite_scheme(forward_error);
		 finite_scheme cnt = finite_scheme();
	//	 finite_scheme bd = finite_scheme(backward_error);
		 

	//	 cout << "finite_Scheme class lmax calc. forward = " << fd.get_lmax() << endl;
		 cout << "finite_Scheme class lmax calc. cnt = " << cnt.get_lmax() << endl;
	//	 cout << "finite_Scheme class lmax calc. bd = " << bd.get_lmax() << endl;
	//	 cout << "finite_Scheme class l2 calc. forward = " << fd.get_l2() / (1 / delta_x )<< endl;
		 cout << "finite_Scheme class l2 calc. cnt = " << cnt.get_l2() / (1 / delta_x) << endl;
		 //	 cout << "finite_Scheme class lmax calc. bd = " << bd.get_lmax() << endl;
		 


	//	cout << "center error :" << accumulate(center_error.begin(), center_error.end(), 0.0) << endl << /*<< "back error :" << accumulate(backward_error.begin(), backward_error.end(), 0.0)*/ "forward error :" << accumulate(forward_error.begin(), forward_error.end(), 0.0) <<  endl;
	//x=0;
	//delta_x*=0.1; //decreases delta x
	//
	//}

  fs.close();

  cout << "enter to stop" << endl;
  cin.get();
  return 0;


}








