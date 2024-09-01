#include<stdio.h>
int main(){
    // int a=12;
    // int *b=&a;
    // char *c=&a;
    // printf("%d\n",*b);
    // printf("%d",*c);
    int arr[]={1,2,3};
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        printf("%d\n",*arr+i);
    }
    return 0;
}