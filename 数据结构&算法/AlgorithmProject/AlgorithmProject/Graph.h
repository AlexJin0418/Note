#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

namespace graph {

	class DenseGraph {
	private:
		int n, m;		// n is vertex number; m is edge number
		bool directed;
		vector<vector<bool>> g;


	public:
		DenseGraph(int n, bool directed)
		{
			this->n = n;
			this->m = 0;
			this->directed = directed;

			for (int i = 0; i < n; i++)
			{
				g.push_back(vector<bool>(n, false));		// Graph
			}
		}

		~DenseGraph()
		{

		}

		int V() { return n; }
		int E() { return m; }

		// Add an edge between v and w
		void addEdge(int v, int w)
		{
			if (hasEdge(v, w))
			{
				return;
			}

			g[v][w] = true;
			if (!directed)
			{
				g[w][v] = true;
			}
			
		}

		bool hasEdge(int v, int w)
		{
			return g[v][w];
		}
	};

	class SpareGraph {
	private:
		int n, m;
		bool directed;
		vector<vector<int>> g;

	public:
		SpareGraph(int n, bool directed) 
		{
			this->n = n;
			this->m = 0;
			this->directed = directed;

			for (int i = 0; i < n; i++)
			{
				g.push_back(vector<int>());		// Empty vector
			}
		}

		~SpareGraph() 
		{
		
		}

		int V() { return n; }
		int E() { return m; }

		void addEdge(int v, int w)
		{
			g[v].push_back(w);
			if (!directed && v != w)
			{
				g[w].push_back(v);
			}
			m++;
		}

		bool hasEdge(int v, int w)
		{
			for (int i = 0; i < g[v].size(); i++)
			{
				if (g[v][i] == w)
				{
					return true;
				}
			}
			return false;
		}
	};

	class A {

		void Foo();
	};

	void A::Foo()
	{
		cout << "Foo" << endl;
	}
}


#endif // !GRAPH_H
