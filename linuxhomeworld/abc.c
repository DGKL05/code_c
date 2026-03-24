#include<unistd.h>
#include<stdio.h>
main()
{  int p1,p2;
  while ((p1=fork())==-1);                /*创建子进程p1*/
  if (p1==0)                            /*子进程1创建成功*/
    printf("BBB\t");
  else
  {  while ((p2=fork())==-1);              /*创建子进程p2*/
     if (p2==0)                          /*子进程2创建成功*/
       printf("CCC\t");
     else
       printf("AAA\t");  }                     /*父进程执行*/
}//abc
