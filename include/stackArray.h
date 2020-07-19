#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "typedefs.h"

typedef struct stack{
    
    uint8 *items; // number of items of the stack
    sint16 top;   // TOP index of the stack
    uint32 stack_capacity; // the stack capacity determined by the user

}stack;

/* 
 * A function to create a stack 
 * @param capacity, the stack size specified by the user
 * @return pointer to a stack
 */

stack* stack_create(uint32 capacity);

/* 
 * A function to return the current value of top index of the stack
 * @param stk, pointer to the stack
 * @return the value of top position
 */

sint16 get_top(stack *stk);

/* 
 * A function to push the values to the stack
 * @param u8_data,the value of data pushed into the stack
 * @param stk, pointer to the stack
 */

void push(uint8 u8_data, stack *stk);

/* 
 * A function to pull values to the stack
 * @param stk, pointer to the stack
 * @return the pulled value
 */

uint8 pull(stack *stk);

/* 
 * A function to print the stack
 * @param stk, pointer to the stack
 */

void print_stack(stack *stk);


#endif