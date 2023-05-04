/*
Steps to convert post to infix:
style: <operand> <operand> <<operator>>
ex: abc*+def^/-
1. start from R -> L
2. If incoming is opperand  ==> Push it
3. If incoming is operator  => Pop 2 elements ==> B=pop 1, A= pop 2 ===> push (A<operaotr>B)
*/
#include <iostream>
#include <string>

using namespace std;

struct node
{
    char data;
    node *next;
};

struct snode
{
    string data;
    snode *next;
};

snode *screateNode(string s)
{
    snode *newNode = (snode *)malloc(sizeof(snode));
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}

node *createNode(char chr)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = chr;
    newNode->next = NULL;
    return newNode;
}

char Peek(node *h)
{
    if (h == NULL)
    {
        return '\0';
    }
    else
    {

        return h->data;
    }
}
string sPeek(snode *h)
{
    if (h == NULL)
    {
        return "\0";
    }
    else
    {

        return h->data;
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

snode *sPush(snode *h, string s)
{

    if (h == NULL)
    {
        h = screateNode(s);
        return h;
    }
    else
    {
        snode *tmp;
        tmp = screateNode(s);
        tmp->next = h;
        h = tmp;
        return h;
    }
}

snode *sPop(snode *h)
{
    if (h == NULL)
    {

        return NULL;
    }
    else if (h->next == NULL)
    {

        h = NULL;
        return h;
    }
    else
    {

        h = h->next;

        return h;
    }
}

node *Pop(node *h)
{
    if (h == NULL)
    {

        return NULL;
    }
    else if (h->next == NULL)
    {

        h = NULL;
        return h;
    }
    else
    {

        h = h->next;

        return h;
    }
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

void infixToPostfix()
{
    cin.get(); // Important to flush out cache
               // cin.clear();
    char exp[80], pexp[80];
    cout << "\nEnter expression: ";
    cin.get(exp, 80);
    node *stack = NULL;
    char ctop;
    int i = 0, j = 0;

    while (exp[i] != '\0')
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '^' && exp[i] != '(' && exp[i] != ')')
        {
            pexp[j] = exp[i];
            i++;
            j++;
        }
        else
        {
            ctop = Peek(stack);

            if (ctop == '\0' || ctop == '(' || exp[i] == '(')
            {
                stack = Push(stack, exp[i]);
                i++;
            }
            else if (exp[i] == '^')
            {
                if (ctop == '^')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                }
                else
                {
                    stack = Push(stack, exp[i]);
                    i++;
                }
            }
            else if (exp[i] == ')')
            {
                while (ctop != '(')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                    ctop = Peek(stack);
                }
                stack = Pop(stack);
                i++;
            }
            else if (exp[i] == '*' or exp[i] == '/')
            {
                if (ctop == '+' || ctop == '-')
                {
                    stack = Push(stack, exp[i]);
                    i++;
                }
                else if (ctop != '^')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                }
                else if (ctop == '^')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                }
            }
            else if (exp[i] == '+' or exp[i] == '-')
            {
                if (ctop == '+' || ctop == '-')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                }
                else if (ctop == '*' || ctop == '/' || ctop == '^')
                {
                    pexp[j] = ctop;
                    j++;
                    stack = Pop(stack);
                }
            }
        }
    }
    ctop = Peek(stack);
    while (ctop != '\0')
    {
        if (ctop != '(' && ctop != ')')
        {
            pexp[j] = ctop;
            j++;
        }
        stack = Pop(stack);
        ctop = Peek(stack);
    }
    pexp[j] = '\0';
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\nPostfix Expression is: " << pexp;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void postfixToInfix()
{
    cin.get();
    char exp[80], pexp[80];
    cout << "\nEnter expression: ";
    cin.get(pexp, 80);
    snode *stack = NULL;
    char ctop;
    string str, sinfix;
    int i = 0, j = 0;
    while (pexp[i] != '\0')
    {
        if (pexp[i] != '+' && pexp[i] != '-' && pexp[i] != '*' && pexp[i] != '/' && pexp[i] != '^')
        {
            str = "";
            str += pexp[i];
            stack = sPush(stack, str);
            i++;
        }
        else
        {
            string A, B;
            str = "(";
            B = sPeek(stack);
            stack = sPop(stack);
            A = sPeek(stack);
            stack = sPop(stack);
            str += A + pexp[i] + B + ")";
            stack = sPush(stack, str);
            i++;
        }
    }

    string A, B;
    str = "";
    B = sPeek(stack);
    stack = sPop(stack);
    A = sPeek(stack);
    stack = sPop(stack);
    str += A + pexp[i] + B;
    stack = sPush(stack, str);
    cout << "\n````````````````````````";
    cout << "\nInfix Expression: " << sPeek(stack);
    cout << "\n````````````````````````";
}
int main()
{
    node *head = NULL;

    int choice = 0, elem, size;

    while (choice != 9)
    {
        cout << "\n.............................";
        cout << "\n1.Infix to Postfix\n2.Postfix to Infix\n9.Quit";
        cout << "\nEnter choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            infixToPostfix();
            cin.get();
            break;
        case 2:
            postfixToInfix();
            cin.get();
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
