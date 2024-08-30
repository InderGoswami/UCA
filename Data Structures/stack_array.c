#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
int *arr=NULL;
int ind=0;
int max_size=1;//intitalize the stack size with 1
int get_size(){
    return ind;
}
bool is_empty(){
    return ind==0;
}
void resize_arr(int new_size){
    int* large_arr= (int*)malloc(sizeof(int)*new_size);
    for(int i=0;i<ind;i++){
        large_arr[i]=arr[i];
    }
    free(arr);
    arr=large_arr;
}
void push(int data){
    if(arr==NULL){
        arr=malloc(sizeof(int)*max_size);
    }
    arr[ind]=data;
    ind++;
    if(ind==max_size){
        resize_arr(2*max_size);
        max_size*=2;
    }
}
int pop(){
    if(arr==NULL || ind==0){
        return -1;
    }
    int val=arr[ind-1];
    ind--;
    if(ind>0 && ind==max_size/4){
        resize_arr(max_size/2);
        max_size/=2;
    }
    return val;
}
void test_stack() {
    // Test 1: Create an empty stack and check initial state
    assert(is_empty() == true);
    assert(get_size() == 0);

    // Test 2: Push elements and verify size and order
    push(10);
    assert(is_empty() == false);
    assert(get_size() == 1);
    assert(pop() == 10);
    assert(get_size() == 0);

    // Test 3: Push more elements to test dynamic resizing
    push(20);
    push(30);
    push(40);
    push(50);
    assert(get_size() == 4);

    // Pop elements and verify the order
    assert(pop() == 50);
    assert(pop() == 40);
    assert(pop() == 30);
    assert(pop() == 20);
    assert(is_empty() == true);
    assert(get_size() == 0);

    // Test 4: Check underflow (pop from empty stack)
    assert(pop() == -1); // Should indicate an empty stack

    // Test 5: Push elements and test resizing down
    for (int i = 0; i < 8; i++) {
        push(i);
    }
    assert(get_size() == 8);

    for (int i = 7; i >= 0; i--) {
        assert(pop() == i);
    }
    assert(is_empty() == true);
    assert(get_size() == 0);

    // Additional tests can be added as needed
}

int main(){
  test_stack();
  printf("All test cases passed\n");  
}