#include <iostream>
using namespace std;
//acts like complete tree but not
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

void comTree(tree *rt, tree *nwnod)
{

    if (rt->left == NULL)
    {
        rt->left = nwnod;
        return;
    }
    if (rt->right == NULL)
    {
        rt->right = nwnod;
        return;
    }
    if (rt->left != NULL && rt->right != NULL)
    {
        comTree(rt->right, nwnod);
        return;
    }
    else
    {
        comTree(rt->left, nwnod);
        return;
    }
}

void printComp(tree *rt)
{
    if (rt == NULL)
    {
        return;
    }
    else
    {

        if (rt->left != NULL)
            cout << " -> " << rt->left->data;
        if (rt->right != NULL)
            cout << " -> " << rt->right->data;
    }
    printComp(rt->left);
    printComp(rt->right);
}
int main()
{

    tree *rt = createNode(0); // root node

    comTree(rt, createNode(100));
    comTree(rt, createNode(150));
    comTree(rt, createNode(200));
    comTree(rt, createNode(250));
    comTree(rt, createNode(300));
    comTree(rt, createNode(350));
    comTree(rt, createNode(400));
    printComp(rt);

    return 0;
}