#include <iostream>
using namespace std;
// code to add nodes at left or right of the tree
struct tree
{
    int data;
    struct tree *right, *left;
};

tree *createElement()
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void seeTree(tree *rt)
{
    if (rt != NULL)
    {

        tree *tmp = rt->left;
        while (tmp != NULL)
        {
            cout << "\nleft: " << tmp->data;
            tmp = tmp->left;
            seeTree(tmp);
        }
        tmp = rt->right;
        while (tmp != NULL)
        {
            cout << "\nright: " << tmp->data;
            tmp = tmp->right;
            seeTree(tmp);
        }
    }
}
void addNode(tree *tmp)

{
    tree *rt = tmp;
    int chc, elem;
    cout << "\n---------------------------";
    cout << "\nLeft or Right?(0/1) : ";
    cin >> chc;
    cout << "\n---------------------------";
    cout << "\nEnter element: ";
    cin >> elem;
    tree *nwnod = createElement();
    nwnod->data = elem;
    if (chc == 0)
    {

        while (rt->left != NULL)
        {
            rt = rt->left;
        }
        rt->left = nwnod;
    }
    else
    {
        while (rt->right != NULL)
        {
            rt = rt->right;
        }
        rt->right = nwnod;
    }
    cout << "\n---------------------------";
    cout << "\nElement: " << elem << "added";
    cout << "\n---------------------------" << rt;
}

int main()
{
    int choice = 1, dat, side;
    tree *root = createElement();
    root->data = 6969;
    while (choice != 0)
    {
        cout << "\n---------------------------" << root;
        cout << "\n1.seeTree\n2. addElement";
        cout << "\nYour choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n---------------------------";
            cout << "\n     Tree is elements are: ";
            seeTree(root);
            cout << "\n---------------------------";
            break;
        case 2:
            addNode(root);
            break;
        case 3:
            // addLeft();
            break;
        case 0:
            cout << "\n---------------------------";
            cout << "\n     Bye";
            cout << "\n---------------------------\n";
            break;

        default:
            cout << "\n---------------------------";
            cout << "\n     Wrong Choice";
            cout << "\n---------------------------";
        }
    }
}
