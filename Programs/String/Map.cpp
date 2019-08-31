/*
 * Map.cpp
 *
 *  Created on: Aug 30, 2019
 *      Author: Prash
 */

#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int Map_main()
{

	// empty map container
	map<int, string> gquiz1;

	// insert elements in random order
	gquiz1.insert(pair<int, string>(1, "Krishna"));
	gquiz1.insert(pair<int, string>(2, "Vibha"));
	gquiz1.insert(pair<int, string>(3, "Shunham"));
	gquiz1.insert(pair<int, string>(4, "Prashant"));
	gquiz1.insert(pair<int, string>(5, "Payal"));
	gquiz1.insert(pair<int, string>(6, "Saanvi"));
	gquiz1.insert(pair<int, string>(7, "Anaysha"));

	cout << "\nThe map gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (auto &itr : gquiz1 ) {
		cout << '\t' << itr.first
			<< '\t' << itr.second << '\n';
	}
	cout << endl;

	// assigning the elements from gquiz1 to gquiz2
	map<int, string> gquiz2(gquiz1.begin(), gquiz1.end());

	// print all elements of the map gquiz2
	cout << "\nThe map gquiz2 after"
		<< " assign from gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	// remove all elements up to
	// element with key=3 in gquiz2
	cout << "\ngquiz2 after removal of"
			" elements less than key=3 : \n";
	cout << "\tKEY\tELEMENT\n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	// remove all elements with key = 4
	int num;
	num = gquiz2.erase(2);
	cout << "\ngquiz2.erase(2) : ";
	cout << num << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	cout << endl;

	// lower bound and upper bound for map gquiz1 key = 5
	cout << "gquiz1.lower_bound(5) : "
		<< "\tKEY = ";
	cout << gquiz1.lower_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< gquiz1.lower_bound(5)->second << endl;
	cout << "gquiz1.upper_bound(5) : "
		<< "\tKEY = ";
	cout << gquiz1.upper_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< gquiz1.upper_bound(5)->second << endl;

	return 0;
}



