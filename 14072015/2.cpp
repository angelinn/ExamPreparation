#include <cstdio>

struct Node
{
    int data;
    Node** children;
    size_t count;
};

void deleteNode(Node*& root)
{
    for (int i = 0; i < root->count; ++i)
        deleteNode(root->children[i]);

    delete root;
}

bool member(Node* root, int x)
{
    if (root->data == x)
        return true;

    for (int i = 0; i < root->count; ++i)
    {
        if (member(root->children[i], x))
            return true;
    }

    return false;
}

void filterOdd(Node* root)
{
	for (int i = 0; i < root->count; ++i)
	{
		if (root->children[i]->data % 2)
		{
			deleteNode(root->children[i]);

			for (int j = i; j < root->count; ++j)
				root->children[j] = root->children[j + 1];

			--root->count;
		}
		else
			filterOdd(root->children[i]);
	}
}
