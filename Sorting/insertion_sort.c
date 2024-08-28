#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<assert.h>
void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0 && curr<arr[j]){
            arr[j+1]=arr[j];
            
            j--;
        }
        arr[j]=curr;
    }
}
double calculate_time(int arr[],int n){
    clock_t s_time,e_time;
    double CPU_time;
    s_time=clock();
    insertion_sort(arr,n);
    e_time=clock();
    CPU_time=(double)(e_time-s_time)/CLOCKS_PER_SEC;
    return CPU_time;


}
long calculate_memory(int arr[],int n){
    struct rusage s_memory,e_memory;
    int s1=getrusage(RUSAGE_SELF,&s_memory);
    insertion_sort(arr,n);
    int s2=getrusage(RUSAGE_SELF,&e_memory);
    long memory_taken=e_memory.ru_maxrss-s_memory.ru_maxrss;
    return memory_taken;
}
void test_case() {
    int arr[] = {54,78,5,10,4};
    int expected_arr[] = {4 ,5, 10 ,54, 78};
    insertion_sort(arr,5);
    for(int i=0;i<5;i++){
        assert(arr[i]==expected_arr[i]);//
//The assert function in C is used for debugging purposes to verify that certain conditions hold true during program execution. If the condition provided to assert evaluates to false, the program will terminate and print an error message, which can help identify logical errors or invalid assumptions in the code.
    }
    
   
}

int main(){
    //test_case();
    srand(time(NULL));
    int s1=50;
    int *arr1=(int*)(malloc(sizeof(int)*s1));
    for(int i=0;i<s1;i++){
        arr1[i]=rand();
    }
    double t1=calculate_time(arr1,s1);
    int s2=100;
    int *arr2=(int*)(malloc(sizeof(int)*s2));
    for(int i=0;i<s2;i++){
        arr2[i]=rand();
    }
    double t2=calculate_time(arr2,s2);
    printf("%lf",t2/t1);
}