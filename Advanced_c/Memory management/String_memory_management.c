#include<stdio.h>
int main(){
    char str1[]="Inder";//char array often stored in stack or heap
    str1[0]='i';//Char array is modified
    printf("%s \n",str1);
    char *str2="Aman";//str2 is pointer to string literal in read only data section of memeory
    //str2[0]='a'; //segmentation fault bcz str is pointer to string literal in data section which can not be modified 
    printf("%s \n",str2);
    
}