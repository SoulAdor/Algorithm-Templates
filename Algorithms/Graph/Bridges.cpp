#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	std::vector <int> edges;
	bool visited = false;
	int visit_time;
	int lowest_time;
	int island_id;
};

int counter = 0;
int islands = 0;

int n, m;
std::vector <Node> nodes;
long long answer;

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

// If child's lowest time is smaller or equal to parent's visit time, we can go to parent without edge
bool IsBridge (int parent, int child)
{
	if (nodes[child].visit_time < nodes[parent].visit_time) swap(parent, child);
	return nodes[child].lowest_time > nodes[parent].visit_time;
}

void FillIslands (int id)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;

	node.island_id = islands;
	for (int child: node.edges)
		if (!IsBridge(id, child)) FillIslands (child);
}

void FillTimes (int id, int parent = -1)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;
	
	node.lowest_time = node.visit_time = counter++;
	for (int child: node.edges) if (child != parent) 
	{
		FillTimes (child, id);
		node.lowest_time = min (node.lowest_time, nodes[child].lowest_time);
	}
}

void Solve()
{
	for (int i = 1; i <= n; i++) FillTimes (i);
	ResetVisited ();
	for (int i = 1; i <= n; i++) if(!nodes[i].visited) 
	{
		islands++;
		FillIslands(i);
	}
}

void Out()
{
	cout << islands << endl;
	for (int i = 1; i <= n; i++)
		cout << nodes[i].island_id << " ";
}

int main()
{
	In();
	Solve();
	Out();
}