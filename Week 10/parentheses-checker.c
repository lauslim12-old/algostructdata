#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char arr[MAX_SIZE];
} st;

void init() {
    st.top = -1;
}

bool isEmpty() {
    if(st.top == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull() {
    if(st.top == MAX_SIZE-1) {
        return true;
    }
    else {
        return false;
    }
}

void push(char item){
    if(isFull()){
            printf("Stack is full!");
    }
    else {
        st.top++;
        st.arr[st.top] = item;
    }
}

void pop() {
    if(isEmpty()){
        printf("Stack is empty!");
    }
    else{
        st.top--;
    }
}

char gettop() {
    return st.arr[st.top];
}

bool ArePair(char opening, char closing) {
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int main() {
    char in_expr[MAX_SIZE];
    int length = 0, i, j;
    bool matched = false;

    while(1) {
        init();

        printf("Masukkan pola: ");
        gets(in_expr);
        length = strlen(in_expr);
        matched = true;

        for(i = 0; i < length; i++) {
            if(in_expr[0] == '-' && in_expr[1] == '1') {
                printf("Terima kasih telah memakai program parentheses checker ini. \n");
                return 0;
            }

            if(in_expr[0] != '(' && in_expr[0] != '{' && in_expr[0] != '[') {
                matched = false;
            }

            if(in_expr[i] == '(' || in_expr[i] == '{' || in_expr[i] == '[') {
                push(in_expr[i]);
            }

            else if(in_expr[i] == ')' || in_expr[i] == '}' || in_expr[i] == ']') {
                char a = gettop();
                if(isEmpty() || !ArePair(gettop(), in_expr[i])) {
                    matched = false;
                }
                else {
                    pop();
                }
            }
        }

        if(isEmpty() && matched == true) {
            printf("Valid parenthesis expression! \n\n");
        }
        else {
            printf("Invalid parenthesis expression! \n\n");
        }
    }

    return 0;
}



