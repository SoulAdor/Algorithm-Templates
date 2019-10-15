#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class MinQueue
{
	struct Info
	{
		int value, minimum;
	};

	stack <int> in;
	stack <Info> out;
	int min_in = INT_MAX;

	void MoveInToOut ()
	{
		min_in = INT_MAX;
		Info next;
		while(!in.empty())
		{
			next.value = in.top(); in.pop();
			next.minimum = min (next.value, out.empty() ? INT_MAX : out.top().minimum);
			out.push(next);
		}
	}

	public:

	void Push (int number)
	{
		in.push(number);
		min_in = min (min_in, number);
	}

	int Pop ()
	{
		if (out.empty()) MoveInToOut ();
		int value = out.top().value; out.pop();
		return value;
	}
	
	int Back ()
	{
		if (out.empty()) MoveInToOut ();
		return out.top().value;
	}

	int Size ()
	{
		return in.size() + out.size();
	}

	bool Empty ()
	{
		return Size() == 0;
	}

	int GetMinimum ()
	{
		return min (min_in, out.empty() ? INT_MAX : out.top().minimum);
	}
};


int main()
{__
	MinQueue q;
	q.Push (3);
	q.Push (2);
	q.Push (4);
	
	cout << q.Size() << endl;
	cout << q.GetMinimum() << endl;
	cout << q.Pop() << endl;
}