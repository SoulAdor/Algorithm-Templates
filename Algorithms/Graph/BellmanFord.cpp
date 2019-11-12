#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Edge
{
	int end;
	long long weight;
};

struct Node
{
	vector <Edge> edges;
	long long distance = LLONG_MAX;
	bool visited = false;
};

int n, m, s;
vector <Node> nodes;
long long MINIMUM = -2e18;

void In()
{
	cin >> n >> m >> s;
	nodes.resize(n + 1);

	long long u, v, w;
	Edge next;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> next.end >> next.weight;
		nodes[u].edges.push_back(next);
	}
}

void UpdateDistances ()
{
	for (int i = 1; i <= n; i++) if (nodes[i].distance != LLONG_MAX)
		for (Edge edge: nodes[i].edges)
			if (nodes[edge.end].distance > nodes[i].distance + edge.weight)
				nodes[edge.end].distance = nodes[i].distance + edge.weight;
}

void CheckNegativeLoops ()
{
	for (int i = 1; i <= n; i++) if (nodes[i].distance != LLONG_MAX)
		for (Edge edge: nodes[i].edges)
			if (nodes[i].distance == LLONG_MIN || nodes[i].distance + edge.weight < nodes[edge.end].distance) 
				nodes[edge.end].distance = LLONG_MIN;
}


// Update distances n times, if anything updates after this, it is part of negative cycle
void Solve()
{
	nodes[s].distance = 0;
	for (int i = 1; i < n; i++) UpdateDistances ();
	for (int i = 1; i <= n; i++) CheckNegativeLoops ();
}

void Out()
{
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i].distance == LLONG_MAX) cout << "Unreachable" << endl;
		else if (nodes[i].distance < MINIMUM) cout << "Negative cycle" << endl;
		else cout << nodes[i].distance << endl;
	}
}

int main()
{
	In();
	Solve();
	Out();
}