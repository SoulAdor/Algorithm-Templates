#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	vector <int> edges;
};

int n;
vector <Node> nodes;
long long answer;

void In()
{
	cin >> n;
	nodes.resize(n + 1);
	int start, finish;
	for (int i = 1; i < n; i++)
	{
		cin >> start >> finish;
		nodes [start].edges.push_back(finish); 
		nodes [finish].edges.push_back(start); 
	}
}

void DFS (int id, int parent = -1)
{
	Node& node = nodes[id];
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
