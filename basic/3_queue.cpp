#include <iostream>
using namespace std;

#define SIZE 5

struct quetmplt
{
    int front;
    int rare;
    int slot[SIZE];
};

void createQueue(quetmplt *q)
{
    q->front = 0;
    q->rare = -1;
}

bool isFull(quetmplt *q)
{
    if (q->rare == SIZE - 1)
    {
        cout << "\n-------------------------";
        cout << "Queue is full :(";
        cout << "\n-------------------------";

        return true;
    }
    else
    {
        return false;
    }
}

void enque(quetmplt *q, int elm)
{
    q->rare = q->rare + 1;
    q->slot[q->rare] = elm;
    cout << "\n-------------------------";
    cout << endl
         << elm << " added to queue";
    cout << "\n-------------------------";
}

void deque(quetmplt *q)
{
    if (q->front + 1 == q->rare + 1)
    {
        cout << "\n-------------------------";
        cout << endl
             << q->slot[q->front] << " is the Dequed elment & it last in queue";
        cout << "\nreseting the queue";
        createQueue(q);
        cout << "\n-------------------------";
    }
    else
    {
        cout << "\n-------------------------";
        cout << endl
             << q->slot[q->front] << " is the Dequed elment";
        cout << "\n-------------------------";
        q->front += 1;
    }
}

bool isEmpty(quetmplt *q)
{
    if (q->rare == -1)
    {
        cout << "\n-------------------------";
        cout << "\nQueue is Empty :(";
        cout << "\n-------------------------";

        return true;
    }
    else
    {
        return false;
    }
}

void peek(quetmplt *q)
{
    cout << "\n-------------------------";
    cout << endl
         << q->slot[q->front] << "is the first elemnt in queue";
    cout << "\n-------------------------";
}

void seeFull(quetmplt *q)
{
    cout << "\n-------------------------";
    cout << "\nQueue elemnts are: ";
    for (int i = q->front; i <= q->rare; i++)
    {
        cout << "\n> " << q->slot[i];
    }
    cout << "\n-------------------------";
}

int main()
{
    quetmplt *queu1 = (quetmplt *)malloc(sizeof(quetmplt));
    createQueue(queu1);
    int choice, elem;

    while (choice != 9)
    {
        cout << "\n....................... " ;
        cout << "\n1.Enqueue\n2.Dequeu\n3.Peek\n4.SeeFullQ\n9.Quit";
        cout << "\nEnter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!isFull(queu1))
            {
                cout << "\nEnter elment to be added in queue: ";
                cin >> elem;
                enque(queu1, elem);
            }
            break;
        case 2:
            if (!isEmpty(queu1))
            {
                deque(queu1);
            }
            break;
        case 3:
            if (!isEmpty(queu1))
            {
                peek(queu1);
            }
            break;
        case 4:
            if (!isEmpty(queu1))
            {
                seeFull(queu1);
            }
            break;
        case 9:
            cout << "\n-------------------------";
            cout << "\nBye___________.";
            cout << "\n-------------------------";
            break;

        default:
            cout << "\nEnter Correct Choice.";
            break;
        }
    }

    return 0;
}