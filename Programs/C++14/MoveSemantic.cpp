/* MoveSemantic.cpp
 */

#include <iostream>
using namespace std;

class A
{
public:
	// constructor
	/* explict keyword : To avoid implicit conversions which may lead to unexpected results*/
	explicit A(size_t length)
	: mLength(length), mData(new int[length]) {
		cout<<"explicit Constructor"<<endl;
	}

	// Copy constructor.
	A(const A& other)
	: mLength(other.mLength), mData(new int[other.mLength])
	{
		cout << "A(const A&). length = "
				<< other.mLength << ". Copying resource." << endl;

		copy(other.mData, other.mData + mLength, mData);
	}

	// Copy assignment operator.
	A& operator=(const A& other)
	{
		cout << "operator=(const A&). length = "
				<< other.mLength << ". Copying resource." << endl;

		if (this != &other)
		{
			delete[] mData;  // Free the existing resource.
			mLength = other.mLength;
			mData = new int[mLength];
			std::copy(other.mData, other.mData + mLength, mData);
		}
		return *this;
	}


	// move constructor
	/* The move constructor is much faster than a copy constructor because
	 * it doesn't allocate memory nor does it copy memory blocks.
	 */
	A(A&& other) noexcept
	{
		cout<<"Move Constructor"<<endl;
		mData = other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
		//or simply write:
		//  *this = move(other);
	}

	// move assignment
	/* A move assignment operator is similar to a copy constructor except that
	 * before pilfering the source object, it releases any resources that its
	 * object may own. The move assignment operator takes the following steps:
	 * 1) Release any resources that *this currently owns.
	 * 2) Pilfer other's resource.
	 * 3) Set other to a default state.
	 * 4) Return *this.
	 */
	A& operator=(A&& other) noexcept
	{
		mData =  other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
		cout<<"Move Assignment"<<endl;
		return *this;
	}

	size_t getLength() { return mLength; }

	int* get_mData() { return mData; }

private:
	int *mData;
	size_t mLength;
};

int Movemain()
{
	A a(11), b(22);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;
	swap(a,b);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;

	return 0;
}
