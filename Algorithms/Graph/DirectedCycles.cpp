#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	vector <int> edges;
	bool visited = false;
	bool finished = false;
};

int n, m;
vector <Node> nodes;
vector <int> cycle;

void In()
{
	cin >> n >> m;
	nodes.resize (n + 1);
	int start, finish;
	for (int i = 0; i < m; i++)
	{ 
		cin >> start >> finish;
		nodes [start].edges.push_back (finish);
	}
}

// Keep track of visited and finished on each node.
// If we ever get to visited but not finished, we got up the stack.
// This implementation keeps track of parent id and adds cycle recursively
// Also works with multiple edges and loops
// For undirected, any visited and not parent is a cycle

int parent_cycle = 0;
void FindCycle (int id)
{
	Node& node = nodes[id];
	if (node.visited) return;

	node.visited = true;

	for (int child: node.edges)
	{
		if (parent_cycle != 0) break;
		if (nodes[child].visited && !nodes[child].finished) 
		{
			parent_cycle = child;
			break;
		}
		FindCycle (child);
	}
	if (parent_cycle > 0) cycle.push_back(id);
	if (parent_cycle == id) parent_cycle = -1;

	node.finished = true;
}

void Solve()
{
	for (int i = 1; i <= n; i++)
		if (parent_cycle == 0) FindCycle (i);
}

void Out()
{
	std::reverse(cycle.begin(), cycle.end());
	for (int node: cycle) cout << node << " ";
}

int main()
{__
	In();
	Solve();
	Out();
}
