#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
};

int listSize(node *h)
{
    node *temp = h;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct node *createNode(int elem)
{
    struct node *newNode = (struct node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = elem;
    return newNode;
}

void seeList(struct node *h)
{

    if (h == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nList is empty";
        cout << "\n-----------------------------------";
        return;
    }
    else if (h->next == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nList elemnts are: \n"
             << h->data;
        cout << "\n-----------------------------------";
    }
    else
    {
        struct node *temp = h;
        cout << "\n-----------------------------------";
        cout << "\nList elemnts are: \n";
        while (temp->next != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
        cout << "\n-----------------------------------";
    }
}

struct node *addAtEnd(struct node *h, int elm)
{
    struct node *temp = h;
    if (h == NULL)
    {
        h = createNode(elm);
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = createNode(elm);
    }
    cout << "\n-----------------------------------\n";
    cout << elm << " added to list";
    cout << "\n-----------------------------------";
    return h;
}

struct node *addAtBeginning(struct node *h, int elem)
{
    if (h == NULL)
    {
        h = createNode(elem);
        cout << "\n----------------------------------\n";
        cout << elem << " added to list";
        cout << "\n-----------------------------------";
        return h;
    }
    else
    {
        struct node *temp = createNode(elem);
        temp->next = h;
        h = temp;
        cout << "\n-----------------------------------\n";
        cout << elem << " added to list";
        cout << "\n-----------------------------------";
        return h;
    }
}

void delAtend(node *h, node **ah) // double pointer be carefull
{
    if (h == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nEmpty list can't delete";
        cout << "\n-----------------------------------";
    }
    else if (h->next == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nDeleted last elemnt of list: " << h->data;
        cout << "\n-----------------------------------";
        *ah = NULL;
    }
    else
    {
        node *temp1, *temp2;
        temp1 = h;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        cout << "\n-----------------------------------\n";
        cout << temp1->data << " is deleted from the list";
        cout << "\n-----------------------------------";
        temp2->next = NULL;
    }
}

void delAtBeginnig(node *h, node **ah)
{
    if (h == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nEmpty list can't delete";
        cout << "\n-----------------------------------";
    }
    else if (h->next == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nDeleted last elemnt:" << h->data;
        cout << "\n-----------------------------------";
        *ah = NULL;
    }
    else
    {
        cout << "\n-----------------------------------";
        cout << "\nDeleted: " << h->data;
        cout << "\n-----------------------------------";
        node *temp = h->next;
        *ah = temp;
    }
}

void delAtnPlce(node *h, node **ah, int plc)
{
    node *temp1 = h;
    int i = 0;
    node *temp2;
    for (i = 0; i < plc - 1; i++)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    cout << "\n-----------------------------------\n";
    cout << temp1->data << " is removed from list";
    cout << "\n-----------------------------------";
}

node *addAtntPlce(node *h, int elm, int plc)
{
    node *tmp1, *tmp2;
    tmp1 = h;

    for (int i = 1; i < plc; i++)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }
    tmp2->next = addAtBeginning(tmp1, elm); // heavy logic understand carefully
    return h;
}

node *revList(node *h)
{
    node *prev, *cur, *nxt = NULL;

    prev = h;
    cur = prev->next;
    if (listSize(h) > 2)
    {
        nxt = cur->next;
        prev->next = NULL;
        while (nxt->next != NULL)
        {
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        nxt->next = cur;
        cur->next = prev;
        h = nxt;
    }
    else
    {
        prev->next = NULL;
        cur->next = prev;
        h = cur;       
    }

    cout << "\n-----------------------------------\n";
    cout << " List reversed  ";
    cout << "\n-----------------------------------";
    seeList(h);

    return h;
}

int main()
{
    struct node *head = NULL, *temp;
    int choice = -1, elem, plce, Lsize;
    while (choice != 0)
    {
        cout << "\n\n...................................";
        cout << "\n1.SeeList\n2.Add element at end\n3.Add element at beginnig";
        cout << "\n4.Delete at end\n5.Delete at beginnig";
        cout << "\n6.Add at nth place\n7.Delete at nth place";
        cout << "\n8.Reverse a list";
        cout << "\n9.Size of list\n0.Quit\nEnter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            seeList(head);
            break;
        case 2:
            cout << "\nEnter the element: ";
            cin >> elem;
            head = addAtEnd(head, elem);
            break;
        case 3:
            cout << "\nEnter the element: ";
            cin >> elem;
            head = addAtBeginning(head, elem);
            break;
        case 4:
            delAtend(head, &head);
            break;
        case 5:
            delAtBeginnig(head, &head);
            break;
        case 6:
            Lsize = listSize(head);
            cout << "Enter the place: ";
            cin >> plce;
            if (plce == 1)
            {
                cout << "\nEnter the element: ";
                cin >> elem;
                head = addAtBeginning(head, elem);
                break;
            }
            else if (plce == Lsize + 1)
            {
                cout << "\nEnter the element: ";
                cin >> elem;
                head = addAtEnd(head, elem);
                break;
            }
            else if (plce > Lsize || plce < 1)
            {
                cout << "\n-----------------------------------\n";
                cout << plce << " is out of bound bcz size is " << Lsize;
                cout << "\n-----------------------------------";
                break;
            }
            else
            {
                cout << "\nEnter the element: ";
                cin >> elem;
                head = addAtntPlce(head, elem, plce);
                break;
            }
        case 7:
            Lsize = listSize(head);
            if (Lsize == 0)
            {
                cout << "\n-----------------------------------\n";
                cout << "List is empty";
                cout << "\n-----------------------------------";
                break;
            }
            cout << "Enter the place: ";
            cin >> plce;
            if (plce > Lsize)
            {
                cout << "\n-----------------------------------\n";
                cout << plce << " is out of bound bcz size is " << Lsize;
                cout << "\n-----------------------------------";
            }
            else
            {
                if (plce == 1)
                {
                    delAtBeginnig(head, &head);
                }
                else if (plce == Lsize)
                {
                    delAtend(head, &head);
                }
                else
                {
                    delAtnPlce(head, &head, plce);
                }
            }
            break;

        case 8:
            Lsize = listSize(head);
            if (Lsize == 0)
            {
                cout << "\n-----------------------------------\n";
                cout << "List is empty";
                cout << "\n-----------------------------------";
                break;
            }
            else if (Lsize == 1)
            {
                cout << "\n-----------------------------------\n";
                cout << "List has only one element";
                cout << "\n-----------------------------------";
                break;
            }
            else
            {
                head = revList(head);
                break;
            }

        case 9:
            cout << "\n-----------------------------------\n";
            cout << listSize(head) << " is the length of the list";
            cout << "\n-----------------------------------";
            break;
        case 0:
            cout << "\n-----------------------------------";
            cout << "\n---------------Bye-----------------";
            cout << "\n-----------------------------------\n";
            break;

        default:
            cout << "\n-----------------------------------";
            cout << "\n---------Wrong choice--------------";
            cout << "\n-----------------------------------";
            break;
        }
    }
}
