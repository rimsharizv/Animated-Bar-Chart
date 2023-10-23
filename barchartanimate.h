// barchartanimate.h
// Rimsha Rizvi

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"  // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    int colorIndex;
    map<string, string> colorMap;
    vector<string> types;
    string title;
    string xlabel;
    string source;
 
  // extractLines()
  // This function splits the each line to get correspoinding value
  // (wanted) into variables
    void extractLines(ifstream &file, int& num, int& value,
               string& line, string& wanted, string& year,
               string& name, string& country, string& category) {
      getline(file, line);  // removing text
      stringstream s(line);
      getline(s, wanted, ',');
      year = wanted;
      getline(s, wanted, ',');
      name = wanted;
      getline(s, wanted, ',');
      country = wanted;
      getline(s, wanted, ',');
      value = stoi(wanted);
      getline(s, wanted, ',');
      category = wanted;
    }
  
  // addingTypes()
  // This function searches for the category in the array
  // if not found, it adds it to the end of the array
  void addingTypes(string category) {
    for (int i = 0; i < (int)types.size(); i++) {
      if (types[i] == category) {
        return;
      }
    }
    types.push_back(category);
  }

  // expand()
  // This function doubles the size of the array if needed
  void expand(int& size, int& capacity) {
    if (size == capacity) {
        int newCap = capacity * 2;
        BarChart *newb1 = new BarChart[newCap];
        
        for (int i = 0; i < size; i++) {
          newb1[i] = barcharts[i];
        }
        delete[] barcharts;
        capacity = newCap;
        barcharts = newb1;
        newb1 = nullptr;
      }
  }

 public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        // TO DO:  Write this constructor.
        capacity = 4;
        size = 0;
        barcharts = new BarChart[capacity];
        colorIndex = 0;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        // TO DO:  Write this destructor.
        if (barcharts != nullptr) {
          delete[] barcharts;
          barcharts = nullptr;
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        // TO DO:  Write this constructor.
        if (file.eof()) {
          return;
        }
      string line, wanted, year, name, country, category;
      int num, value;

      getline(file, line); // extra
      if (file.eof()) {
          return;
      }
      getline(file, line);
      num = stoi(line);
      BarChart b1(num);
      for (int i = 0; i < num; i++) {
        extractLines(file, num, value, line, wanted, year, name, country, category);

        addingTypes(category);  // stores category if not found
        b1.addBar(name, value, category);
        b1.setFrame(year);

        if (colorMap.count(category) == 0) {
          colorMap.insert({category, COLORS[colorIndex % 7]});
          colorIndex++;
        }
      }
      expand(size, capacity);  // expands bar chart
      barcharts[size] = b1;
      size++;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;

        // TO DO:  Write this function.
			if (endIter == -1) {
        endIter = size;
      }
    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;

      barcharts[i].graph(output, colorMap, top);

      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        return size;  // TO DO:  update this, it is only here so code compiles.
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        //BarChart bc;
        // TO DO:  Write this function.
      if (i > size || i < 0) {
        throw out_of_range("BarChartAnimate: i out of bounds");
      }
      return barcharts[i];  
      // TO DO:  update this, it is only here so code compiles.
    }
};
