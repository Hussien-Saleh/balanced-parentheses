/*
 @author      : Hussien Saleh 
 Here is an application to check balanced parentheses using my own stack
 */


#include "../include/stackArray.h"

#define EXPR_LEN  20 //length of expression and the stack

/* function to check the balanced parentheses 
 @param, expr, pointer to the expression entered by the user
 @return if the expression is balanced or not
*/

uint8 balancedParentheses(uint8 *expr);

/* function to check if two characters are matched 
 @param, firstChar, character pulled from the stack
 @param, secondChar, character compared from the expression
 @return if the characters entered are matched or not
*/

uint8 is_matched (uint8 firstChar, uint8 secondChar);


int main(){
    uint8 expr[EXPR_LEN]; // expression entered by the user
    printf("\nplease enter the expression:  ");
    scanf("%s", expr);

    if(balancedParentheses(expr) == 1)
        printf("\nBalanced\n"); // balanced if returned value equals to 1
    else
        printf("\nNot balanced\n"); // not balanced

    return 0;
}


uint8 balancedParentheses(uint8* expr){
    
    stack *s = stack_create(EXPR_LEN); // temporary stack is created

    /* Traverse through the given expression */
    for (uint32 index =  0; index < EXPR_LEN; index++){

        /* push an opening parentheses if found */
        if(expr[index] == '(' || expr[index] == '{')
        {   
            push(expr[index],s); // push the open bracket
        }
        /* check the opposite closing parentheses*/
        if( expr[index] == ')' || expr[index]== '}') 
        {  
            // if the stack is empty
            if(get_top(s) == -1)
                return 0;
            else
            {   // compare the two characters. opening parentheses pulled off the stack and closing ones off the expression
                if(is_matched(pull(s),expr[index])==0)
                    return 0;
            }
        }
    }
    // if the stack is empty after fully traversing the expression
    if(get_top(s) == -1)
        return 1; // balanced 
    else
        return 0; // not_balanced
}

uint8 is_matched (uint8 firstChar, uint8 secondChar) 
{ 
    if ((firstChar == '(' && secondChar == ')') ||
        (firstChar == '{' && secondChar == '}'))
        return 1; 
    else
        return 0; 
} 
    