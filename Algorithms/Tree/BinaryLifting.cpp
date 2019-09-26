#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct Node
{
	int project, depth, in_time, out_time;
	vector <int> parents;
	vector <int> edges;
};

int n;
vector <Node> nodes;
vector <vector <int> > projects;
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

int counter = 0;
void FillInfo (int id, int parent = 0, int depth = 0)
{
	Node& node = nodes[id];
	node.in_time = counter++;
	node.depth = depth;
	node.parents.push_back(parent);

	for (int size = 2, i = 0; size <= node.depth; size *= 2, i++) 
		node.parents.push_back(nodes[node.parents.back()].parents[i]);
	for (int child: node.edges) 
		if (child != parent) 
			FillInfo (child, id, depth + 1);

	node.out_time = counter++;
}

void StripLowestBit (int& number)
{
	number = number & (number - 1);
}

int FindParent (int node, int parent)
{
	for (; parent; StripLowestBit (parent)) 
		node = nodes[node].parents[__builtin_ctz(parent)];
	return node;
}

bool Parent (int parent, int child)
{
	return nodes[parent].in_time <= nodes[child].in_time && nodes[child].out_time <= nodes[parent].out_time;
}

int LCA (int u, int v)
{
	if (Parent(u,v)) return u;
	if (Parent(v,u)) return v;
	for (int jump = nodes[u].parents.size() - 1; jump >= 0; jump--)
		if (jump < nodes[u].parents.size() && !Parent(nodes[u].parents[jump], v)) 
			u = nodes[u].parents[jump];
	return nodes[u].parents[0];
}

void Solve()
{
	FillInfo (1);
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
