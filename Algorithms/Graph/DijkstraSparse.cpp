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
	long long distance;
};

int n, m;
vector <Node> nodes;
vector <long long> distances;

void In()
{
	cin >> n >> m;
	nodes.resize(n + 1);

	int start, end;
	Edge next;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> next.weight;
		next.end = end;
		nodes[start].edges.push_back(next);
		next.end = start;
		nodes[end].edges.push_back(next);
	}
}

struct NodeDistance
{
	int id;
	long long distance;
	NodeDistance(int id, long long distance): id(id), distance(distance) {}
};

struct CompareDistances{
   bool operator()(NodeDistance const& a, NodeDistance const& b)
   {
      return a.distance > b.distance;
   }
};

priority_queue <NodeDistance, vector<NodeDistance>, CompareDistances> pq;

void UpdateDistances (int id, int distance, vector <long long>& distances, vector <bool>& found)
{
	distances[id] = distance;
	found[id] = true;
	for (Edge edge: nodes[id].edges) 
		if (!found[edge.end] && distance + edge.weight < distances[edge.end])
			pq.push(NodeDistance(edge.end, distance + edge.weight));
}

void Dijkstra (int start, vector <long long>& distances)
{
	vector <bool> found;
	distances.resize(n + 1, LLONG_MAX);
	found.resize(n + 1, false);

	NodeDistance current(start, 0);
	pq.push (current);
	while (!pq.empty())
	{
		current = pq.top(); pq.pop();
		if (!found[current.id]) 
			UpdateDistances (current.id, current.distance, distances, found);
	}
}

void Solve()
{
	Dijkstra (1, distances);
}

void Out()
{
	for (int i = 1; i <= n; i++) cout << distances[i] << " ";
}

int main()
{
	In();
	Solve();
	Out();
}