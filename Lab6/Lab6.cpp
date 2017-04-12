//ROT13 - translates a set of characters to the character 13 rotations after if A--> N, S--> F
//CSIS 111-<002>
//<ANSI table>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function prototypes
void Rot13(char&);
void WriteTranslatedChar(char, ofstream&);

int main(){
	cout << "HaiDang Phan -- Lab 6" << endl << endl;
	//variable declarations
	string fileName;
	ofstream output;
	ifstream input;
	char translate;

	//input/output definitions
	cout << "Enter file name: " << endl;
	cin >> fileName;
	input.open(fileName);
	output.open("output.rot13");

	//runs functions while characters left
	while (input.get(translate)){
		Rot13(translate);
		WriteTranslatedChar(translate, output);
	}
	return 0;
}

//Changes letters based of ANSI characters
//We discussed them briefly in class
void Rot13(char& translate){
	//capital letters
	if (translate <= 90 && translate >= 65){
		translate = (translate - 52) % 26 + 65;
	}
	//lowercase letters
	else if (translate <= 122 && translate >= 97){
		translate = (translate - 84) % 26 + 97;
	}
	//other characters
	translate= translate;
}
//prints each character to output file
void WriteTranslatedChar(char translate, ofstream& output){
	output << translate;
}
