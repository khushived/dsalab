#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*top=NULL;
void push(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("allocation failed");
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}
void pop(){
    if (top==NULL){
        printf("stack empty");
        return;
    }
    struct node*temp=top;
    top=top->next;
    printf("popped",temp->data);
    free(temp);
}