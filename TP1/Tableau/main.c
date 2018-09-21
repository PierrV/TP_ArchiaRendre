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

void init_stack(stack_t* tab_t){
    tab_t->tab = (int*)malloc(sizeof(int)*MAX);
    tab_t->top = -1;
    tab_t->taille = MAX;
}

int push_stack(stack_t * tab_t, int elm){
    int taille = tab_t->taille;

    if(tab_t->top > taille/2){
        tab_t->tab = (int*)realloc(tab_t->tab, taille*2);
        tab_t->taille = taille * 2;
    }

    tab_t->top += 1;
    tab_t->tab[tab_t->top] = elm;

    return tab_t->top;
}

void display_stack(stack_t * tab_t){
    int i;
    int taille = ( tab_t->taille );

    printf("STACK DATAS %d \n", taille);

    for(i = 0; i < taille; i++){
        printf("Case %d : %d \n", i, tab_t->tab[i]);
    }
}

int pop_stack(stack_t * tab_t, int * elm) {
    if(tab_t->top >= 0){
    *elm = tab_t->tab[tab_t->top];
    tab_t->tab[tab_t->top] = 0;
    tab_t->top--;
    } else {
        printf("ERROR : la pile est vide ! \n");
        *elm = -1;
    }
    return *elm;
}

int top_stack(stack_t * tab_t, int * elm) {
    *elm = tab_t->tab[tab_t->top];
    return *elm;
}

