#include <bits/stdc++.h>
using namespace std;

// Might loop on case start + 1 = end, if 1 not added properly in (end - start) / 2

vector <int> v {1, 1, 3, 3, 3, 5, 5};

// Returns id of searched element in sorted list, -1 if not found. 
int BinarySearch (int start, int finish, int value)
{
   int low = 0, mid, high = 3;
   while (low <= high)
   {
      mid = low + (high - low) / 2;
      if (v[mid] == value) return mid;
      v[mid] < value ? low = mid + 1 : high = mid - 1;
   }
   return -1;
}

bool Check (int id)
{
   return v[id] >= 2;
}

int PeakFind (int start, int finish)
{
   int low = 0, mid, high = 3;
   while (low != high)
   {
      mid = low + (high - low) / 2;
      Check (mid) ? high = mid : low = mid + 1;
   }
   return low;
}

int main()
{ 
   // lower_bound returns a pointer to the first array element whose value is at least x.
   // upper_bound returns a pointer to the first array element whose value is larger than x.
   // equal_range returns both above pointers.
   // If there is no such element, the pointer points to the element after the last array element.
   cout <<  lower_bound (v.begin(), v.end(), 3) - v.begin() << endl;
   cout <<  upper_bound (v.begin(), v.end(), 3) - v.begin() << endl;
   auto r = equal_range(v.begin(), v.end(), 3);
   cout << "Number of elements: " << r.second - r.first << "\n";
}