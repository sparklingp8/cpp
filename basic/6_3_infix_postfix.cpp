#include <iostream>
using namespace std;
struct node
{
    char data;
    node *next;
};

node *createNode(char chr)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = chr;
    newNode->next = NULL;
    return newNode;
}

void Peek(node *h)
{
    if (h == NULL)
    {
        cout << "\n-----------------------------";
        cout << "\n        Stack is Empty";
        cout << "\n-----------------------------";
    }
    else
    {
        cout << "\n-----------------------------";
        cout << "\nStack Top Element is: " << h->data;
        cout << "\n-----------------------------";
    }
}

node *Push(node *h, char c)
{

    if (h == NULL)
    {
        h = createNode(c);
        return h;
    }
    else
    {
        node *tmp;
        tmp = createNode(c);
        tmp->next = h;
        h = tmp;
        return h;
    }
}

node *Pop(node *h)
{
    if (h == NULL)
    {
        cout << "\n-----------------------------";
        cout << "\n        Stack is Empty";
        cout << "\n-----------------------------";
        return NULL;
    }
    else if (h->next == NULL)
    {
        cout << "\n-----------------------------";
        cout << "\nPoped Last element: " << h->data;
        cout << "\n-----------------------------";
        h = NULL;
        return h;
    }
    else
    {
        cout << "\n-----------------------------";
        cout << "\nPoped element is:  " << h->data;
        h = h->next;
        cout << "\n-----------------------------";
        return h;
    }
}

node *converToList(node *h)
{
    cin.get(); // Important to flush out cache
               // cin.clear();
    char exp[80];
    cout << "\nEnter expression: ";
    cin.get(exp, 80);
    int i = 0;
    while ((int)exp[i] != 0)
    {
        h = Push(h, exp[i]);
        i++;
    }
    cout << "\n-----------------------------";
    cout << "\n     Pushed Expression To List";
    cout << "\n-----------------------------";

    return h;
}

void seeList(node *h)
{
    if (h == NULL)
    {
        cout << "\n-----------------------------";
        cout << "\n        Stack is Empty";
        cout << "\n-----------------------------";
    }
    else
    {
        cout << "\n-----------------------------";
        cout << "\nStack elements are: \n";
        while (h->next != NULL)
        {
            cout << h->data << endl;
            h = h->next;
        }
        cout << h->data << endl;
        cout << "\n-----------------------------";
    }
}

int main()
{
    node *head = NULL;

    int choice = 0, elem, size;

    while (choice != 9)
    {
        cout << "\n.............................";
        cout << "\n1.Peek\n2.Push\n3.Pop\n4.Push Expression\n0.SeeList\n9.Quit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Peek(head);
            break;
        case 2:
            char c;
            cout << "\n-----------------------------";
            cout << "\nEnter the char: ";
            cin >> c;
            head = Push(head, c);
            break;
        case 3:
            head = Pop(head);
            break;
        case 4:
            head = converToList(head);
            break;

        case 0:
            seeList(head);
            break;
        case 9:
            cout << "\n-----------------------------";
            cout << "\n         Bye";
            cout << "\n-----------------------------\n";
            break;
        default:
            cout << "\n-----------------------------";
            cout << "\n         Wrong Choice";
            cout << "\n-----------------------------";
            break;
        }
    }

    return 0;
}
