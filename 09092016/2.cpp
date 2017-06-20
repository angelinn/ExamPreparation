#include <cstdio>
int level = 0;

struct Node
{
    int data;

    size_t count;
    Node* children;
    Node* next;

    Node(int data = 0) : data(data), count(0), children(nullptr), next(nullptr)
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

void buildTree(Node* root, int K, int* A, size_t n)
{
    bool newLevel = false;
    for (size_t i = 1; i < n; ++i)
    {
        if (!isMember(root, A[i]))
        {
            if (root->count < K)
            {
                Node* children = root->children;

                if (!root->children)
                {
                    if (newLevel)
                    { 
                        printf("+1 level - [%d]\n", ++level);
                        newLevel = false;
                    }
                    root->children = new Node(A[i]);
                }
                else
                {
                    while (children->next)
                        children = children->next;

                    children->next = new Node(A[i]);
                }
                ++root->count;
            }
            else
            {
                 if (root->next)
                    root = root->next;
                else
                {
                    printf("+1 level - [%d]\n", ++level);
                    newLevel = true;
                    root = root->children;
                }
                --i;
            }
        }
    }
}

Node* buildTree(int K, int* A, size_t n)
{
    if (n == 0)
        return nullptr;
    
    printf("+1 level - [%d]\n", ++level);
    Node* root = new Node();
    root->data = A[0];

    buildTree(root, K, A, n);
    return root;
}

void printTree(Node* root)
{
    printf("%d - [", root->data);
    while (root->children)
    {
        printTree(root->children);
        root->children = root->children->next;
    }
    printf("] ");
}