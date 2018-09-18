#define __STACK_H__

typedef struct node {
 int val;
 struct node * next;
} node_t;

typedef struct stack {
 node_t * top;
} stack_t;


void init_stack(stack_t *); // initalize the data structure
int push_stack(stack_t *, int); // push value into stack
int pop_stack(stack_t *, int *); // pops top value from stack;
int top_stack(stack_t *, int *); // returns top value of stack
void display_stack(stack_t *); // displays the contents of the stack



