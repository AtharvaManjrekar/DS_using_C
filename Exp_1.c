#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int items[MAX];
    int top;
};


void createStack(struct Stack* s) {
    s->top = -1;
}


int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}


int isEmpty(struct Stack* s) {
    return s->top == -1;
}


void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}


int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;  
    } else {
        return s->items[(s->top)--];
    }
}

int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to peek\n");
        return -1;  // Return a sentinel value to indicate failure
    } else {
        return s->items[s->top];
    }
}

void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {



    struct Stack stack;
    createStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  // This should cause stack overflow

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    printf("Top element is: %d\n", peek(&stack));

    return 0;
}
