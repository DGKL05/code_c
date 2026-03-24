#include<unistd.h>
#include<stdio.h>
main(){  
    int p1,p2;
    int i;
  while ((p1=fork())==-1);                /*创建子进程p1*/
  if (p1==0){                            /*子进程1创建成功*/
    for (i=0;i<5;i++) {
         printf("son%d\n",i);                /*输出5个字符串“son“*/
         sleep(1);         /*引入延迟，使输出更易阅读，时间单位为秒*/
   }
}
else
   { while ((p2=fork())==-1);              /*创建子进程p2*/
      if (p2==0) {                         /*子进程2创建成功*/
        for (i=0;i<5;i++) {
            printf("daughter%d\n",i);        /*输出5个字符串“daughter“*/
            sleep(1);      /*引入延迟，使输出更易阅读*/
  }
 }  
 else{
        for (i=0;i<5;i++)                 /*父进程执行*/
             printf("children%d\n",i);         /*输出5个字符串“children“*/
             sleep(2);     /*引入延迟，使输出更易阅读*/
}
}
}//abcd
