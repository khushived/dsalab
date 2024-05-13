#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int top=-1;
int stack[100];
void push(int el){
    return stack[++top]=el;
}
int pop(){
    return stack[top--];
}
int peek(){
    return stack[top];
}

