#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string s;
vector <int> Z;
long long answer;

void In()
{
	cin >> s;
}

// Fills Z with values from s in O(n).
// Z is assumed empty from the start.
// Z at 0 is 0.
void FillZ (vector <int>& Z, string& s)
{
	Z.resize(s.size(), 0);
	for (int i = 1, l = 0, r = 0; i < s.size(); i++)
	{
		// Compute value from previous iteration
		if (r >= i) Z[i] = min (Z[i-l], r - i + 1);
		// Increase manually
		while (i + Z[i] < s.size() && s[i + Z[i]] == s[Z[i]]) Z[i]++;
		// Update bounds
		if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
	}
}

// collisions[i] is true iff t collides with substring of s starting with i
void FillCollisions (vector <bool>& collisions, string& t, string& s)
{
	string concat = t + s;
	vector <int> Z;
	FillZ (Z, concat);
	collisions.resize (s.size()); 
	for (int i = 0; i < s.size(); i++)
		collisions[i] = Z[i + t.size()] >= t.size();
}

// Returns size of longest prefix of s that is palindrome
int PalindromicPrefix(string& s)
{
	string reversed = s;
	reverse(reversed.begin(), reversed.end());
	s += reversed;
	vector <int> Z;
	FillZ (Z, s);
	int size = reversed.size();
	for (int i = size, length = size; i < s.size(); i++, length--)
		if (Z[i] >= length) return length;
	return 0;
}

void Solve()
{
	FillZ (Z, s);
}

void Out()
{
	for (int z : Z)
		cout << z << ' ';
}

int main()
{__
	In();
	Solve();
	Out();
}