#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
struct Node{
    int data;//data
    struct Node* next;//pointer refering to next Node
    
};
typedef struct Node Node;
Node* head=NULL;
int size=0;//size tracker
void insert_front(int data){
    Node* new_node=(Node*)(malloc(sizeof(Node)));
    new_node->data=data;
    new_node->next=head;
    head=new_node;
    size++;

}
void insert_mid(int data,int pos){
    Node* new_node=(Node*)(malloc(sizeof(Node)));
     new_node->data=data;
    if(pos==0){
        insert_front(data);
        return;
    }
    size++;
    Node* prev_node=head;
    //zero based positioning
    for(int i=1;i<pos;i++){
        prev_node=prev_node->next;
    }
    Node* ahead_node=prev_node->next;
    prev_node->next=new_node;
    new_node->next=ahead_node;

    

}
void insert_last(int data){

    Node* new_node=(Node*)(malloc(sizeof(Node)));
    new_node->data=data;
    size++;
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* prev_node=head;
    while(prev_node->next!=NULL){
        prev_node=prev_node->next;
    }
    prev_node->next=new_node;
}
int remove_start(){
    if(head==NULL){
        return -1;
    }
    Node* temp_node=head;
    int val=temp_node->data;
    //Manually free the space for node to be deleted
    head=head->next;
    free(temp_node);
    size--;
    return val;
}
int remove_mid(int pos){
    if(pos==0){
        return remove_start();
    }
    Node* prev=NULL;
    Node* curr=head;
    int i=0;
    while(i<pos){
        prev=curr;
        curr=curr->next;
        i++;
    }
    int val=curr->data;
    
    prev->next=curr->next;
    free(curr);
    size--;
    return val;

}
int remove_last(){
    Node* curr_node=head;
    if(curr_node==NULL){
        return -1;
    }
    if(head->next==NULL){ 
        int val=head->data;
        free(curr_node);
        return val;
    }
    size--;
    Node* prev_node=NULL;
    while(curr_node->next!=NULL){
        prev_node=curr_node;
        curr_node=curr_node->next;
        
    }
    int val=curr_node->data;
    prev_node->next=NULL;
    free(curr_node);
    return val;
}
void test_case() {
    // Initial checks
    assert(head == NULL); // The list should be empty at the start
    assert(size == 0);    // Size should be 0 at the start

    // Test insert_last
    insert_last(45);
    assert(head != NULL);
    assert(head->data == 45);
   
    assert(size == 1);

    insert_last(54);
    assert(head->next != NULL);
    assert(head->next->data == 54);
    
    assert(size == 2);

    insert_last(78);
    assert(head->next->next != NULL);
    assert(head->next->next->data == 78);
    assert(size == 3);

    // Test insert_front
    insert_front(23);
    assert(head->data == 23);
    assert(size == 4);

    // Test insert_mid
    insert_mid(99, 2);
    assert(head->next->next->data == 99);
    assert(size == 5);

    // Test remove_start
    int removed_val = remove_start();
    assert(removed_val == 23);
    assert(head->data == 45);
    assert(size == 4);

 
    // Test remove_last
    removed_val = remove_last();
    assert(removed_val == 78);
    assert(size == 3);

    


    printf("All test cases passed!\n");
}

int main() {
    test_case();  // Run the test cases
    return 0;
}
