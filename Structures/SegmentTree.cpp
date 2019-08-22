#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree
{
	int segtree_size;
	vector <T> segtree;
	T identity;

	// Returns value we ar counting here.
	T (*UpdateFn) (T, T);

	// Update segtree size. Take size bigger than segtree size and multiply it by 2.
	void Init (int main_size, T (*UpdateFunction) (T, T), T fun_identity)
	{
		segtree_size = 1;
		while (segtree_size < main_size) segtree_size *= 2;
		segtree_size *= 2;
		
		segtree.resize(segtree_size);
		UpdateFn = UpdateFunction;
		this->identity = fun_identity;
	}

	// All parents get updated accordingly to base. O(N)	
	void UpdateAllParents ()
	{
		for (int i = segtree_size / 2 - 1; i > 0; i--) 
			segtree[i] = UpdateFn (segtree[i * 2], segtree[i * 2 + 1]);
	}

	// Change value at position index without updating parents
	void ChangeValue (int index, T value)
	{
		segtree[index + segtree_size / 2] = value;
	}

	// Get value at position without updating parents
	T GetValue (int index)
	{
		return segtree[index + segtree_size / 2];
	}

	// Update the value, then go up parents updating them too
	void Update (int pos, T value)
	{
		for (segtree[pos += segtree_size / 2] = value; pos > 1; pos /= 2)
			segtree[pos / 2] = UpdateFn (segtree[pos], segtree[pos ^ 1]);
	}

	// Returns querry on interval [start, finish]. We go from bottom to top and check, if parent is not included, count value and change to next parent
	T Query (int start, int finish)
	{
		T ans = this->identity;
		for (start += segtree_size / 2, finish += segtree_size / 2; start < finish; start /= 2, finish /= 2) 
		{
			if (start % 2 == 1) ans = UpdateFn (ans, segtree[start++]);
			if (finish % 2 == 0) ans = UpdateFn (ans, segtree[finish--]);
		}
		return (start == finish) ? UpdateFn (ans, segtree[start]) : ans;
	}

	void Destroy ()
	{
		segtree.clear();
	}
};

