//Lab5.cpp prints a bar graph of 24 temperatures to both a text file (barGraph.txt) and the console window
//CSIS 111-02

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	cout << "HaiDang Phan -- Lab 5" << endl;
	cout << "Bar Graph also printed to text file (barGraph.txt)"<<endl<<endl;

	//I have read and understood the lab submittal policy

	ifstream input;
	ofstream output;
	output.open("barGraph.txt");
	//variable declarations
	int temp;
	int stars;
	int remainder;
	int countStar;
	int countSpace;

	//printing the header and scale
	input.open("tempData.txt");
	output << "Temperatures for 24 hours:" << endl
		 << "    -30        0         30        60        90        120" << endl
		 << "     |---------|---------|---------|---------|---------|" << endl;
	cout << "Temperatures for 24 hours:" << endl
		<< "    -30        0         30        60        90        120" << endl
		<< "     |---------|---------|---------|---------|---------|" << endl;
	
	while (input >> temp){
		//prints temperatures
		output<<setw(4)<<temp<<" ";
		cout << setw(4) << temp << " ";
		if (temp > 0)
			stars = (temp / 3.0) + 0.5;
		else
			stars = (temp / 3.0) - 0.5;
		countStar = 1;

		//prints stars before 0
		if (stars <= 0){
			countSpace = 1;
			remainder = 10 + stars;
			//spacing
			while(countSpace<=remainder){
				output << " ";
				cout << " ";
				countSpace++;
			}
			countStar = -1;
			while (countStar >= stars){
				output << "*";
				cout << "*";
				countStar--;
			}
			output << "|";
			cout << "|";
		}		

		//prints stars after 0
		if (temp > 0){
			//spacing
			countSpace = 1;
			while (countSpace <= 10){
				output << " ";
				cout << " ";
				countSpace++;
			}
			output << "|";
			cout << "|";
			while (countStar <= stars){
				output << "*";
				cout << "*";
				countStar++;
			}
		}
		output << endl;
		cout << endl;
	}	

	//closing
	input.close();
	output.close();
	return 0;
}