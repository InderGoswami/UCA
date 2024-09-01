#include<stdio.h>
void function(int x){
    printf("%d \n",x);
}
double add_d(double x,double y){
    return x+y;
}
int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){
    return a/b;
}
void performOperation(int(*operation)(int,int),int a,int b){
    //reference to function whom to perform will be sent
    int result=operation(a,b);//function with pointer operation is called with arguments
    printf("%d",result);

}
int main(){
    //declare the function pointer
    //void (*function_pointer)(int);
    //return_type pointer_name arguments
    //assign address of function to function_pointer
    //function_pointer=&function;//function_pointer will store address of function
    //(*function_pointer)(4);//defrence function pointer and access the function and call it with given arguments
    //double(*function_pointer2)(double,double);
    //function_pointer2=&add;
   
    //printf("%lf \n",(function_pointer2)(4.2,78));

    //function(5);
    performOperation(add,12,54);//we are passing refernce to add function here
    return 0;
}