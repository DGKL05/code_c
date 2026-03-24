#include<unistd.h>
#include<stdio.h>
main()
{  
    int p1,p2,i;
    while ((p1=fork())==-1);                /*创建子进程p1*/
    if (p1==0){                            /*子进程1创建成功*/
        lockf(1,1,0);
        for (i=0;i<50;i++)  printf("son%d\n",i);
        lockf(1,0,0);  
    }
    else{ 
        while ((p2=fork())==-1);              /*创建子进程p2*/
        if (p2==0){                          /*子进程2创建成功*/
            lockf(1,1,0);  
            for (i=0;i<50;i++)  
                printf("daughter%d\n",i); 
            lockf(1,0,0);  
        } else{  
            lockf(1,1,0);
            for (i=0;i<50;i++)  
                printf("children%d\n",i);   
            lockf(1,0,0);  
        }
   }
}//B1
