#include <bits/stdc++.h>
using namespace std;

vector <int> subset;

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