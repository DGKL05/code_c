#include<unistd.h>
#include<stdio.h>
void  main()
{ printf("Before fork...");
  if (fork()==0)
    {  printf("Son\n");  }
  else
    {  printf("Father\n");  }
}//A
