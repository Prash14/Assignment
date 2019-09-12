/*
 * DispatchTable.cpp
 *
 *  Created on: Sep 9, 2019
 *      Author: Prash
 *  The example shows a simple dispatch table that maps characters to function objects.
 *
 */

// dispatchTable.cpp

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
using namespace std;

int dispathTable_main(){

  // dispatch table
  map< const char , function<double(double,double)> > dispTable{
    {'+',[](double a, double b){ return a + b;} },
    {'-',[](double a, double b){ return a - b;} },
    {'*',[](double a, double b){ return a * b;} },
    {'/',[](double a, double b){ return a / b;} } };

  /* function<double(double,double)> :
   * function is a so called polymorphic function wrapper
   * return double
   * input Parameter : double,double
   */
  // do the math
  cout << "3.5+4.5= " << dispTable['+'](3.5,4.5) << endl;
  cout << "3.5-4.5= " << dispTable['-'](3.5,4.5) << endl;
  cout << "3.5*4.5= " << dispTable['*'](3.5,4.5) << endl;
  cout << "3.5/4.5= " << dispTable['/'](3.5,4.5) << endl;

  // add a new operation
  dispTable['^']=  [](double a, double b){ return pow(a,b);};
  cout << "3.5^4.5= " << dispTable['^'](3.5,4.5) << endl;

  return 0;
}



