#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

/*
* First element of values is value, and second one is id.
*
* Find first element that would count some value twice or end.
* If we have seen every element, then update result.
* Remove the element or decrease its count.
*/
long long GetSmallestDifference (vector <pair<long long, int>>& values, int num_sets)
{
	sort (values.begin(), values.end());
	map <int, int> seen;
	long long result = LLONG_MAX;
	for (int start = 0, finish = 0; start != values.size(); start++)
	{
		for (; finish != values.size() && seen.size() != num_sets; finish++) seen[values[finish].second]++;
		if (seen.size() == num_sets) result = min (result, values[finish - 1].first - values[start].first);
		seen[values[start].second] == 1 ? seen.erase (values[start].second) : seen[values[start].second]--;
	}
	return result;
}

int main()
{__

	vector <vector <int>> values;
	values.push_back({1,2,4});
	values.push_back({3,5,7});
	values.push_back({5,3,8});

	vector <pair<long long, int>> numbers;
	for (int i = 0; i < values.size(); i++)
		for (int j = 0; j < values[i].size(); j++)
			numbers.push_back({values[i][j], i});
	cout << GetSmallestDifference(numbers, values.size());
}