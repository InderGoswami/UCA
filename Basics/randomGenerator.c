#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//functions for generating random numbers are rand() and srand().
//srand() is used to seed rand() function 
//Initializes the random number generator with a seed value. It’s important to call srand() once at the start of your program 
//to ensure you get different sequences of random numbers each time you run the program.
int main(){
    srand(time(NULL));//The function time(NULL) in C is used to obtain the current calendar time. 
    //srand returns the current time as a time_t
    for(int i=0;i<10;i++){
        printf("%d " ,rand());//rand() function will generate random integers
    }
    return 0;
}
