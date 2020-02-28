#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// We keep smallest final number for each length
// This is increasing sequence, otherwise we would be able to find smaller number for shorter subsequence
// Complexity : O(N*log(N))
vector <int> GetLIS (const vector <long long>& numbers)
{
	vector <long long> smallest_number (numbers.size() + 1, LLONG_MAX);
	smallest_number[0] = LLONG_MIN;
	vector <int> LIS;
	for (auto number : numbers)
	{
		auto res = lower_bound (smallest_number.begin(), smallest_number.end(), number);
		int length = distance(smallest_number.begin(), res);
		smallest_number[length] = min (smallest_number[length], number);
		LIS.push_back(length);
	}
	return LIS;
}

int main()
{__
	vector <long long> arr = {0,1,2,1,4,4,3,5,2};
	vector <int> LIS = GetLIS(arr);
	cout << *max_element(LIS.begin(), LIS.end()) << endl;
	for (int i = 0; i < LIS.size(); i++) cout << LIS[i] << " ";
}