#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void seeList(struct node *h)
{
    
    if (h == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nEmpty List";
        cout << "\n-----------------------------------";
        return;
    }
    else if (h->next == NULL)
    {
        cout << "\n-----------------------------------";
        cout << "\nList elemnts are: \n"
             << h->data;
        cout << "\n-----------------------------------";
        cout << "\nList elemnts are: ";
    }
    else
    {
        struct node *temp=h;        
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

struct node *createNode(int elem)
{
    struct node *newNode = (struct node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = elem;
    return newNode;
}
struct node *addElemAtEnd(struct node *h, int elm)
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
    return h;
}

int main()
{
    struct node *head = NULL, *temp;
    int choice = 0, elem;
    while (choice != 10)
    {
        cout << "\n...................................";

        cout << "\n1.SeeList\n2.Add element at end\n10.Quit\nEnter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            seeList(head);
            break;
        case 2:
            cout << "\nEnter the element: ";
            cin >> elem;
            head = addElemAtEnd(head, elem);

        default:
            break;
        }
    }
}