#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> st;
st.resize(n + 1);

// Get maximum value from start to finish inclusive in O(1)
int STGetMax (int start, int finish)
{
	int pow = (int) log2 (finish - start + 1);
	return max (st[start][pow], st[finish - (1 << pow) + 1][pow]);
}

// Initialize sparse table. it is the same values at index 0 and maximum of 2^i values sterting from here at index i for each element
void STInit ()
{
   for (int i = 1; i <= n; i++) st[i].push_back(values[i]);
   for (int size = 2; size <= n; size <<= 1)
      for (int i = 1; i <= n && i + size - 1 <= n; i++)
		   st[i].push_back (max (st[i].back(), st[i + (size >> 1)].back() ) );
}