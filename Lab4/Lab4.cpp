//Lab4.cpp -- calculates final grades from an input file
//CSIS 111-02
//Public Domain


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout << "HaiDang Phan -- Lab 4" << endl << endl;
	//I have read and understood the lab submittal policy

	double student_score;
	double total_points;
	double final_score;
	int final_score_whole;
	ifstream input;

        input.open("John_Smith_Grade.txt");
        if(!input.is_open())
                input.open("Lab4/John_Smith_Grade.txt");
        input >> student_score >> total_points;
        input.close();

	final_score = student_score / total_points * 100;
	cout << fixed << showpoint << setprecision(5) 
		<<"Floating Point Result: "<< final_score <<"%"<< endl;
	final_score_whole= (int) ceil(final_score);
	cout <<"Rounded Result: "<<final_score_whole<<"%"<< endl;

        if (final_score_whole >= 90)
                cout << "Excellent" << endl;
        else if (final_score_whole >= 80)
                cout << "Well Done" << endl;
        else if (final_score_whole >= 70)
                cout << "Good" << endl;
        else if (final_score_whole < 60)
                cout << "Fail" << endl;
        else
                cout << "Need Improvement" << endl;
	return 0;
}


