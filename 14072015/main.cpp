#include "1.cpp"
#include "2.cpp"

int main()
{
    float** img = new float*[2];
    img[0] = new float[3] {1, 2, 3};
    img[1] = new float[3] {4.5, 6.5, 7.5};

    subsample(2, 3, img);

    Node* root = new Node { 8, new Node*[2], 2 };
    root->children[0] = new Node { 2, nullptr, 0 };
    root->children[1] = new Node { 3, new Node*[3], 3 };
    
    root->children[1]->children[0] = new Node { 4, nullptr, 0 };
    root->children[1]->children[1] = new Node { 5, nullptr, 0 };
    root->children[1]->children[2] = new Node { 6, nullptr, 0 };

    printf("Is 3 member of 8: %d\n", member(root, 3));
    printf("Is 4 member of 3: %d\n", member(root->children[1], 4));
    printf("Is 2 member of 3: %d\n", member(root->children[1], 2));

    filterOdd(root);

    deleteNode(root);
}
