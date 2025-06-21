#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int values[MAX];
char ops[MAX];
int top_val = -1, top_op = -1;

// Push and pop functions
void push_val(int val) {
    values[++top_val] = val;
}

int pop_val() {
    return values[top_val--];
}

void push_op(char op) {
    ops[++top_op] = op;
}

char pop_op() {
    return ops[top_op--];
}

int apply_op(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void show_stack_state() {
    printf("Ops stack: ");
    for(int i = 0; i <= top_op; i++) printf("%c ", ops[i]);
    printf(" | Values stack: ");
    for(int i = 0; i <= top_val; i++) printf("%d ", values[i]);
    printf("\n");
}

int evaluate(char* expr) {
    int i = 0;

    while(expr[i]) {
        if(expr[i] == ' ') {
            i++;
            continue;
        }

        if(expr[i] == '(') {
            push_op(expr[i]);
        }
        else if(isdigit(expr[i])) {
            int val = 0;
            while(isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            i--;
            push_val(val);
        }
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            push_op(expr[i]);
        }
        else if(expr[i] == ')') {
            while(top_op >= 0 && ops[top_op] != '(') {
                int b = pop_val();
                int a = pop_val();
                char op = pop_op();
                int res = apply_op(a, b, op);
                printf("Apply %d %c %d = %d\n", a, op, b, res);
                push_val(res);
                show_stack_state();
            }
            pop_op(); // remove '('
        }
        i++;
    }

    return pop_val();
}

int main() {
    char expr[] = "(3 + (2 * 4))";
    printf("Evaluating: %s\n", expr);
    int result = evaluate(expr);
    printf("Result: %d\n", result);
    return 0;
}
