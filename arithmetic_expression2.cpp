#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top = -1;
void pop();
void push(char);
char checkStack();
int main(){

    int i;
    char str[50];
    printf("Enter Expression:\n");
    scanf("%s",str);

    for(i = 0; i < strlen(str); i++){
        if(str[i] == '(')push(str[i]);
        else if(str[i] == '{')push(str[i]);
        else if(str[i] == '[')push(str[i]);

        if(str[i] == ')'){
            if(checkStack() == '(')pop();
            else{
                printf("\nInvalid Expression.");
                return 0;
            }
        }
        else if(str[i] == '}'){
            if(checkStack() == '{')pop();
            else{
                printf("\nInvalid Expression.");
                return 0;
            }
        }
        else if(str[i] == ']'){
            if(checkStack() == '[')pop();
            else{
                printf("\nInvalid Expression.");
                return 0;
            }
        }
    }
    if(top == -1)printf("\nValid Expression.");
    else printf("\nInvalid Expression.");
    return 0;
}
void push(char a){
    stack[++top] = a;
}
void pop(){
    if(top == -1){
        printf("\nInvalid Expression.");
        return;
    }
    else --top;
}
char checkStack(){

    return stack[top];
}
