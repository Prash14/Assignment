#include "iostream"
#include "vector"
#include "array"
#include "string"

using namespace std;



int main()
{
	auto sum = [](auto a,auto b){return a+b;};
    vector<int> vi = {1,2,3};
    array<string,2> vs = {"Hello ","World"};
	auto curSum = 0;
	for(auto item : vi)
	{
	    curSum =  sum(curSum , item);
	}

	cout<<"Vector Sum = "<<curSum<<endl;

    cout<<"String array Sum "<<endl;
    string curStr;
    for(auto item : vs)
	{
	    curStr =  sum(curStr , item);
	}
    cout<<curStr<<endl;

	return 0;
}
