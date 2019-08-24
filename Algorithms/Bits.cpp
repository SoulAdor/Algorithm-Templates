#include <bits/stdc++.h>
using namespace std;

// Changes bit at position starting from 0
int SetBit (int number, int position)
{
	return number | 1 << position;
}

int GetBit (int number, int position)
{
	return number & 1 << position;
}

int ChangeBit (int number, int position)
{
	return number ^ 1 << position;
}

int ClearBit (int number, int position)
{
	return number & !(1 << position);
}

int StripLowestBit (int number)
{
	return number & (number - 1);
}

bool PowerOfTwo (int number)
{ 
	return number && !StripLowestBit (number);
}

int HighestBitPosition (int number) 
{ 
	return log2 (number);
}

int HighestBit (int number) 
{ 
	return 1 << HighestBitPosition (number);
}

int LowestBit (int number) 
{ 
	return number & (-number);
}


/*
	Number of leading zeroes: 			builtin_clz(x)
  	Number of trailing zeroes : 		builtin_ctz(x)
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