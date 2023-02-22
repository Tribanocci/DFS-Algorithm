#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STACK_LEN 10



typedef struct stack {
	int stack_array[STACK_LEN];
	int top;
} Stack;

void init_stack(Stack *stk);
void push(Stack *stk, int a);
void pop(Stack *stk, int *e);
int isempty(Stack stk);
int isfull(Stack stk);

#endif /* STACK_H_INCLUDED */
