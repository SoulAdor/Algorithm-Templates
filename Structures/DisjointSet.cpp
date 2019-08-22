#include <bits/stdc++.h>
using namespace std;

// Parent and depth if Set

class DisjointSet
{
	struct DSInfo
	{
		int parent, depth;
	};

	vector < DSInfo > DSinfos;

	void Merge (int first_set, int second_set)
	{
		if 		(DSinfos[first_set].depth > DSinfos[second_set].depth)	DSinfos[second_set].parent = first_set;
		else if 	(DSinfos[first_set].depth < DSinfos[second_set].depth)	DSinfos[first_set].parent = second_set;
		else
		{
			DSinfos[second_set].parent = first_set;
			DSinfos[first_set].depth++;
		}
	}

	int GetSet (int node)
	{
		if (DSinfos[node].parent == node) return node;
		return DSinfos[node].parent = GetSet (DSinfos[node].parent);
	}

	public:

	// Initializes disjoint set to handle values up to size inclusive
	void Init (int size)
	{
		DSinfos.resize (size + 1);
		for (int i = 0; i <= size; i++)
		{
			DSinfos[i].parent = i;
			DSinfos[i].depth = 1;
		}
	}

	// Joins two elements if they are not already joined
	void Join (int first, int second)
	{
		if (GetSet (first) != GetSet (second)) Merge (GetSet (first), GetSet (second)); 
	}

	// Returns true if two elements belong together
	bool Same (int first, int second)
	{
		return GetSet (first) == GetSet (second);
	}
};

int main()
{
	DisjointSet ds;
	ds.Init(5);
	cout << ds.Same(1,2) << endl;
	cout << ds.Same(1,1) << endl;
	ds.Join(1,2);
	cout << ds.Same(1,2) << endl;
	cout << ds.Same(1,1) << endl;
}