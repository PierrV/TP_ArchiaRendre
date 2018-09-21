#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
 stack_t p;
 #ifdef __FILE__STACK__
 set_file(&p, "persistentStack");
 #endif

 init_stack(&p);
 push_stack(&p, 5);
 push_stack(&p, 6);
 push_stack(&p, 7);
 display_stack(&p);
 scanf("%*c");
 int val;
 pop_stack(&p, &val);
 printf("popped value = %d\n", val);
 display_stack(&p);
 pop_stack(&p, &val);
 printf("popped value = %d\n", val);
 display_stack(&p);
 pop_stack(&p, &val);
 printf("popped value = %d\n", val);
 display_stack(&p);
 pop_stack(&p, &val); // fails
 printf("popped value = %d\n", val); // prints out the old value
 display_stack(&p);
}

void init_stack(stack_t* node){
    node_t *p = malloc(sizeof(node_t));
    p->next = NULL;
    node->top = p;
}

int push_stack(stack_t * nt, int elm){
    node_t *n = malloc(sizeof(node_t));
    n->val = elm;
    n->next = nt->top;
    nt->top = n;
    return n->val;
}

void display_stack(stack_t * node){
    int i = 0;
    node_t* n = node->top;
    while(n->next != NULL){
        printf("Node %d : %d \n",i,n->val);
        n = n->next;
        i++;
    }
}

int pop_stack(stack_t * node, int * elm) {
    if(node->top->next != NULL){
        *elm = node->top->val;
        node->top = node->top->next;
    } else {
        printf("ERROR : pile vide \n");
        *elm = -1;
    }
    return *elm;
}

int top_stack(stack_t * node, int * elm) {
    node_t* n = &node->top;
    while(n->next != NULL){
        n = n->next;
    }
    *elm = n->val;
    return *elm;
}

