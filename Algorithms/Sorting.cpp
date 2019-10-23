#include <bits/stdc++.h>
using namespace std;


int GetRandom (int start, int finish)
{
	return rand() % (finish - start + 1) + start;
}

int GetPivot (std::vector <int>& arr, int start, int finish)
{
	return arr[(start + finish) / 2];
}

// Take pivot from the array.
// Values in [start, i) <= pivot 
// Values in (j, finish] >= pivot
// We want i to be strictly more than j to divide array into smaller parts
// Can also be used to get element in i'th position without sorting in O(n) if called conditionally in the end
void QuickSort (std::vector <int>& arr, int start, int finish)
{
	if (start >= finish) return;
	int i = start, j = finish;
	for (int pivot = GetPivot(arr, start, finish); i <= j; i++, j--)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i > j) break;
		std::swap (arr[i], arr[j]);
	}
	QuickSort (arr, start, j);
	QuickSort (arr, i, finish);
}

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
   QuickSort (v, 0, v.size() - 1);
   for (int x: v) cout << x << " ";
}