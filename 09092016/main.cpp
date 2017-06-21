#include "1.cpp"
// #include "2.cpp"
#include "2_smart.cpp"


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

int main()
{
    sameSymbols("this is just a simple example");

    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Node* tree = buildTree(3, A, 10);
    printTree(tree);
}
