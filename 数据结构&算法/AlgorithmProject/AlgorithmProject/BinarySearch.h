#pragma once

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <queue>

using namespace std;

	
// Binary search
// Only works for sorted array
// If finds target, return index
template<typename T>
int binarySearch(T arr[], int n, T target)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}

		if (target < arr[mid])
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	return -1;
}

template<typename Key, typename Value>
class BST {
public:
	BST()
	{
		root = NULL;
		count = 0;
	}

	~BST()
	{
		destroy(root);
	}

	int size() { return count; }
	bool isEmpty() { return count == 0; }

	// Insert new node
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}

	// Check if BST constains key
	bool contains(Key key)
	{
		return contains(root, key);
	}

	Value* search(Key key)
	{
		return search(root, key);
	}

	// Pre-order traversal BST
	void preOrder(Node* node)
	{
		if (node != NULL)
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right)
		}
	
	}

	// In-order traveral BST
	void inOrder(Node* node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// Post-order traversal BST
	void postOrder(Node* node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// BFS
	void levelOrder()
	{
		queue<Node*> queue;
		if (root != NULL)
		{
			queue.push(root);
		}

		while (!queue.empty())
		{
			Node* node = queue.front();
			queue.pop();

			if (node -> left != NULL)
			{
				queue.push(node->left);
			}
			
			if (node -> right != NULL)
			{
				queue.push(node->right);
			}
		}
	}

private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		Node(Node* node)
		{
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node* root;
	int count;

	// Recursively find a place to create new node
	Node* insert(Node* node, Key key, Value value)
	{
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}

		if (key == node->key)
		{
			node->value = value;
		}
		else if (key < ndoe->key)
		{
			node->left = insert(node->left, key, value);
		}
		else
		{
			node->right = insert(node->right, key, value);
		}

		return node;
	}

	bool contains(Node* node, Key key) 
	{
		if (node == NULL)
		{
			return false;
		}

		if (key == node -> key)
		{
			return true;
		}
		else if (key < node -> key)
		{
			return contains(node -> left, key);
		}
		else
		{
			return contains(node -> right, key);
		}
	}

	Value* search(Node* node, Key key)
	{
		if (node == NULL)
		{
			return NULL;
		}

		if (key == node -> key)
		{
			return &(node->value);
		}
		else if (key < node->key)
		{
			return search(node->left, key);
		}
		else
		{
			return search(node->right, key);
		}
	}

	void destroy(Node* node)
	{
		if (node != NULL)
		{
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}

	Node* findMin(Node* node)
	{
		if (node -> left == NULL)
		{
			return node;
		}

		return findMin(node->left);
	}

	Node* deleteMin(Node* node)
	{
		if (node -> left == NULL)
		{
			Node* rightNode = node->right;	// No matter NULL or not
			delete node;
			count--;
			return node->right;
		}
		
		node->left = deleteMin(node->left);
		return node;
	}


	Node* remove(Node* node, Key key)
	{
		if (node == NULL)
		{
			return NULL;
		}

		if (key < node -> key)
		{
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key)
		{
			node->left = remove(node->right, key);
			return node;
		}
		else
		{
			// key == node->key
			if (node -> left == NULL)
			{
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}

			if (node->right == NULL)
			{
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			// node->left != NULL && node->right != NULL
			Node* successor = new Node(findMin(node->right));
			count++;

			successor->left = node->left;	// 左侧子节点不变
			successor->right = deleteMin(node->right);	// 右侧子节点变成删除右侧最小节点的子节点

			delete node;
			count--;

			return successor;
		}
	}
	
};

#endif // !BINARY_SEARCH_H