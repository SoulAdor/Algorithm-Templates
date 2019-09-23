#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	vector <int> edges;
	bool visited = false;
};

int n, m;
vector <Node> nodes;
long long answer;

void In()
{
	cin >> n >> m;
	nodes.resize(n + 1);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		nodes [u].edges.push_back(v);
		nodes [v].edges.push_back(u);
	}
}

void DFS (int id, int parent = -1)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;

	for (int child: node.edges)
	{
		if (child != parent) continue;
		DFS (child, id);
	}
}

void Solve()
{
	DFS (1);
}

void Out()
{
	cout << answer << endl;
}

int main()
{__
	In();
	Solve();
	Out();
}
