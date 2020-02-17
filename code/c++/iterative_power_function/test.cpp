#include <iostream>
#include <cmath>

using namespace std;


double power(double x, int n);


int main() {
	int n = 3;
	double x = 3;

	cout << "Enter a value for x: ";
	cin >> x;
	cout << "\nEnter a value for n: ";
	cin >> n;

	double result = power(x, n);

	cout << "Result = " << result << endl << endl;
	return result;
}

// --------------------------------------------------------- //
//
// power(x,n) has the following asymptotic upper bounds:
//	Memory:		O(n) = log(n)
//	Temporal:	O(n) = log(n)
//
// --------------------------------------------------------- //

double power(double x, int n) {
	double result = 1;				// Initialize the result variable
	int num = log2(n) + 1;				// Determine the number of iterations
	int data[num], c = num-1;			// Declare array to hold squares

	//  -- O(n) = log(n) -- // 
	for(int i=n; i>=1; i/=2) {			// Iterate through squares and reverse fill array
		data[c--] = i;				// 
	}

	// -- O(n) = log(n) -- //
	for(int i=0; i<num; ++i) {			// Compute power through repeated sqaures
		result *= result;	
		if(data[i] % 2 == 1) result *= x;
	}
	return result;	
}
