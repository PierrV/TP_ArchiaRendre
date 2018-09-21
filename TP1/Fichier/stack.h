#define __STACK_H__

#define MAX_FLNM 100
typedef struct {
 char filename[MAX_FLNM];
 int fd; // file descriptor of the open file
 int top_off; // final offset
} stack_t;

void set_file(stack_t *, char *); // special function to determine the file to be used


void init_stack(stack_t *); // initalize the data structure
int push_stack(stack_t *, int); // push value into stack
int pop_stack(stack_t *, int *); // pops top value from stack;
int top_stack(stack_t *, int *); // returns top value of stack
void display_stack(stack_t *); // displays the contents of the stack
