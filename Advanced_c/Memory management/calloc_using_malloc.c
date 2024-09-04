#include<stdio.h>
#include<stdlib.h>
void* calloc_using_malloc(int n){//n is here number of bytes
    char* arr=(char*)malloc(n);//basically we are making pointer char type so that we can iterate on each byte and make it zero
    int i=0;
    while(i<n){
        *(arr+i)='\0';//null characterg
        i++;
    }

    return (void*)arr;

}
int main(){
    int n=8; //to store 2 integers 
    int *arr=(int*)calloc_using_malloc(n);//typecasting void* into char*
    if(arr==NULL){
        printf("Problem in using calloc function formed using malloc function \n");
    }
    else{
        for(int i=0;i<n;i++){
            printf("%d ",*(arr+i));//printing byte by byte
        }
    }
    free(arr);


}