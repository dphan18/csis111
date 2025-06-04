//Author Daniel Phan
//Tempdata <Lab 3> -- Enters temperature data to file and calculates average
//CSIS 111-002
//Sources: book and class slides

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

	//declares variables
	double avgTemp;
	double t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
	ofstream output;
	ifstream input;

	//allows for 12 inputs to tempdata.dat
        cout << "Enter 12 temperatures separated by a space:" << endl;
	cin >> t1>>t2>> t3>> t4>> t5>> t6>> t7>> t8>> t9>> t10>> t11>> t12;
	output.open("tempdata.dat");
	output << fixed << showpoint<<setprecision(1);
	output << setw(6) <<t1<<endl;
	output << setw(6) << t2 << setw(10) << t2 - t1 << endl;
	output << setw(6) << t3 << setw(10) << t3 - t2 << endl;
	output << setw(6) << t4 << setw(10) << t4 - t3 << endl;
	output << setw(6) << t5 << setw(10) << t5 - t4 << endl;
	output << setw(6) << t6 << setw(10) << t6 - t5 << endl;
	output << setw(6) << t7 << setw(10) << t7 - t6 << endl;
	output << setw(6) << t8 << setw(10) << t8 - t7 << endl;
	output << setw(6) << t9 << setw(10) << t9 - t8 << endl;
	output << setw(6) << t10 << setw(10) << t10 - t9 << endl;
	output << setw(6) << t11 << setw(10) << t11 - t10 << endl;
	output << setw(6) << t12 << setw(10) << t12 - t11 << endl;

	//calculates and prints average
	avgTemp = (t1+ t2+t3+ t4+ t5+ t6+ t7+ t8+ t9+ t10+ t11+ t12) / 12;
	cout <<"Average Temperature: "<< avgTemp<<endl;
	return 0;
}