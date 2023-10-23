// barchart.h
// Rimsha Rizvi
// This file allocates space on the heap.
// One entire frame of the animation inside a C-array of Bar object is stored.

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"  // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Codio (light/dark mode)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;

 public:
    // default constructor:
    BarChart() {
        // TO DO:  Write this constructor.
        bars = nullptr;
        this->capacity = 0;
        this->size = 0;
        this->frame = "";
    }
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        // TO DO:  Write this constructor.
        this->bars = new Bar[n];
        this->capacity = n;
        this->size = 0;
        this->frame = "";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        // TO DO:  Write this constructor.
        capacity = other.capacity;
        bars = new Bar[capacity];
        size = other.size;
        frame = other.frame;
        
        for (int i = 0; i < other.size; i++) {
          bars[i] = other.bars[i];
        }
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        //BarChart bc;
        // TO DO:  Write this operator.
        if (this == &other) {
          return *this;
        }
         delete[] bars;

        this->capacity = other.capacity;
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->frame = other.frame;

        for (int i = 0; i < size; i++) {
          this->bars[i] = other.bars[i];
        }
        return *this;   // TO DO:  update this, it is only here so code compiles.
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        // TO DO:  Write this operator.
        capacity = 0;
        size = 0;
        frame = "";
        delete[] bars;
        bars = nullptr;
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
        // TO DO:  Write this destructor.
        if (bars != nullptr) {
          delete[] bars;
        }
    }
    
    // setFrame
    void setFrame(string frame) {
        // TO DO:  Write this destructor.
        this->frame = frame;
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        // TO DO:  Write this function.
        return this->frame; // TO DO:  update this, it is only here so code compiles.
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        // TO DO:  Write this function.
        if (size == capacity) {
          return false;
        }
        Bar bar1(name, value, category);
        bars[size] = bar1;
        size++;
        return true; // TO DO:  update this, it is only here so code compiles.
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        // TO DO:  Write this function.
        return size;  // TO DO:  update this, it is only here so code compiles.
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        //Bar b;
        // TO DO:  Write this function.
        if (i > size || i < 0) {
          throw out_of_range("BarChart: i out of bounds");
        }
        return bars[i];  // TO DO:  update this, it is only here so code compiles.
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        // TO DO:  Write this function.
        sort(bars, bars+size, greater<Bar>());
        output << "frame: " << frame << endl;
        for (int i = 0; i < size; i++) {
          output << bars[i].getName() << " ";
          output << bars[i].getValue() << " ";
          output << bars[i].getCategory() << endl;
        }
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
//         string color = "\033[1;36m";  // you should get this from colorMap
//         string barstr = "";
//         for (int i = 0; i < lenMax; i++) {
//             barstr += BOX;
//         }
//         output << color << barstr << endl;
    	
        // TO DO:  Write this function.
        string color = "";
        string barstr = "";
        sort(bars, bars+size, greater<Bar>());
        double topValue = bars[0].getValue();
        
        if (top > size) {
          top = size;
        }
        for (int i = 0; i < top; i++) {
          if (colorMap.count(bars[i].getCategory()) == 0){
            color = BLACK;
          } else {
            color = colorMap[bars[i].getCategory()];
          }
            double barLength = (double(bars[i].getValue()/topValue)*lenMax);
//             cout << barLength << endl;
//             cout << floor(barLength) << endl;
            for (int j = 0; j < floor(barLength); j++) {
              barstr += BOX;
            }
            output << color << barstr << " ";
            output << bars[i].getName() << " ";
            output << bars[i].getValue() << endl;
            barstr = "";
        }
    }
};

