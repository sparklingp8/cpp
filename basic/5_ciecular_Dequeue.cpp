#include <iostream>
using namespace std;
//all double sided queue function implementation in C++
#define SIZE 5

struct circQtmplt
{
    int arr[SIZE];
    int front;
    int rare;
};

void createCq(circQtmplt *cq)
{
    cq->front = -1;
    cq->rare = -1;
}

bool isFull(circQtmplt *cq)
{
    if ((cq->rare + 1) % SIZE == cq->front)
    {
        cout << "\n----------------------------------------";
        cout << "\nQueue is fulllllllllllllll..............";
        cout << "\n----------------------------------------";
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(circQtmplt *cq)
{
    if (cq->front == -1 && cq->rare == -1)
    {
        cout << "\n----------------------------------------";
        cout << "\nQueue is Empty..............";
        cout << "\n----------------------------------------";
        return true;
    }
    else
    {
        return false;
    }
}

void peek(circQtmplt *cq)
{
    if (!isEmpty(cq))
    {
        cout << "\n----------------------------------------\n";
        cout << cq->arr[cq->front] << " is the first element in Queue";
        cout << "\n----------------------------------------";
    }
}

void enque(circQtmplt *cq, int e)
{
    if (cq->rare == -1)
    {
        cq->front = 0;
        cq->rare = 0;
        cq->arr[cq->rare] = e;
    }
    else
    {
        cq->rare = (cq->rare + 1) % SIZE;
        cq->arr[cq->rare] = e;
    }
    cout << "\n----------------------------------------\n";
    cout << e << " is added Queue";
    cout << "\n----------------------------------------";
}
void enqueueFront(circQtmplt *cq, int elm)
{
    if (cq->rare == -1)
    {
        cq->rare = 0;
    }
    if (cq->front == 0)
    {
        cq->front = SIZE - 1;
    }
    else if (cq->front == -1)
    {
        cq->front = 0;
    }
    else
    {
        cq->front -= 1;
    }
    cq->arr[cq->front] = elm;
    cout << "\n----------------------------------------\n";
    cout << elm << " is added Queue";
    cout << "\n----------------------------------------";
}

void deque(circQtmplt *cq)
{
    if (!isEmpty(cq))
    {
        if (cq->front == cq->rare)
        {
            cout << "\n----------------------------------------\n";
            cout << cq->arr[cq->front] << " is last element of Queue";
            cout << "\n----------------------------------------";
            createCq(cq);
        }
        else
        {
            cout << "\n----------------------------------------\n";
            cout << cq->arr[cq->front] << " is Dequeued";
            cout << "\n----------------------------------------";
            cq->front = (cq->front + 1) % SIZE;
        }
    }
}
void deQueueRare(circQtmplt *cq)
{
    if (cq->front == cq->rare)
    {
        cout << "\n----------------------------------------\n";
        cout << cq->arr[cq->front] << " is last element of Queue";
        cout << "\n----------------------------------------";
        createCq(cq);
    }
    else
    {
        cout << "\n----------------------------------------\n";
        cout << cq->arr[cq->rare] << " is Dequeued";
        cout << "\n----------------------------------------";
        if (cq->rare - 1 == -1)
        {
            cq->rare = SIZE - 1;
        }
        else
        {
            cq->rare -= 1;
        }
    }
}

void seeAll(circQtmplt *cq)
{
    cout << "\n----------------------------------------\n";
    cout << "\nQueue elements are:\n";
    for (int i = cq->front; i != (cq->rare);)
    {

        cout << cq->arr[i] << endl;
        i = (i + 1) % SIZE; // IMPORTANT
    }
    cout << cq->arr[cq->rare] << endl; // IMPORTATNT
    cout << "\n----------------------------------------\n";
}

int main()
{
    circQtmplt *cq1 = (circQtmplt *)malloc(sizeof(circQtmplt));
    createCq(cq1);

    int choice = 0, elem;

    while (choice != 7)
    {
        cout << "\n\n..........................................";
        cout << "\n1.EnQueue at rare \n2 Enqueue at front\n3.Deque at rare\n4.DeQueue at front\n5.peek\n6.seeAll\n7.quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!isFull(cq1))
            {
                cout << "\nEnter the new element: ";
                cin >> elem;
                enque(cq1, elem);
            }
            break;
        case 2:
            if (!isFull(cq1))
            {
                cout << "\nEnter the new element: ";
                cin >> elem;
                enqueueFront(cq1, elem);
            }
            break;
        case 3:
            if (!isEmpty(cq1))
            {
                deQueueRare(cq1);
            }
            break;
        case 4:
            deque(cq1);
            break;
        case 5:
            peek(cq1);
            break;
        case 6:
            if (!isEmpty(cq1))
            {
                seeAll(cq1);
            }
            break;
        case 7:
            cout << "\n----------------------------------------";
            cout << "\nBye................";
            cout << "\n----------------------------------------\n";
            break;

        default:
            cout << "\n----------------------------------------";
            cout << "\nWrong Choice";
            cout << "\n----------------------------------------";
            break;
        }
    }
}
