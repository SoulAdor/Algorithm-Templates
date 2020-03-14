#include <bits/stdc++.h>
using namespace std;

unsigned long long SetBit (unsigned long long number, int position)
{
	return number | 1ULL << position;
}

unsigned long long GetBit (unsigned long long number, int position)
{
	return number & 1ULL << position;
}

unsigned long long ChangeBit (unsigned long long number, int position)
{
	return number ^ 1ULL << position;
}

unsigned long long ClearBit (unsigned long long number, int position)
{
	return number & !(1ULL << position);
}

unsigned long long StripLowestBit (unsigned long long number)
{
	return number & (number - 1);
}

bool PowerOfTwo (unsigned long long number)
{ 
	return number && !StripLowestBit (number);
}

int HighestBitPosition (unsigned long long number) 
{
	return 63 - __builtin_clzll(number);
}

unsigned long long HighestBit (unsigned long long number) 
{ 
	return 1ULL << HighestBitPosition (number);
}

int LowestBitPosition (unsigned long long number) 
{
	return __builtin_ctzll(number);
}

int LowestBit (unsigned long long number) 
{
	return 1ULL << LowestBitPosition (number);
}


/*
   // All take unsigned values as arguments
   // Add ll to the end for long longs : __builtin_clzll(x)

	Number of leading zeroes: 			__builtin_clz(x)
  	Number of trailing zeroes : 		__builtin_ctz(x)
  	Number of 1-bits: 					__builtin_popcount(x) 
	Parity of number: 					__builtin_parity(n)
*/

int main()
{
	bitset <10> bs;
   bs[1] = 1;
   bs[3] = 1;
   bs[4] = 1;
   bs[7] = 1;
   cout << bs[4] << "\n"; // 1
   cout << bs[5] << "\n"; // 0
   // Returns number of ones
   cout << bs.count() << "\n"; 
   // Bit operations
   bitset<10> bitset_a(string("0010110110"));
   bitset<10> bitset_b(string("1011011000"));
   cout << (bitset_a & bitset_b) << "\n"; // 0010010000
   cout << (bitset_a | bitset_b) << "\n"; // 1011111110
   cout << (bitset_a ^ bitset_b) << "\n"; // 1001101110
   cout << endl;
   // Can do bitwise operations!
   cout << (bs << 1) << endl;
   cout << (bs << 2) << endl;
}