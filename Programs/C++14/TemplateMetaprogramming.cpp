/*
 * TemplateMetaprogramming.cpp
 *
 *  Created on: Aug 27, 2019
 *      Author: Prash
 */


#include <iostream>
using namespace std;

/* Template MetaProgramming
 * The special thing about above program is: calculation is done at compile time.
 * So, it is compiler that calculates factorial. To understand how compiler does
 * this,let us consider the following facts about templates and enums:
 * 1) We can pass nontype parameters (parameters that are not data types) to
 *    class/function templates.
 * 2) Like other const expressions, values of enumaration constants are evaluated
 *    at compile time.
 * 3) When compiler sees a new argument to a template, compiler creates a new
 * instance of the template.
 *
 */

namespace TemplateMetaProgramming
{
   template<int n>
   class factorial
   {
   public:
	   enum { val = n*factorial<n-1>::val };
   };

   template<>   //Like Speciallized Template
   class factorial<0>
   {
   public:
	   enum { val = 1 };
   };
}


/* Template Specialization
 * Template is a great feature in C++. We write code once and use it for any data
 * type including user defined data types.
 * It is possible in C++ to get a special behavior for a particular data type.
 * This is called template specialization.
 *
 */

namespace TemplateSpeciallization
{
    template <class T>   //Normal template
    class Test
	{
    	// Data memnbers of test
    	public:
    	Test()
    	{
    		// Initializstion of data memnbers
    		cout << "General template object \n";
    	}
    	// Other methods of Test
    };

    template <>     //Note template specialization syntax here
                    //it blanks and in class they put <int>
    class Test <int>
    {
    	public:
    	Test()
    	{
    		// Initializstion of data memnbers
    		cout << "Specialized template object\n";
    	}
    };
}

using namespace TemplateMetaProgramming;
using namespace TemplateSpeciallization;

int Template_main()
{

	cout<<factorial<5>::val<<endl;

	cout<<"Template Speciallization"<<endl;

	Test<int> a;
	Test<char> b;
	Test<float> c;

	return 0;
}

