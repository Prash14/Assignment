

/////////////////////////////////////////////////////////////////////////////

/* ABOUT THIS TEST - READ CAREFULLY

   Grading: This test is graded based on two parameters:

   1) Correctness - your implementation should follow the
   specification, and answers to the questions below should be right.

   2) Speed - the faster you can do this test, the better

   Timing: You have at most 60 minutes time for this test, after which
   you must send the test back by e-mail. If you do not accomplish
   everything to your satisfaction in that time, you must still submit
   the result in 60 minutes, with what-ever sections you have
   accomplished.

   General: The code below may contain any number of bugs. Part of
   your job is to fix them as you go.

   Tools: You need a working C++ compiler for this test. All normal/modern
   compilers should work - gcc, clang, msvc etc.

   You are allowed to use any on-line/written reference material that
   helps you.

  */

/////////////////////////////////////////////////////////////////////////////
// First Part: Basic C++ and STL.

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Animal
{
public:
  Animal() {}

  virtual void makeNoise() { std::cout << "This animal makes no sound." << std::endl; }
};


/////////////////////////////////////////////////////////////////////////////
// Start here

void animals()
{
  // Using std::vector, create an array integers and fill it with numbers
  // from 0 to 99 and print the numbers to console.
  vector<int> noOfInteger;
  for(int i = 0; i < 100; i++)
	  noOfInteger.push_back(i);

  vector<int>::iterator it;
  for(it = noOfInteger.begin(); it != noOfInteger.end();it++)
	  cout << *it << endl;

  // Inherit two classes, called Cat and Dog from the Animal class and
  // overload the makeNoise() function in both of them. Make the Cat and Dog print
  // different messages in their makeNoise().

	class Cat : public Animal
	{
	public:
	  Cat() {}

	  void makeNoise() { std::cout << "This animal makes Miau sound." << std::endl; }
	};

	class Dog : public Animal
	{
	public:
	  Dog() {}

	  void makeNoise() { std::cout << "This animal makes Bhow Bhow sound." << std::endl; }
	};

  // Below is a list of Animal objects. Insert one Cat and one Dog object into
  // the end of the list.
	std::list<Animal*> listOfAnimals;
	Cat obj1;
	Dog obj2;
	listOfAnimals.push_back(&obj1);
	listOfAnimals.push_back(&obj2);

  // Iterate over the contents of the list and call makeNoise() for each item.
  // Explain the results.
	list<Animal*>::iterator it1;
	for(it1 = listOfAnimals.begin(); it1 != listOfAnimals.end(); it1++)
	(*it1)->makeNoise();
}



// Here is a simple Goomba class. It just keeps track of how many Goombas are alive.
class Goomba
{
public:
  static int liveGoombas;

  Goomba() { liveGoombas++; };
  ~Goomba() { liveGoombas--; }
};

int Goomba::liveGoombas = 0;

// And a Goomba legion class. Please don't change this class.
class GoombaLegion
{
public:
  void add(Goomba*  goomba)
  {
    goombas.push_back(goomba);
  }
  ~GoombaLegion() {
	  vector<Goomba*>::iterator it1;
	 for(it1 = goombas.begin(); it1 != goombas.end(); it1++)
		delete *it1;
  }

private:
  std::vector<Goomba*> goombas;
};

void goombas()
{
  {
    // Below is a legion of Goombas. Please add 100 Goombas to it. Please don't
    // modify the GoombaLegion class.
    GoombaLegion legion;
	Goomba *goomba = NULL; 
	for(int i = 0; i < 100; i++) {
		goomba = new Goomba();
		legion.add(goomba);
	}
  }

  // The legion went out of scope and was destroyed. But how many Goombas are alive?
  // Please explain what happens and then fix the code.

  std::cout << "There are " << Goomba::liveGoombas << " live goombas" << std::endl;

  /*
	I fix the code by changing the Goomba class the issue is that in add function. Object 
	goomba was pass by value. So it was calling copy constructor multiple time.
	And one more issue is that the destructor was not cleanig the vector.
  */
}



int main()
{
  animals();
  goombas();

  return 0;
}
