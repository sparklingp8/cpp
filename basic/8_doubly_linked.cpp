#include <iostream>
using namespace std;

struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};

int listSize(dnode *h)
{
    if (h == NULL)
    {
        return 0;
    }
    else
    {
        int cnt = 1;
        while (h->next != NULL)
        {
            cnt++;
            h = h->next;
        }
        return cnt;
    }
}

dnode *creatNode(int elm)
{
    dnode *newNode = (dnode *)malloc(sizeof(dnode));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = elm;

    return newNode;
}

void seeList(dnode *h)
{
    if (h == NULL)
    {
        cout << "\n---------------------------";
        cout << "\n     List is Empty";
        cout << "\n---------------------------";
    }
    else
    {
        cout << "\n---------------------------\n";
        cout << "List element are:\n";
        while (h->next != NULL)
        {
            cout << h->data << endl;
            h = h->next;
        }
        cout << h->data << endl;
        cout << "---------------------------";
    }
}

dnode *addAtend(dnode *h, int elm)
{
    dnode *newNode = creatNode(elm);
    dnode *temp = h;
    if (temp == NULL)
    {
        temp = newNode;
        return temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    cout << "\n---------------------------\n";
    cout << elm << " added to list";
    cout << "\n---------------------------";
    return h;
}

dnode *addAtBegin(dnode *h, int elm)
{
    dnode *temp, *nwnode;
    nwnode = creatNode(elm);

    if (h == NULL)
    {
        return nwnode;
    }
    else
    {
        h->prev = nwnode;
        nwnode->next = h;
        return nwnode;
    }
    cout << "\n---------------------------\n";
    cout << elm << " added to list";
    cout << "\n---------------------------";
}

void addAtNthPlce(dnode *h, int elm, int plc)
{
    dnode *tmp = h;
    dnode *nwnode = creatNode(elm);
    for (int i = 2; i < plc; i++)
    {
        tmp = tmp->next;
    }
    nwnode->prev = tmp;
    nwnode->next = tmp->next;
    tmp->next = nwnode;
    cout << "\n---------------------------\n";
    cout << elm << " added to list";
    cout << "\n---------------------------";
}

void revList(dnode *h)
{
    dnode *tmp = h;
    if (h == NULL)
    {
        cout << "\n---------------------------";
        cout << "\n     List is Empty";
        cout << "\n---------------------------";
    }
    else
    {
        cout << "\n---------------------------\n";
        cout << "Reverse List element are:\n";
        while (h->next != NULL)
        {
            h = h->next;
        }
        while (h->prev != NULL)
        {
            cout << h->data << endl;
            h = h->prev;
        }
        cout << h->data << endl;
        cout << "---------------------------";
    }
}

int main()
{

    int choice = -1, elem, plce, lsize;
    dnode *head = NULL;

    while (choice != 0)
    {
        seeList(head);
        cout << "\n............................\n";
        cout << "1.See List\n2.Add At End\n3.Add At Begin\n4.Add at nth place";
        cout << "\n8.Reverse list\n9.List Size\n0.Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            seeList(head);
            break;
        case 2:
            cout << "\nEnter the number to be added: ";
            cin >> elem;
            head = addAtend(head, elem);
            break;
        case 3:
            cout << "\nEnter the number to be added: ";
            cin >> elem;
            head = addAtBegin(head, elem);
            break;
        case 4:
            cout << "\nEnter the place : ";
            cin >> plce;
            lsize = listSize(head);
            if (plce < 0 || plce >= lsize + 2)
            {
                cout << "\n---------------------------";
                cout << "\nCant insert at " << plce << " because length is " << lsize;
                cout << "\n---------------------------";
                break;
            }
            else
            {
                cout << "\nEnter the number to be added: ";
                cin >> elem;
                if (plce == 0 || plce == 1)
                {
                    head = addAtBegin(head, elem);
                    break;
                }
                else if (plce == lsize + 1)
                {
                    head = addAtend(head, elem);
                    break;
                }
                else
                {
                    addAtNthPlce(head, elem, plce);
                    break;
                }
            }
        case 8:
            revList(head);
            break;
        case 9:
            cout << "\n---------------------------";
            cout << "\nList size is: " << listSize(head);
            break;
            cout << "\n---------------------------\n";
        case 0:
            cout << "\n---------------------------";
            cout << "\n        Bye";
            cout << "\n---------------------------\n";
            break;
        default:
            cout << "\n---------------------------";
            cout << "\n       Wrong choice";
            cout << "\n---------------------------";
            break;
        }
    }
    return 0;
}