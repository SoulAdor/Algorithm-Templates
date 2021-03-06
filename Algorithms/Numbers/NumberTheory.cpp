#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

// Modulo power counter
long long ModPow (long long num, long long pow)
{
	if (pow == 0) return 1;
	long long res = ModPow (num, pow / 2);
	res = (res * res) % mod;
	if (pow % 2) res = (res * num) % mod;
	return res;
}

// Usual greatest common divisor
long long getGCD (long long a, long long m)
{
	return a == 0 ? m : getGCD (m % a, a);
}

// Returns modulo, works with negative a also
long long Mod (long long a, long long m) 
{ 
   return (a % m + m) % m; 
}

// Extended Euclidian algorithm to get coefficients
tuple <long long, long long, long long> ExtendedGCD (long long a, long long m)
{
	if (a == 0) return {m, 0, 1};
	auto [gcd, x, y] = ExtendedGCD (m % a, a);
	return {gcd, y - (m / a) * x, x};
}

// Returns inverse of a modulo m if they are coprime
long long GetInverse (long long a, long long m)
{
	auto [gcd, x, y] = ExtendedGCD (a, m);
	return Mod(x, m);  			// To handle negative
}

// Primality check in O(sqrt(n))
bool IsPrime (int number) 
{
	if (number <= 1) return false;
	int maximum = sqrt(number);
	for (int i = 2; i <= maximum; i++) 
		if (number % i == 0) return false; 
	return true;
}

int main ()
{
	cout << GetInverse (7, 9) << endl;
}