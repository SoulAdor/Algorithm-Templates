#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Heap
{
	std::vector <T> heap;

	void FixUp (int index)
	{
		if (index == 1) return;
		int parent_index = index/2;
		if (heap[parent_index] > heap[index])
		{
			std::swap(heap[parent_index], heap[index]);
			FixUp (parent_index);
		}
	}

	void FixDown (int index)
	{
		int first_child_index = 2*index, second_child_index = 2*index+1;
		if (first_child_index >= heap.size()) return;
		if (second_child_index < heap.size() && heap[first_child_index] > heap[second_child_index]) 
			std::swap(first_child_index, second_child_index);
		if (heap[index] > heap[first_child_index]) 
		{
			std::swap(heap[index], heap[first_child_index]);
			FixDown(first_child_index);
		}
	}

	public:
	Heap()
	{
		heap.resize(1);
	}

	size_t Size()
	{
		return heap.size() - 1;
	}

	bool Empty()
	{
		return Size() == 0;
	}

	void Push (T value)
	{
		int index = heap.size();
		heap.push_back(value);
		FixUp (index);
	}

	T Top ()
	{
		return heap[1];
	}

	T Pop ()
	{
		T value = Top ();
		std::swap(heap[1], heap.back());
		heap.pop_back();
		FixDown(1);
		return value;
	}
};

int main()
{
   Heap <int> pqueue;
   pqueue.Push(3);
   pqueue.Push(1);
   pqueue.Push(2);
   cout << pqueue.Size() << std::endl;
   cout << pqueue.Pop() << std::endl;
   cout << pqueue.Size() << std::endl;
   cout << pqueue.Pop() << std::endl;
}