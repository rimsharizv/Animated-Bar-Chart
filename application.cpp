// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Shanon Reckinger
// U. of Illinois, Chicago
// CS 251: Fall 2021
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	
  cout << "Enter filename: ";
	string filename;
  cin >> filename;
//   cout << "  Colors are:" << endl;
//   cout << "    PURPLE" << endl;
//   cout << "    BLUE" << endl;
//   cout << "    CYAN" << endl;
//   cout << "    GREEN" << endl;
//   cout << "    GOLD" << endl;
//   cout << "    BLACK" << endl;
//   cout << "Choose a specific color or R for random: ";
//   string chooseColor;
//   cin >> chooseColor;
  cout << "Enter playback speed (0 for normal): ";
  int playback;
  cin >> playback;
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, -1);

    return 0;
}
