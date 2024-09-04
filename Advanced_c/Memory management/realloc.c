#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr=malloc(sizeof(int)*5);//Memory is allocated for 5 integers using malloc
    //take input form user
    for(int i=0;i<5;i++){
        scanf("%d",(arr+i));
    }
    //increase the size of allocated memory to accomodate 10 integers using realloc
    int* new_arr=realloc(arr,10*sizeof(int));
    //Now check the values exists by default at this 10 places
    for(int i=0;i<10;i++){
        printf("%d\n",*(new_arr+i));
    }
    free(new_arr);
    free(arr);
}
