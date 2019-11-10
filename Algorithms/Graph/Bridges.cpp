#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	std::vector <int> edges;
	bool visited = false;
	int depth;
	int low_depth;
	int island_id;
};

int n, m;
std::vector <Node> nodes;
int islands;

void In()
{
	cin >> n >> m;
	nodes.resize(n + 1);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		nodes[u].edges.push_back(v);
		nodes[v].edges.push_back(u);
	}
}

void ResetVisited ()
{
	for (Node& node: nodes) node.visited = false;
}

// If we cannot go higher than node then it is a bridge. 
// Works for back edges too.
bool IsBridge (int start, int end)
{
	if (nodes[end].depth < nodes[start].depth) std::swap(start, end);
	return nodes[end].low_depth > nodes[start].depth;
}

void FillIslands (int id)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;

	node.island_id = islands;
	for (int child: node.edges) if (!IsBridge(id, child)) 
		FillIslands (child);
}

// Count how low can we get from subtree without going up parent edge.
void FillTimes (int id, int parent = -1, int depth = 0)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;
	
	node.depth = node.low_depth = depth;
	for (int child: node.edges) if (child != parent) 
	{
		FillTimes (child, id, depth + 1);
		node.low_depth = std::min (node.low_depth, nodes[child].low_depth);
	}
}

void Solve()
{
	for (int i = 1; i <= n; i++) FillTimes (i);
	ResetVisited ();
	for (int i = 1; i <= n; i++) if (!nodes[i].visited) 
	{
		islands++;
		FillIslands(i);
	}
}

void Out()
{
	cout << islands << std::endl;
	for (int i = 1; i <= n; i++)
		cout << nodes[i].island_id << " ";
}

int main()
{
	In();
	Solve();
	Out();
}