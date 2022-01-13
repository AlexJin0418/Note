#pragma once

#ifndef UNION_FIND_H
#define UNION_FIND_H

class UnionFind
{
private:
	int* id;
	int count;

public:
	UnionFind(int n)
	{
		count = n;
		id = new int[n];
		for (int i = 0; i < n; i++)
		{
			id[i] = i;
		}
	}

	~UnionFind()
	{
		delete[] id;
	}

	int find(int p)
	{
		return id[p];
	}

	bool isConnected(int p, int q)
	{
		return find(p) == find(q);
	}

	// Union two elements
	// O(n)
	void unionElements(int p, int q)
	{
		int pId = find(p);
		int qId = find(q);

		if (pId == qId)
		{
			return;
		}
		
		for (int i = 0; i < count; i++)
		{
			if (id[i] == pId)
			{
				id[i] == qId;
			}
		}
	}
};


class UF2
{
private:
	int* parent;
	int count;

public:
	UF2(int count)
	{
		parent = new int[count];
		this->count = count;
		for (int i = 0; i < count; i++)
		{
			parent[i] = i;
		}
	}

	~UF2()
	{
		delete[] parent;
	}

	// Find root element of p
	int find(int p)
	{
		while (p != parent[p])
		{
			p = parent[p];
		}
		return p;
	}

	bool isConnected(int p, int q)
	{
		return find(p) == find(q);
	}

	void unionElements(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);

		if (pRoot == qRoot)
		{
			return;
		}

		parent[pRoot] = qRoot;	// Set pRoot's parent as qRoot
	}

};
#endif // !UNION_FIND_H
