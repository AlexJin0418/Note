#pragma once
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

template<typename Item>
class MaxHeap
{
public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}

	~MaxHeap() 
	{
		delete[] data;
	}

	int size() { return count; }

	bool empty() { return count == 0; }

	void insert(Item item)
	{
		if (count + 1 > capacity)
		{
			return;
		}
		// 元素从1开始
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

	// 返回第一个元素
	Item pop()
	{
		if (!empty())
		{
			Item res = data[1];
			swap(data[1], data[count]);
			count--;

			shiftDown();

			return res;
		}

		return NULL;
	}

	void print()
	{
		cout << "maxheap: [ ";
		int i = 1;
		for (; i < count; i++)
		{
			cout << data[i] << ", ";
		}

		cout << data[i] << " ]" << endl;
	}

	


private:
	Item* data;
	int count;
	int capacity;

	void shiftUp(int k)
	{
		while (k > 1 && data[k/2] < data[k])
		{
			swap(data[k/2], data[k]);
			k /= 2;
		}
	}

	void shiftDown()
	{
		int i = 1;
		while (i <= count)
		{
			// check left and right
			int l = i * 2 <= count ? i * 2 : i;
			int r = i * 2 + 1 <= count ? i * 2 + 1 : i;

			int max = data[l] > data[r] ? l : r;
			if (data[max] > data[i])
			{
				swap(data[max], data[i]);
				i = max;
			}
			else
			{
				break;
			}
		}
	}
};

#endif // !MAX_HEAP_H
