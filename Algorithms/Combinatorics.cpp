#include <bits/stdc++.h>
using namespace std;

vector <int> subset;
vector <vector <long long>> C;
long long mod = 10e9 + 7;

void InitC (int n)
{
	C.resize(n + 1);
	for (int i = 0; i <= n; i++) C[i].resize(n + 1);
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= n; j++)
			C[i][j] = -1;
}

long long GetC (long long n, long long k)
{
	if (C[n][k] != -1) return C[n][k];
	if (k == 0 || n == k) return C[n][k] = 1;
	return C[n][k] = (GetC(n - 1, k) + GetC(n - 1, k - 1)) % mod;
}

void Subset ()
{
   for (int value : subset) cout << value << " ";
   cout << endl;
}

void Subsets (vector <int>& v, int position)
{
   if (position == v.size()) return Subset ();
   Subsets (v, position + 1);
   subset.push_back (v[position]);
   Subsets (v, position + 1);
   subset.pop_back();
}

void Permutation (vector <int>& v)
{
   for (int value : v) cout << value << " ";
   cout << endl;
}

void Permutations (vector <int>& v, int start)
{
   if (start == v.size()) return Permutation (v);
   for (int i = start; i < v.size(); i++)
   {
      swap (v[start], v[i]);
      Permutations (v, start + 1);
      swap (v[start], v[i]);
   }  
}

int main()
{ 
   vector <int> v = {2, 0, 4, 4, 5};
   Subsets (v, 0);
   Permutations (v, 0);
}