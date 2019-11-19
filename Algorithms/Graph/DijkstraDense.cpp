#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, s;
vector <vector <int>> weights;
vector <long long> distances;

void In()
{
	cin >> n >> s;
	weights.resize(n + 1, vector <int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> weights[i][j];
}

void Dijkstra (int start, vector <long long>& distances)
{
	vector <bool> found;
	distances.resize(n + 1, LLONG_MAX);
	found.resize(n + 1, false);

	distances[start] = 0;
	int min_id;
	long long min_weight;

	for (int count = 2; count <= n; count++) 
	{
		min_weight = LLONG_MAX;
		for (int i = 1; i <= n; i++) if (!found[i] && distances[i] < min_weight)
		{
			min_weight = distances[i];
			min_id = i;
		}
		found[min_id] = true;
		for (int i = 1; i <= n; i++) if (!found[i] && weights[min_id][i] != -1)
			distances[i] = min (distances[i], distances[min_id] + weights[min_id][i]);
	}
}

void Solve()
{
	Dijkstra (s, distances);
}

void Out()
{
	for (int i = 1; i <= n; i++)
		cout << (distances[i] == LLONG_MAX ? -1 : distances[i]) << " ";
}

int main()
{
	In();
	Solve();
	Out();
}