#include "../include/stackArray.h"


stack* stack_create(uint32 capacity){

    stack *stk = (stack*) malloc(sizeof(stack));

    if (stk == NULL)
        return NULL; 

    stk->top = -1;
    stk->stack_capacity = capacity;
    stk->items = (uint8*)  malloc(sizeof(uint8) *capacity );

    if (stk->items == NULL)
    {
        free(stk);
        return NULL;
    }
    return stk;
}

sint16 get_top(stack *stk){
    return stk->top;
}

void push(uint8 u8_data,stack *stk){
    
    if(stk->top != stk->stack_capacity-1)
    {
        stk->items[++stk->top] = u8_data;    
    }
    else
    {
        print_stack(stk);
        exit(1);
    }
}

uint8 pull(stack *stk){
    
    if(stk->top != -1)
        return stk->items[stk->top--];
    else
    {
        print_stack(stk);
        exit(1);
    }
}

void print_stack(stack *stk){

    if(stk->top == -1)
        printf("\nthe stack is empty\n");

    else if(stk->top == stk->stack_capacity-1)
        printf("\nthe stack is full\n");
    else 
    {
        printf ("\n The status of the stack is \n");
        for (uint16 i = stk->top; i >= 0; i--)
        {
            printf ("%d\n", stk->items[i]);
        }
    }
    printf ("\n");
}
