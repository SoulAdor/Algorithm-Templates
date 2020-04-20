#include <bits/stdc++.h>
using namespace std;

// Sieve of least prime factors of number. Is prime if least prime factor is equal to number.
// Vector of sorted prime numbers less or equal than size
vector <int> sieve;
vector <int> primes;

bool IsPrime (int number)
{
    return sieve[number] == number;
}

// Fills up to size inclusive.
void FillSieve (int size)
{
	sieve.resize (size + 1);
	for (int i = 2; i <= size; i++)
	{
		if (!sieve[i])
		{
			sieve[i] = i;
			primes.push_back (i);
		}
		for (int prime: primes)
		{
			if (prime > sieve[i] || prime * i > size) break;
			sieve[prime * i] = prime;
		}
	}
}