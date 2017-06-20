#include "1.cpp"
#include "2.cpp"

int main()
{
    sameSymbols("this is just a simple example");

    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Node* tree = buildTree(3, A, 10);
    printTree(tree);
}