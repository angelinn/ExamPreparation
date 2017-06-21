#include <cstring>
#include <cstdio>

struct Node
{
	int data;
	Node* children;
	Node* next;

	Node(int data = 0) : data(data), children(nullptr), next(nullptr)
	{   }
};

bool isMember(Node* root, int data)
{
	if (root->data == data)
		return true;

	Node* children = root->children;
	while (children)
	{
		if (isMember(children, data))
			return true;

		children = children->next;
	}

	return false;
}

Node* buildTree(int K, int* A, size_t n)
{
	if (n == 0)
		return nullptr;

	Node* root = new Node(A[0]);
	Node* iterator = root;

	for (size_t i = 1; i < n;)
	{
		iterator->children = new Node(A[i++]);
		Node* children = iterator->children;

		for (size_t j = 1; j < K && j < n; ++j, ++i)
		{
			if (!isMember(iterator, A[i]))
			{
				children->next = new Node(A[i]);
				children = children->next;
			}
		}

		iterator = (iterator->next) ? (iterator->next) : iterator->children;
	}

	return root;
}
