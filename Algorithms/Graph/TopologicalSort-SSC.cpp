#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	vector <int> edges;
	vector <int> incoming_edges;
	bool visited = false;
	int topological_sort_index;
	int strongly_connected_component_id;
};

int n, m;
vector <Node> nodes;
vector <int> topological_sort;

int num_strongly_connected;

void In()
{
	cin >> n >> m;
	nodes.resize(n + 1);
	topological_sort.resize(n);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		nodes [u].edges.push_back(v);
		nodes [v].incoming_edges.push_back(u);
	}
}

void ResetVisited ()
{
	for (Node& node: nodes) node.visited = false;
}

void FillTopologicalSort (int id, int& topological_sort_index)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;

	for (int child: node.edges)
		FillTopologicalSort (child, topological_sort_index);
	node.topological_sort_index = topological_sort_index;
	topological_sort[topological_sort_index--] = id;
}

// Try going out from all vertices and using DFS that assigns topological sort id postorder.
// If we see already solved subtree, all indices are bigger there so it does not conflict.
void TopologicalSort ()
{
	int topological_sort_index = n - 1;
	for (int i = 1; i <= n; i++) 
		FillTopologicalSort (i, topological_sort_index);
}

void FillStronglyConnectedComponent (int id)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;
	node.strongly_connected_component_id = num_strongly_connected;

	for (int child: node.incoming_edges)
		FillStronglyConnectedComponent (child);
}

// Iterate nodes in topological sorted order. We know that it starts with node in 'top' SSC.
// We iterate on incoming edges not to go down to the below node. 
// But we still visit all nodes in SSC becase we can form cycles between any two and the cycle is just reversed.
void FillStronglyConnectedComponents ()
{
	for (int i = 0; i < n; i++)
	{
		int next = topological_sort[i];
		if (!nodes[next].visited)
		{
			num_strongly_connected++;
			FillStronglyConnectedComponent(next);
		}
	} 
}

void Solve()
{
	TopologicalSort ();
	ResetVisited ();
	FillStronglyConnectedComponents ();
}

void Out()
{
	cout << num_strongly_connected << std::endl;
	for (int i = 1; i <= n; i++) cout << nodes[i].strongly_connected_component_id << " ";
}

int main()
{
	In();
	Solve();
	Out();
}