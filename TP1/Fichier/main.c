#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include <unistd.h>
#include <sys/types.h>

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


void set_file(stack_t * file, char * name){
    strcpy(file->filename, name);
    file->fd = 0;
    file->top_off = 0;
}

void init_stack(stack_t* file){
    char name[20] = "";
    printf("entrer nom du fichier : ");
    scanf("%s", name);

    set_file(file, name);

    file->fd = fopen(file->filename, "w+");

    if(file->fd == NULL){
        printf("error file");
        return(-1);
    }
}

int push_stack(stack_t * file, int elm){
    fseek( file->fd, file->top_off, SEEK_SET );
    int r = fprintf((FILE*)file->fd, "%d", elm);
    if(r == EOF){
        perror("Error ecriture");
        return(-1);
    }
    file->top_off += 1;
}

void display_stack(stack_t * file){
    int fp = file->fd;
    char c;
    printf("-------- PILE  --------\n\n");
    fseek( fp, 0, SEEK_SET );
    while((c = fgetc(fp)) != EOF) {
            printf("\t %c \n", c);
    }
    printf("\n-------- PILE  --------\n\n");

}

int pop_stack(stack_t * file, int * elm) {
    if(file->top_off > 0){
        int fp = file->fd;
        file->top_off--;

        fseek( fp, file->top_off, SEEK_SET );

        char c = fgetc(fp);
        *elm = c - 48;

        fseek( fp, file->top_off, SEEK_SET );
        int r = fprintf((FILE*)file->fd, "%c", '\0');
    } else {
        printf("ERROR - 1 : La pile est vide \n");
        *elm = -1;
    }
}

int top_stack(stack_t * file, int * elm) {
    int fp = file->fd;
    fseek( fp, file->top_off, SEEK_SET );
    *elm = fgetc(fp) - 48;
    return fgetc(fp) - 48;
}

