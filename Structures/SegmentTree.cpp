#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct segtree
{
	int main_size, rounded_size;
	vector <T> segtree;
	T identity;
	T (*UpdateFn) (T, T);

	public:
	// Update segtree size. Take size bigger than segtree size and multiply it by 2.
	void Init (int main_size, T (*UpdateFunction) (T, T), T fun_identity)
	{
		this->main_size = main_size;
		rounded_size = 1;
		while (rounded_size < main_size) rounded_size *= 2;
		
		segtree.resize(2 * rounded_size);
		UpdateFn = UpdateFunction;
		this->identity = fun_identity;
	}

 	T 	operator []	(int i) const 	{return segtree[i + rounded_size];}
   T&	operator []	(int i) 			{return segtree[i + rounded_size];}

	int size ()
	{
		return main_size;
	}

	// All parents get updated accordingly to base. O (N)	
	void UpdateAllParents ()
	{
		for (int i = rounded_size - 1; i > 0; i--) 
			segtree[i] = UpdateFn (segtree[i * 2], segtree[i * 2 + 1]);
	}

	// Update the value, then go up parents updating them too
	void Update (int pos, T value)
	{
		for (segtree[pos += rounded_size] = value; pos > 1; pos /= 2)
			segtree[pos / 2] = UpdateFn (segtree[pos], segtree[pos ^ 1]);
	}

	// Returns querry on interval [start, finish]. We go from bottom to top and check, if parent is not included, count value and change to next parent
	T Query (int start, int finish)
	{
		T ans = identity;
		for (start += rounded_size, finish += rounded_size; start < finish; start /= 2, finish /= 2) 
		{
			if (start % 2 == 1) ans = UpdateFn (ans, segtree[start++]);
			if (finish % 2 == 0) ans = UpdateFn (ans, segtree[finish--]);
		}
		return (start == finish) ? UpdateFn (ans, segtree[start]) : ans;
	}

	void Clear ()
	{
		segtree.clear();
	}
};

int main ()
{
	segtree <int> tree;
	tree.Init (20, [] (int a, int b) -> int {return a + b;}, 0);
	tree[0] = 2;
	tree[3] = 3;
	cout << tree [3] << endl;
	tree.UpdateAllParents();
	cout << tree.Query (0, 3);
}