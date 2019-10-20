#include <bits/stdc++.h>
using namespace std;

void MergeSort (vector <int> &v)
{
   if (v.size() <= 1) return;
   vector <int> left (v.begin(), v.begin() + v.size() / 2); MergeSort (left);
   vector <int> right (v.begin() + v.size() / 2, v.end());  MergeSort (right);
   for (int i = 0, l = 0, r = 0; i < v.size(); i++)
      v[i] = r == right.size() || (l != left.size() && left[l] < right[r]) ? left[l++] : right[r++];
}

void InsertionSort (vector <int>& v)
{
   for (int i = 0; i < v.size(); i++)
      for (int j = i; j > 0 && v[j] < v[j-1]; j--)
         swap (v[j], v[j-1]);
}

int main()
{
   vector <int> v = {6, 2, 3, 0, 1, 0, 3};
   v = {6, 2, 3, 0, 1, 0, 3};
   MergeSort (v);
   for (int x: v) cout << x << " ";
}