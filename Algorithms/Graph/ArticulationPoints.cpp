#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Edge
{
	int id, end;
};

struct Node
{
	vector <Edge> edges;
	bool visited = false;
	bool articulation_point = false;
	int children = 0;
	int depth;
	int low_depth;
};

int n, m;
vector <Node> nodes;
stack <int> edge_ids;
vector <bool> seen_edges;

int num_components;
vector <int> answer;

void In()
{
	cin >> n >> m;
	nodes.resize(n + 1);
	answer.resize(m);
	seen_edges.resize(m);

	int u, v;
	Edge next;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		next.id = i;
		next.end = v;
		nodes[u].edges.push_back(next);
		next.end = u;
		nodes[v].edges.push_back(next);
	}
}

void FillBiconnectedComponent (int last = -1)
{
	if (edge_ids.empty()) return;
	num_components++;
	while (!edge_ids.empty())
	{
		int id = edge_ids.top(); edge_ids.pop();
		answer[id] = num_components;
		if (id == last) break;
	}
}

// low_depth stores lowest depth we can touch by going up the tree from subtree
// If some child cannot go higher than node, then node is articulation point
void GetBiconnectedComponents (int id, int parent = -1, int depth = 0)
{
	Node& node = nodes[id];
	if (node.visited) return;
	node.visited = true;

	node.low_depth = node.depth = depth;
	for (Edge next: node.edges)
	{
		int edge_id = next.id;
		int child = next.end;
		// Add the edge to the stack if not seen so far not to push to the stact several times
		if (!seen_edges[edge_id])
		{
			edge_ids.push(next.id);
			seen_edges[edge_id] = true;
		}

		if (nodes[child].visited) node.low_depth = min (node.low_depth, nodes[child].depth);
		else
		{
			node.children++;
			GetBiconnectedComponents (child, id, depth + 1);
			node.low_depth = min (node.low_depth, nodes[child].low_depth);
			if (parent == -1 ? node.children > 1 : nodes[child].low_depth == node.depth)
			{
				node.articulation_point = true;
				FillBiconnectedComponent(next.id);
			}
		}
	}
}

void Solve()
{
	for (int i = 1; i <= n; i++)
	{
		GetBiconnectedComponents (i);
		FillBiconnectedComponent ();
	}
}

void Out()
{
	cout << num_components << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}

int main()
{
	In();
	Solve();
	Out();
}