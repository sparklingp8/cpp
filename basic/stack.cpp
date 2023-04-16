#include<iostream>
using namespace std;

#define MAX 10


struct stck{
    int top;
    int items[MAX];
};
typedef struct stck st;

void createEmptyStack(st *s) {
  s->top = -1;
}

// Check if the stack is full
int isfull(st *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(st *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(st *s, int newitem) {
  if (isfull(s)) {
    cout << "STACK FULL";
  } else {
    s->top++;
    s->items[s->top] = newitem;
  }
  
}
// pop elements into stack
void pop(st *s) {
  if (isempty(s)) {
    cout << "STACK is Empty";
  } else {
    cout << "Poped element is" << s->items[s->top];
    s->top--;    
  }
  
}




// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < 4; i++) {
    cout << s->items[i] << " ";
  }
  cout << endl;
}
int main(){
    cout<<"hi";
    int ch;
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);

    return 0;
}