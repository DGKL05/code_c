//testFork.c
#include<stdio.h>
#include<unistd.h>
int main() 
{ 
    int count=1;
    int child;
    if(!(child=fork()))  //!是逻辑非运算，!(child=fork())当child=fork()的值为0时，! (child=fork()) 的值为1。
      printf("This is son, his count is: %d. and his pid is: %d\n", ++count, getpid());
    else 
      printf("This is father, his count is: %d, his pid is: %d\n", count, getpid());
}
