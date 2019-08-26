#include <bits/stdc++.h>
using namespace std;

/*
	Fenwick tree can be used to get sum of frequencies of numbers less than given one
	Get 		O(log(n))
	Update 	O(log(n))

	Current implementation starts with 1 on array.
	For each value, we store sum of n values stored in consecutive less than it.
	N = 2 ^ r, where r is number of consecutive least significant zeroes in binary representation of number
	Or number of times we can divide the number by 2 without any remainder.

	Example: 
	4 = 100; 	N = 2 ^ 2 = 4 (two zeroes from the left, we store sum of values in 4, 3, 2, 1)
	7 = 111; 	N = 2 ^ 0 = 1 (no zeroes from the left, sum in 7)
	10 = 1010; 	N = 2 ^ 1 = 2 (one zero from the left, sum in 10, 9)

	As we see, the more "even" number is, the more elements contribute to sum stored there.
	Powers of 2 store all elemets before them, while odd numbers store only themselves.  

	To get the sum from 1 to k, we take value at k (it might contain sum of several previous values)
	and then go to biggest element that we need. 
	If the number ends with a1(00..), - possibly several zeros, we store exactly sum of exactly 
	a1(00..) numbers in there, so the next index will be at a0(00..). The first least significant 1 changed to 0
	in number's binary form. If there are no 1's, we are at 0 and all the sums have been counted. Number of flips
	cannot be more than number's binary form's length, so it's log(N)

	Update is a bit trickier. We need to add difference to every interval that contains given index.
	As we saw, a1(00..) contains all sums on indices up to a0(00..) not inclusive.
	So, for every prefix a, we update a1.. if number is of form a0.. but not all zeros, or itself. 
	We insure at least one of them is not zero by starting couting at first least significant 1 
	(so we get the number itself and that case is over)
	Only numbers that have 1 at position bigger than starting one and 0 before it are left.
	We only need the ones that have 0 at corresponding position in a updated index. 
	We can iterate over them by adding 1 to the least significant bit.
*/

template <typename T>
class BIT 
{
	vector <T> BIT;
	int maximum_element;

	int LowestBit (int number) 
	{ 
		return number & (-number);
	}

	int StripLowestBit (int number)
	{
		return number & (number - 1);
	}

	public:

	// Creates BIT for 1 to size inclusive
	void Init (int size)
	{
		maximum_element = size;
		BIT.resize (maximum_element + 1);
	}

	T GetFrequency (int index)
	{
		T frequency = 0;
		for (; index; index = StripLowestBit (index)) frequency += BIT[index];
		return frequency;
	}

	T GetFrequency (int start, int finish)
	{
		return GetFrequency (finish) - GetFrequency (start - 1);
	}

	void UpdateFrequency (int index, int difference)
	{ 
		for (; index <= maximum_element; index += LowestBit (index)) BIT[index] += difference;
	}
};