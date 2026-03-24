#include<unistd.h>
#include<stdio.h>
void  main()
{ printf("Before fork...\n");
  if (fork()==0)
    {  printf("Son\n");  }
  else
    {  printf("Father\n");  }
}//B
