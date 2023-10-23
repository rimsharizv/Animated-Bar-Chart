// bar.h
// Rimsha Rizvi
// This file creates a Bar class, where private member variables are defined.
// All functions needed to create and sort bars in a bar chart is used here.

#include <iostream>
#include <string>
#include "myrandom.h"  // used in autograder, do not remove
using namespace std;

//
// Bar
//
// Member variables are defined in this function
// Information (name, value, and category) in a Bar is used in a bar chart.
class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.

  //
  // The Bar class keeps track of name, value, and category of a particular bar
  //
  string name;
  int value;
  string category;

 public:
  //
  // constructor:
  //
  // Called automatically by C++ to initialize an Bar object with
  // a name, value and a category.
  //
    // default constructor:
    Bar() {
        // TO DO:  Write this constructor.
      name = "";
      value = 0;
      category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        // TO DO:  Write this constructor.
        this->name = name;
        this->value = value;
        this->category = category;
    }

    // destructor:
    virtual ~Bar() {
        // TO DO:  Write this destructor or leave empty if not needed.
    }

    // getName:
    // Getter for bar name. Only way to access to private member variable - name.
	string getName() {
        // TO DO:  Write this function.    
        return this->name;  // TO DO:  update this, it is only here so code compiles.
	}

    // getValue:
    // Getter for bar value. Only way to access to private member variable - value.
	int getValue() {
		// TO DO:  Write this function.
        return this->value;  // TO DO:  update this, it is only here so code compiles.
	}
  
    // getCategory:
    // Getter for bar category.
    // Only way to access to private member variable - category.
	string getCategory() {
        // TO DO:  Write this function.
        return this->category;
    // TO DO:  update this, it is only here so code compiles.
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const { 
    // TO DO:  update this, it is only here so code compiles.
    //Bar bar1(bar1.getName(), bar1.getValue(), bar1.getCategory());
    if (this->value < other.value) {
      return true;
    } else {
      return false;
    }
	}

	bool operator<=(const Bar &other) const {
    // TO DO:  update this, it is only here so code compiles.
    //Bar bar1(bar1.getName(), bar1.getValue(), bar1.getCategory());
    if (this->value <= other.value) {
      return true;
    } else {
      return false;
    }
	}

	bool operator>(const Bar &other) const {
    // TO DO:  update this, it is only here so code compiles.
    //Bar bar1(bar1.getName(), bar1.getValue(), bar1.getCategory());
    if (this->value > other.value) {
      return true;
    } else {
      return false;
    }
	}

	bool operator>=(const Bar &other) const {
    // TO DO:  update this, it is only here so code compiles.
    //Bar bar1(bar1.getName(), bar1.getValue(), bar1.getCategory());
    if (this->value >= other.value) {
      return true;
    } else {
      return false;
    }
	}
};

