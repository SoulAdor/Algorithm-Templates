#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{__
   double test = 123.123123;

   // Notation, precision
   cout << fixed;							// Use fixed notaion not scientific one
   cout.precision(3);					// Guaranteed output size (123.123)
   cout << test;
}