#include <bits/stdc++.h>
using namespace std;

tuple <int, int, int> getExtendedGCD (int a, int m)
{
	if (a == 0) return {m, 0, 1};
	auto [gcd, x, y] = getExtendedGCD (m % a, a);
	return {gcd, y - (m / a) * x, x};
}

// With negative a
int mod (int a, int m) 
{ 
    return (a % m + m) % m; 
} 

int getGCD (int a, int m)
{
	return a == 0 ? m : getGCD (m % a, a);
}

int GetInverse (int a, int m)
{
	auto [gcd, x, y] = getExtendedGCD (a, m);  
	return (x % m + m) % m;  			// To handle negative
}

int main ()
{
	cout << GetInverse (7, 9) << endl;
}