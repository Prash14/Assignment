/* RangeBaseForLoop
 * =================================================
 * for ( range_declaration : range_expression )
    loop_statement

 * Parameters :
 * -------------
 * range_declaration :
 * """"""""""""""""""
 * a declaration of a named variable, whose type is the
 * type of the element of the sequence represented by
 * range_expression, or a reference to that type.
 * Often uses the auto specifier for automatic type
 * deduction.
 *
 * range_expression :
 * """"""""""""""""""
 * any expression that represents a suitable sequence
 * or a braced-init-list.
 *
 * loop_statement :
 * """"""""""""""""
 * any statement, typically a compound statement, which is the body of the loop.
 *
 */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;


int rangebasedforloop_main()
{
	std::vector<int> a;
	array <int,5> b;
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	// C++11
	for (auto it = v.begin(); it != v.end(); ++it)
		a.push_back(*it);

	// C++03
/*	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        	a.push_back(*it);
*/
	for (auto item : a)
		std::cout << item << " ";  // read only access

	std::cout << std::endl;

	int i=0;
	for (auto &item : b)
	{
		item = v.at(i++);
	}

	std::cout << std::endl;

	for (auto &item : b) {
		item *= 10;
		std::cout << item << " ";  // read only access
	}

	std::cout << std::endl;

	reverse_copy(b.begin(), b.end(),
	                      std::ostream_iterator<int>(std::cout, " "));

	std::cout << endl<<" After Reverse "<<std::endl;

	for (auto item : b)
			std::cout << item << " ";  // read only access

	sort(b.begin(),b.end());
}
