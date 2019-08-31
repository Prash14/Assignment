/*
 * BinaryLiteral.cpp
 *
 *  Created on: Aug 27, 2019
 *      Author: Prash
 */
/* C++ 14: C++ now supports binary literals:
 * // the answer to life, the universe, etc. in..
 * auto a1 = 42;        // ... decimal
 * auto a2 = 0x2A;      // ... hexadecimal
 * auto a3 = 0b101010;  // ... binary
 *
 * This works well in combination with the new ' digit separators,
 *  for example to separate nybbles or bytes:
 *
 *  auto a = 0b100'0001;  // ASCII 'A' Here 0b means binary
 *
 */

#include"iostream"
using namespace std;

int BinaryLiteralmain()
{
	auto a = 0b100'0001;
	cout<<(char)a;

	return 0;
}
