#include <iostream>
#include "barchartanimate.h"
using namespace std;
#include <cassert>
//
// testBarDefaultConstructor()
//
// functions to test default constructor for Bar object
//
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}


//
// testBarParamConstructor()
//
// functions to test parameter passed in constructor Bar object
//

// test 1
bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

// test 2
bool testBarParamConstructor2() {
	Bar b("Dubai", 3310000, "UAE");
    if (b.getName() != "Dubai") {
    	cout << "testBarParamConstructor2: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 3310000) {
    	cout << "testBarParamConstructor2: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "UAE") {
    	cout << "testBarParamConstructor2: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor2: all passed!" << endl;
    return true;
}


//
// testOperators() - testing <, <=, >, >=
//
// functions to test getter values (name, value, category)
//

bool lessThanTest(Bar& b1, Bar& b2) {
  // b2 < b1
  if (b1 < b2) {
    cout << "testOperator: < failed!" << endl;
    return false;
  } else if (b2 >= b1) {
    cout << "testOperator: < failed!" << endl;
    return false;
  } else if (!(b2<=b1)) {
    cout << "testOperator: < failed!" << endl;
    return false;
  } else {
    cout << "testOperator: < passed!" << endl;
    return true;
  }
}

bool lessThanEqTest(Bar& b1, Bar& b2, Bar& b3) {
  // b1 b2 same and smaller than b3
  if (b3 < b1) {
    cout << "testOperator: <= failed!" << endl;
    return false;
  } else if (!(b2 <= b1)) {
    cout << "testOperator: <= failed!" << endl;
    return false;
  } else if (!(b1 <= b3)) {
    cout << "testOperator: <= failed!" << endl;
    return false;
  } else if (!(b2 < b3)) {
    cout << "testOperator: <= failed!" << endl;
    return false;
  } else if (!(b2 <= b3)) {
    cout << "testOperator: <= failed!" << endl;
    return false;
  } else {
    cout << "testOperator: <= passed!" << endl;
    return true;
  }
}

bool greaterThanTest(Bar& b1, Bar& b2) {
  // b1 > b2
  if (b2 > b1) {
    cout << "testOperator: > failed!" << endl;
    return false;
  } else if (b2 >= b1) {
    cout << "testOperator: > failed!" << endl;
    return false;
  } else if (!(b2<=b1)) {
    cout << "testOperator: > failed!" << endl;
    return false;
  } else {
    cout << "testOperator: > passed!" << endl;
    return true;
  }
}

bool greaterThanEqTest(Bar& b1, Bar& b2, Bar& b3) {
  // b1 b2 same and smaller than b3
  if (b3 < b1) {
    cout << "testOperator: >= failed!" << endl;
    return false;
  } else if (!(b2 >= b1)) {
    cout << "testOperator: >= failed!" << endl;
    return false;
  } else if (!(b3 >= b1)) {
    cout << "testOperator: >= failed!" << endl;
    return false;
  } else if (!(b3 > b2)) {
    cout << "testOperator: >= failed!" << endl;
    return false;
  } else if (!(b3 >= b2)) {
    cout << "testOperator: >= failed!" << endl;
    return false;
  } else {
    cout << "testOperator: >= passed!" << endl;
    return true;
  }
}

void testOperators() {
  // test 1 - Same country
  Bar b1("NYC", 18823000, "US");  // higher
  Bar b2("LA", 3900000, "US");  // equal to chic
  Bar b3("Chicago", 3900000, "US");  // equal to la
  // test 2 - Different country, same value
  Bar b4("Chicago", 1020, "US");  // equal to paris
  Bar b5("NYC", 1300, "US");  // higher
  Bar b6("Paris", 1020, "France");  // equal to chic
  
  cout << "   Testing L operator Test 1:" << endl;
  lessThanTest(b1,b2);
  cout << "   Testing L operator Test 2:" << endl;
  lessThanTest(b5,b6);
  
  cout << "   Testing LE operator Test 1:" << endl;
  lessThanEqTest(b2,b3,b1);
  cout << "   Testing LE operator Test 2:" << endl;
  lessThanEqTest(b4,b6, b5);
  
  cout << "   Testing G operator Test 1:" << endl;
  greaterThanTest(b1,b2);
  cout << "   Testing G operator Test 2:" << endl;
  greaterThanTest(b5,b6);
  
  cout << "   Testing GE operator Test 1:" << endl;
  greaterThanEqTest(b2,b3,b1);
  cout << "   Testing GE operator Test 2:" << endl;
  greaterThanEqTest(b2,b3,b1);
}
  

// TESTING barchart.h

//
// testBarChartDefaultConstructor()
//
// functions to test default constructor for BarChart object
//
bool testBarChartDefaultConstructor() {
	BarChart b;
  if (b.getSize() != 0) {
    cout << "testBarChartDefaultConstructor: getSize failed" << endl;
    return false;
  } else if (b.getFrame() != "") {
    cout << "testBarChartDefaultConstructor: getFrame failed" << endl;
    return false;
  }
  cout << "testBarChartDefaultConstructor: all passed!" << endl;
  return true;
}



//
// testBarChartParamConstructor()
//
// functions to test parameter passed in constructor BarChart object
//
bool testBarChartParamConstructor() {
	BarChart b(10);
  int count = 0;
  for (int i = 0; i < 10; i++) {
    b.addBar("a",i,"b");
    count++;
  }
  
  if (count != 10) {
    cout << "testBarChartParamConstructor: all failed!" << endl;
    return false;
  }
  cout << "testBarChartParamConstructor: all passed!" << endl;
  return true;

}


// testBarChartGraph()
// Tests to see if the color maps and graph works

void testBarChartGraph() {
  BarChart bc(10);
  bc.addBar("Chicago", 1020, "US");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Paris", 1200, "France");
  bc.setFrame("1950");

  string red("\033[1;36m");
  string blue("\033[1;33m");
  map < string, string > colorMap;
  colorMap["US"] = red;
  colorMap["France"] = blue;
  bc.graph(cout, colorMap, 3);
  stringstream result("");
  bc.graph(result, colorMap, 3);

  stringstream correct("");

  correct << red;
  for (int i = 0; i < 60; i++) {
    correct << BOX;
  }
  correct << " NYC 1300" << endl;

  correct << blue;
  for (int i = 0; i < (1200 * 60 / 1300); i++) {
    correct << BOX;
  }
  correct << " Paris 1200" << endl;

  correct << red;
  for (int i = 0; i < (1020 * 60 / 1300); i++) {
    correct << BOX;
  }
  correct << " Chicago 1020" << endl;

  string R = result.str();
  string C = correct.str();

  if (R.size() != C.size()) {
    cout << "strings diff in size (R=" << R.size() << R.size() << ",C=" <<
      C.size() << ")" << endl;
  }
  for (size_t i = 0; i < R.size() && i < C.size(); i++) {
    if (result.str()[i] != correct.str()[i]) {
      cout << "strings diff at index " << i <<
        " (R=" << result.str()[i] << ")" << endl;
    }
  }
  assert(R.size() == C.size());
  assert(R == C);
  cout << endl << correct.str();
}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
  testBarParamConstructor2();
  testOperators();
  testBarChartDefaultConstructor();
  testBarChartParamConstructor();
  testBarChartGraph();
	
    return 0;
}