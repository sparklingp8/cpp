#include <iostream>

using namespace std;
#define MAX 10

struct stcktmplt
{
    int slot[MAX];
    int top;
};
void createEmptyStack(stcktmplt *s)
{
    s->top = -1;
}
int isEmpty(stcktmplt *s)
{
    if (s->top == -1)
    {
        cout << "\n-----------------------------";
        cout << "\nStack is empty";
        cout << "\n-----------------------------";
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stcktmplt *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek(stcktmplt *s)
{
    if (!isEmpty(s))
    {
        cout << "\n-----------------------------";
        cout << "\nTop element is " << s->slot[s->top];
        cout << "\n-----------------------------";
    }
}
void push(stcktmplt *s, int elm)
{

    s->top = s->top + 1;
    s->slot[s->top] = elm;
    cout << "\n-----------------------------";
    cout << "\nElement " << elm << " is pushed";
    cout << "\n-----------------------------";
}
void pop(stcktmplt *s)
{
    if (!isEmpty(s))
    {
        cout << "\n-----------------------------";
        cout << "\nElement " << s->slot[s->top] << " is poped out";
        cout << "\n-----------------------------";
        s->top = s->top - 1;
    }
}

void seeAll(stcktmplt *s)
{
    if (!isEmpty(s))
    {
        cout << "\n-----------------------------";
        cout << "\nStack elements are: \n";
        for (int i = 0; i <= s->top; i++)
        {
            cout << "> " << s->slot[i] << endl;
        }
        cout << "\n-----------------------------";
    }
}
int main()
{
    int choice = 0, elem;
    stcktmplt *stck1 = (stcktmplt *)malloc(sizeof(stcktmplt));
    createEmptyStack(stck1);

    while (choice != 7)
    {
        cout << "\n..............................";
        cout << "\n1.peek\n2.push\n3.pop\n4.seeAll\n5.quit";
        cout << "\n\nEnter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            peek(stck1);
            break;
        case 2:
            if (isFull(stck1))
            {
                cout << "\nStack OverFlow will happen sorry..........";
            }
            else
            {
                cout << "\nEnter element to be pushed: ";
                cin >> elem;
                push(stck1, elem);
            }

            break;
        case 3:
            pop(stck1);
            break;
        case 4:
            seeAll(stck1);
            break;
        case 5:
            cout << "\n-----------------------------";
            cout << "\nBye...........";
            cout << "\n-----------------------------";
            choice = 7;
            break;
        default:
            cout << "Enter correct choice";
        }
    }
}