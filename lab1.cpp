#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
vector<double> center_error;
vector<double> forward_error;
//vector<double> backward_error;

vector<vector<double>> forward_MainError;

// create a name for the file output
auto f= [](double x) { return 3 * pow(x, 3) + 2 * x + 1; }; // orig func.//return 9 * pow(x, 2) + 2; // f'(x);
auto center = [&](double x, double delta_x) {return ((f(x + delta_x) - f(x - delta_x)) / delta_x)*0.5; };
auto f_prime_x = [](double x) {return 9 * pow(x, 2) + 2; }; // f'(x);
auto fwd = [&](double x, double delta_x) {return (f(x + delta_x) - f(x)) / delta_x; };
//auto back = [&](double x, double delta_x) {return  (f(x) - f(x - delta_x)) / delta_x; };


int main()

{
	ofstream outputFile;
	ofstream fs;
	string filename = "exampleOutput.csv";

	cout << setprecision(10);
	
	double x =0 ;
	//double h = 1;
	double delta_x = 0.1;
	double c_error;
	//double b_error;
	double f_error;
	double a_solution = 11;
	double l2_er = 0.0;
	double l0_er = 0.0;
	double li_fw = 0.0;
	double increment = 1.05;
	
	fs.open(filename);

//	Write a C++ program which solves the above problem on a uniform grid
//of spacing h = 0.1

	fs << "x" << ", " << "fwd" << ", " << "fwd error" << ", " << "back" << ", " << "back error" << ", " << "center" <<
		", " << "center error" << ", " << "f'(x)" << " ," << "dx" << endl;

  for (int j = 0; j < 5; j++)
	{
         cout << j;
          


		 do
		 {
			 c_error = center(x, delta_x) - f_prime_x(x);
			 f_error = fwd(x, delta_x) - f_prime_x(x);
			// b_error = back(x, delta_x) - f_prime_x(x);

			 /*	cout << "x = " << x  << " fwd scheme: " <<  fwd(x,delta_x) << " bwd scheme: " <<  back(x,delta_x) << " center scheme: " <<  center(x,delta_x) <<
		   " f'x: " << f_prime_x(x) << " step size :" << delta_x << endl;*/


		 cout << "x = " << x <<" \t fwd error: " << f_error /*<< "\t bwd error: " << b_error */ << "\t center scheme: " << c_error << "\t f'x: " << f_prime_x(x) << "\t step size :" << delta_x << endl;



			 fs << x << ", " << fwd(x, delta_x) << ", " << f_error << ", " /*<< back(x, delta_x) << ", " << b_error */<< ", " << center(x, delta_x) <<
				 ", " << c_error << ", " << f_prime_x(x) << " ," << delta_x << endl;


			center_error.push_back(abs(c_error));
			forward_error.push_back(abs(f_error));
			l2_er += pow(abs(f_error),2);

			 x += delta_x;
		 } while (x < 1 + (delta_x/2));
		 //while (x < 1 + delta_x);
			//if(number > xxx + 1*pow(10,-5) && number < xxx - 1*pow(10,-5))
		/*for (size_t i = 0; i < center_error.size(); i++)
		{
			cout <<  center_error[i];
		}*/
		 cout << "l2 is " << l2_er/(1/delta_x) << endl;


		 for (int i = 0; i < forward_error.size(); i++) {
			 if (abs(forward_error[i]) > li_fw) {
				 li_fw = forward_error[i];
			 }
			 else {
				 continue;
			 }
		 }

		 for (int i = 0; i < center_error.size(); i++) {
			 if (abs(center_error[i]) > li_fw) {
				 li_fw = center_error[i];
			 }
			 else {
				 continue;
			 }
		 }




		 std::cout << "L infinite for forward diff: " << li_fw << "\n";


		cout << "center error :" << accumulate(center_error.begin(), center_error.end(), 0.0) /*<< "back error :" << accumulate(backward_error.begin(), backward_error.end(), 0.0)*/ << "forward error :" << accumulate(forward_error.begin(), forward_error.end(), 0.0) <<  endl;
	x=0;
	delta_x*=0.1; //decreases delta x
	
	}

  fs.close();

  cout << "enter to stop" << endl;
  cin.get();
  return 0;


}








