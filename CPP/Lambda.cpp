#include <iostream>
#include <algorithm>
#include <vector>

void my_function(const std::string& str)
{
  std::cout << "Country: " << str << std::endl;
}

int main()
{
  std::vector<std::string> my_vector;

  my_vector.push_back("USA");
  my_vector.push_back("UK");
  my_vector.push_back("JAPAN");
  my_vector.push_back("CHINA");
  my_vector.push_back("RUSSIA");
  my_vector.push_back("INDIA");
  my_vector.push_back("SOUTH AFRICA");

  for_each(my_vector.begin(), my_vector.end(), my_function);
  return 0;
}
/*
Here is a sample example where we create my_vector as string vector and try to iterate 
through all the elements of the vector using for_each.  

for_each takes first and last iterator as argument and tries to iterate through 
all the elements of the vector. Also note that my_function is a function which takes 
std::string as argument.

Now lets take another example of using for_each using function objects.
*/

/**
 * @Author: Mital Vora<mital.d.vora@gmail.com>
 *
 * for_each Example 2: Demonstrating c++11 new for_each loop
 * using class object
 */

#include <iostream>
#include <algorithm>
#include <vector>

class MyClass
{
  public:
    void operator()(const std::string& str)
    {
      std::cout << "Country: " << str << std::endl;
    }
} myClassObject;

int main()
{
  std::vector<std::string> my_vector;

  my_vector.push_back("USA");
  my_vector.push_back("UK");
  my_vector.push_back("JAPAN");
  my_vector.push_back("CHINA");
  my_vector.push_back("RUSSIA");
  my_vector.push_back("INDIA");
  my_vector.push_back("SOUTH AFRICA");

  for_each(my_vector.begin(), my_vector.end(), myClassObject);
  return 0;
}

/*
In above example we are using the same vector but instead of passing a function.. 
we are now passing a functor ( object which has operator() overloaded).

In both of the above examples we have to declare the "my_function" and "MyClass"
 and object of "MyClass" separately. Isn't this non-intuitive ?? can we declare 
 the function as and when we require it ?? The answer is yes. C++11 now supports 
 lambda expressions. We can declare functions whenever we wanna use it. Lets take an 
 example of lambda function:
*/

/**
 * for_each Example 3: Demonstrating c++11 new for_each loop
 * using lambda function
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<std::string> my_vector;

  my_vector.push_back("USA");
  my_vector.push_back("UK");
  my_vector.push_back("JAPAN");
  my_vector.push_back("CHINA");
  my_vector.push_back("RUSSIA");
  my_vector.push_back("INDIA");
  my_vector.push_back("SOUTH AFRICA");

  for_each(my_vector.begin(), my_vector.end(),
      [](const std::string& str) { std::cout << "Country: " << str << std::endl; });
  return 0;
}
/*
So here in the third argument of for_each(), we are passing a lambda expression. 
The lambda expression works exactly the same way as both the examples above. 
It takes string as argument and prints the string
*/