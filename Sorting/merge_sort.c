#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<assert.h>
void merge_2_sorted(int arr[],int aux[],int start,int mid,int end){
    for(int x=start;x<=end;x++){//store the required elements in temp array to use them in future
        aux[x]=arr[x];
    }
    int i=start;//starting of left part of array
    int j=mid+1;//starting of right part of array
    for(int x=start;x<=end;x++){
        if(i>mid){//all the elements of first part has already copied
            //Now only copy right part 
            arr[x]=aux[j++];
        }
        else if(j>end){
            //all elements of second part has already copied 
            //Now only copy left part
            arr[x]=aux[i++];
        }
        else if(aux[i]<=aux[j]){//current element of left part is smaller or equal than current element of right part
            arr[x]=aux[i++];
        }
        else{//current element of right part is smaller than current element of left part
            arr[x]=aux[j++];//else -> already sorted

        }
        
    }


}
void merge_sort_r(int arr[],int aux[],int start,int end){
    if(start==end){
        return;
    }
    int mid=(start+end)/2;
    merge_sort_r(arr,aux,start,mid);//sort the first left
    merge_sort_r(arr,aux,mid+1,end);//sort the second right
    merge_2_sorted(arr,aux,start,mid,end);

}
void merge_sort(int arr[],int n){
    //create an auxliary array of size n
    int *aux=(int*)malloc(n*sizeof(int));
    merge_sort_r(arr,aux,0,n-1);
    free(aux);//delete auxilary array
}
double calculate_time(int arr[],int n){
    clock_t s_time,e_time;
    double CPU_time;
    s_time=clock();
    merge_sort(arr,n);
    e_time=clock();
    CPU_time=(double)((e_time-s_time))/CLOCKS_PER_SEC;
    return CPU_time;


}
long calculate_memory(int arr[],int n){
    struct rusage s_memory,e_memory;
    int s1=getrusage(RUSAGE_SELF,&s_memory);
    merge_sort(arr,n);
    int s2=getrusage(RUSAGE_SELF,&e_memory);
    long memory_taken=e_memory.ru_maxrss-s_memory.ru_maxrss;
    return memory_taken;
}
void test_case() {
    int arr[] = {54,78,5,10,4};
    int expected_arr[] = {4 ,5, 10,54, 78};
    merge_sort(arr,5);
    for(int i=0;i<5;i++){
        assert(arr[i]==expected_arr[i]);//
//The assert function in C is used for debugging purposes to verify that certain conditions hold true during program execution. If the condition provided to assert evaluates to false, the program will terminate and print an error message, which can help identify logical errors or invalid assumptions in the code.
    }
    
   
}
int main(){
    test_case();
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