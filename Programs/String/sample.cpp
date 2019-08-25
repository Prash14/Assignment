/*
 * sample.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: Prash
 */


// stod example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stod
using namespace std;

int string_main ()
{
  string orbits ("365.24 29.53");
  string::size_type sz;     // alias of size_t
  auto len = orbits.length();
  auto size = orbits.size();
  cout<<"Length "<<len<<" size "<<size<<" sz "<<sz<<endl;
  double earth = stod (orbits,&sz);
  double moon = stod (orbits.substr(sz));
  cout << "The moon completes " << (earth/moon) << " orbits per Earth year.\n";
  cout<<"Moon "<<moon<<"\t Earth "<<earth<<ends;
  cout<<"sz ="<<sz<<endl;
  return 0;
}


