#include <cstdio>
#include <cctype>
#include <cstdlib>

struct Node
{
	int data;

	Node* next;
	Node* children;
};

void buildNode(FILE* fileHandle, Node*& root)
{
	char c = 0;

	while ((c = fgetc(fileHandle)) != EOF)
	{
		if (c == '(')
		{
			char number[10];
			size_t currentSize = 0;

			while (!isdigit((c = fgetc(fileHandle))))
			{
				if (c == ')')
					return;
			}

			number[currentSize++] = c;

			while (isdigit((c = fgetc(fileHandle))))
			{
				number[currentSize++] = c;
			}
			
			number[currentSize] = '\0';

			Node* current = new Node{ atoi(number), nullptr, nullptr };

			if (!root)
				root = current;
			else if (!root->children)
				root->children = current;
			else
			{
				Node* children = root->children;
				while (root->children->next)
					root->children = root->children->next;

				root->children->next = current;
				root->children = children;
			}

			buildNode(fileHandle, current);
		}
	}
}

Node* buildTree(const char* filePath)
{
	FILE* pFile = fopen(filePath, "r");
	if (!pFile)
	{
		printf("Could not open file.\n");
		return nullptr;
	}

	Node* root = nullptr;
	buildNode(pFile, root);
	
	fclose(pFile);
	return root;
}

void printTree(Node* root)
{
	if (!root)
		return;

	printf("[%d] - Children: [", root->data);
	Node* children = root->children;
	while (children)
	{
		printTree(children);
		children = children->next;
	}

	printf("]");
}