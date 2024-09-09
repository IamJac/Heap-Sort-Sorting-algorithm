#include <iostream>
using namespace std;
class Minheap
{
public:
	int* heap_array;
	int heap_size;
	int capacity;
	Minheap(int size)
	{
		heap_array = new int[size];
		heap_size = 0;
		capacity = size;
	}
	void get_unsortedarray()
	{
		cout << "Input " << capacity << " elements into the heap_array " << endl;
		for (int i = 0; i < capacity; i++)
		{
			cin >> heap_array[i];
			heap_size++;
			if (i == capacity - 1)
			{
				cout << "The heap array is full" << endl;
			}
		}
	}
	void print_unsortedarray()
	{
		cout << "Unsorted array " << endl;
		for (int i = 0; i < capacity; i++)
		{
			cout << heap_array[i] << " ";
		}
		cout << endl;
	}
	int left(int i)
	{
		return (i * 2) + 1;
	}
	int right(int i)
	{
		return (i * 2) + 2;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	void min_heapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap_size && heap_array[l] < heap_array[i])
		{
			smallest = l;
		}
		if (r < heap_size && heap_array[r] < heap_array[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			swap(heap_array[smallest], heap_array[i]);
			min_heapify(smallest);
		}
	}
	int extract_min()
	{
		if (heap_size == 0)
		{
			return -12;
		}
		else if (heap_size == 1)
		{
			heap_size--;
			return heap_array[0];
		}
		else
		{
			int root = heap_array[0];
			heap_array[0] = heap_array[heap_size - 1];
			heap_size--;
			min_heapify(0);
			return root;
		}
	}
	void heap_sort()
	{
		cout << "Sorted array:" << endl;
		int* temp_array = new int[capacity];
		for (int i = 0; i < capacity; i++)
		{
			temp_array[i] = extract_min();
			cout << temp_array[i] << " ";
		}
	}
};
int main()
{
	int size = 0;
	cout << "Input size of the array" << endl;
	cin >> size;
	Minheap m(size);
	m.get_unsortedarray();
	m.print_unsortedarray();
	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		m.min_heapify(i);
	}
	m.heap_sort();
	return 0;
}
