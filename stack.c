//--------Onomata-------------ΑΜ----------------
//--------Eleni_Frantzi-------2020010133--------
//--------Elisavet_Manali-----2020010087--------
//--------Rafaillia_Platinaki-2020010126--------
//--------Rodopi_Viltanioti---2020010117--------
//----------------------------------------------
#include <stdio.h>
#include "stack.h"

void init_stack(Stack *stk)
{
	stk->top = -1;
}

void push(Stack *stk, int a)
{
	if (isfull(*stk)) printf("Stack is full\n");
	else {
		stk->stack_array[++stk->top] = a;
	}
}

void pop(Stack *stk, int *e){
	if (isempty(*stk)) printf("Stack is empty\n");
	else {
		*e = stk->stack_array[stk->top];
		--stk->top;
		}
}

int isempty(Stack stk)
{
	return (stk.top == -1);
}

int isfull(Stack stk)
{
	return (stk.top == STACK_LEN - 1);
}

