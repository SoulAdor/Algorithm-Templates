#include <bits/stdc++.h>
using namespace std;

vector <int> v {1, 1, 3, 3, 3, 5, 5};

// Returns id of searched element in sorted list, -1 if not found. 
long long BinarySearch (long long start, long long finish, long long value)
{
   while (start < finish)
   {
      long long mid = start + (finish - start) / 2;
      if (v[mid] == value) return mid;
      v[mid] < value ? start = mid + 1 : finish = mid - 1;
   }
   return -1;
}

bool Check (long long value)
{
   return v[value] >= 3;
}

long long FirstTrue (long long start, long long finish)
{
   while (start != finish)
   {
      long long mid = start + (finish - start) / 2;
      Check (mid) ? finish = mid : start = mid + 1;
   }
   return start;
}

long long LastFalse (long long start, long long finish)
{
   while (start != finish)
   {
      long long mid = start + (finish - start + 1) / 2;
      Check (mid) ? finish = mid - 1 : start = mid;
   }
   return start;
}

int main()
{ 
   // lower_bound returns a pointer to the first array element whose value is at least x, or end().
   // upper_bound returns a pointer to the first array element whose value is larger than x, or end().
   // equal_range returns both above pointers.
   // If there is no such element, the pointer points to the element after the last array element.
   cout <<  lower_bound (v.begin(), v.end(), 3) - v.begin() << endl;
   cout <<  upper_bound (v.begin(), v.end(), 3) - v.begin() << endl;
   auto r = equal_range(v.begin(), v.end(), 3);
   cout << "Number of elements: " << r.second - r.first << "\n";
   cout << BinarySearch (0,5,3) << "\n";
   cout << FirstTrue (0,5) << "\n";
   cout << LastFalse (0,5) << "\n";
}