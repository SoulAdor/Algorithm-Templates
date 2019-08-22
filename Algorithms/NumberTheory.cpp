#include <bits/stdc++.h>
using namespace std;

// m > a
int getExtendedGCD (int a, int m, int* c_a, int* c_m)
{
	if(a == 0) 
	{
		*c_a = 0; *c_m = 1;
		return m;
	} 
	int c_r, c_a2;
	int gcd = getExtendedGCD (m % a, a, &c_r, &c_a2);
  	*c_a = c_a2 - (m / a) * c_r;
  	*c_m = c_r;
	return gcd;
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
	int c_a, c_m;
	getExtendedGCD (a, m, &c_a, &c_m);  
	return (c_a % m + m) % m;  			// To handle negative
}