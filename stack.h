//
// Created by ASUS on 3/17/2024.
//

#ifndef GITHUBLIB_STACK_H
#define GITHUBLIB_STACK_H

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack){
    stack->top = -1;
}

bool is_empty(Stack *stack){
    return (stack->top == -1);
}

bool is_full(Stack *stack){
    return (stack->top == MAX_SIZE - 1);
}
void push(Stack *stack, int value){
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack){
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(Stack *stack){
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}


#endif //GITHUBLIB_STACK_H
