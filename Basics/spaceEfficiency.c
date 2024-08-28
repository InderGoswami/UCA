#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
//Use getrusage() to get the memory usage statistics before and after your code runs.
//int getrusage(int who, struct rusage *usage);
//who: Specifies which process's resource usage to obtain. It can be:
//RUSAGE_SELF: Resource usage of the current process.
//usage: A pointer to a struct rusage where the resource usage information will be stored.
int main(){
    struct rusage usage_s,usage_e;
    int status_s=getrusage(RUSAGE_SELF,&usage_s);//will find memory usage till this instance
    int *arr=(int*)malloc(sizeof(int)*100000);//dynamically allocation of memory and malloc will return a pointer
    int status_e=getrusage(RUSAGE_SELF,&usage_e);//will find memory usage till this instance
    // Calculate memory usage in kilobytes
    long memory_used = usage_e.ru_maxrss - usage_s.ru_maxrss;//ru_maxrss field in the struct rusage contains the maximum resident set size in kilobytes, which represents the amount of memory used by the program. 
    printf("Memory used by program is %ld kb \n",memory_used);
    free(arr);//deallocate memory given to arr
    return 0;
}
