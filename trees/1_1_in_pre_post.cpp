#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
};

tree *createNode(int dat)
{
    tree *nwNode = (tree *)malloc(sizeof(tree));
    nwNode->left = NULL;
    nwNode->right = NULL;
    nwNode->data = dat;
    return nwNode;
}

void preOrder(tree *rt)
{
    if (rt == NULL)
    {
        return;
    }
    cout << rt->data << "->";
    preOrder(rt->left);
    preOrder(rt->right);
}

void inOrder(tree *rt)
{
    if (rt == NULL)
        return;
    inOrder(rt->left);
    cout << rt->data << "->";
    inOrder(rt->right);
}

void postOrder(tree *rt)
{
    if (rt == NULL)
        return;
    postOrder(rt->left);
    postOrder(rt->right);
    cout << rt->data << "->";
}

int main()
{
    int choice;
    tree *root = createNode(10);
    root->left = createNode(9);
    root->right = createNode(15);
    root->left->left = createNode(7);
    while (choice != 9)
    {
        cout << "\n------------------------------------";
        cout << "\n.1Preorder traversal\n2.Inorder traversal\n3.Postorder traversal.";
        cout<<"\nEnter option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            preOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 9:
            cout << "\n------------------------------------";
            cout << "\n      Bye";
            cout << "\n------------------------------------\n";
            break;
        default:
            cout << "\n------------------------------------";
            cout << "\n      Wrong choice";
            cout << "\n------------------------------------";
        }
    }
}