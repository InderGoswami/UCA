#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* head=NULL;
int n=0;
int size(){
    return n;
}
bool is_empty(){
    return n==0;
}
void push(int data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    n++;
    //insert at head
    if(head==NULL){
        head=new_node;
        new_node->next==NULL;
        return;

    }
    new_node->next=head;
    head=new_node;

}
int pop(){
    if(head==NULL){
        return -1;
    }
    n--;
    Node* temp=head;
    int d=head->data;
    head=head->next;
    free(temp);
    return d;
}
int testStack() {
    push(3);
    push(10);
    push(20);

    assert(is_empty() == false);
    assert(size() == 3);
    assert(pop() == 20);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 3);
    assert(size() == 0);
    assert(is_empty());
}

int main() {
    testStack();
    printf("Success");
    return 0;
}
