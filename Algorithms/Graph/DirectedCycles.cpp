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
bool answer;

void In()
{
	cin >> n >> m;
	nodes.resize (n + 1);
	int start, finish;
	for (int i = 0; i < m; i++)
	{ 
		cin >> start >> finish;
		nodes [start].edges.push_back (finish);
		nodes [finish].edges.push_back (start);
	}
}

// Keeping track of stack tree as we go. To print whole cycle, might use vector instead of set.
set <int> stk;
bool FindCycles (int start)
{
	if (nodes[start].visited) return false;
	nodes[start].visited = true;
	stk.insert (start);
	for (int end : nodes[start].edges)
	{
		if (stk.count (end)) return true;
		else if (FindCycles (end)) return true;
	}
	stk.erase (start);
	return false;
}

void Solve()
{
	answer = FindCycles (1);
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
