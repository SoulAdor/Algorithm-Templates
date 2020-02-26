#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector <int> GetPrevSmallerIds (vector <long long>& numbers)
{
	stack <int> prevSmallerIds;
	vector <int> result;
	result.resize(numbers.size());
	for (int i = 0; i < numbers.size(); i++)
	{
		while (!prevSmallerIds.empty() && numbers[prevSmallerIds.top()] >= numbers[i]) prevSmallerIds.pop();
		result[i] = prevSmallerIds.empty() ? -1 : prevSmallerIds.top();
		prevSmallerIds.push(i);
	}
	return result;
}

// Returns id of smaller number coming after each one, or -1 if such number does not exist
// We keep id's in stack, such that there is no smaller number than nubmers[id] in [i, id]
// If there were smaller number, we would always pick it over given because it is smaller and comes first
// So we either remove id from the stack, or keep it and know answer for given index
vector <int> GetNextSmallerIds (vector <long long>& numbers)
{
	stack <int> nextSmallerIds;
	vector <int> result;
	result.resize(numbers.size());
	for (int i = numbers.size()-1; i >= 0; i--)
	{
		while (!nextSmallerIds.empty() && numbers[nextSmallerIds.top()] >= numbers[i]) nextSmallerIds.pop();
		result[i] = nextSmallerIds.empty() ? -1 : nextSmallerIds.top();
		nextSmallerIds.push(i);
	}
	return result;
}

int main()
{__
	vector <long long> numbers = {1, 2, 3, 2, 0, 10, 11, 3};
	vector <int> answer = GetNextSmallerIds (numbers);
	for (int ans : answer) cout << ans << " ";
	cout << endl;
}