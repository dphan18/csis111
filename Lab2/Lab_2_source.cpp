//<File name> -- Determines the number of potential team arrangements 
//CSIS 111-002
//Sources: Stirlings formula from Problem 3
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "HaiDang Daniel Phan -- Lab 2" << endl << endl;

	double teams;
	//number of total students
	double n;
	//number of groups
	double r;
	//difference n-r
	double d;

	//asks users for input
	cout << "Enter the number of students " << endl;
	cin >> n;
	cout << "Enter the number of groups" << endl;
	cin >> r;

	//declares d
	d = n - r;

	//uses Stirlings formula to calculate factorial approximation
	//permutations=n!/(r!(n-r)!)
	teams = (pow(2.72, -n)*pow(n, n)*sqrt(2 * 3.14*n)) / ((pow(2.72, -r)*pow(r, r)*sqrt(2 * 3.14*r))*(pow(2.72, -d)*pow(d, d)*sqrt(2 * 3.14*d)));
	
	//prints out the number of different teams
	cout << "Approximate potential team arrangements: "<<teams<<endl;

	return 0;
}

//Function definitions

