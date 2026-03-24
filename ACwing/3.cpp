#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn  100
#define INF 0X3F3F3F3F
int a[maxn][maxn];
int f[maxn];
int pre[maxn];
using namespace std;
int main(){
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
    memset(pre,0,sizeof(pre));
	for(int i = 1 ;i <= n; i++) //输出各城市之间距离
	 	for(int j = 1; j <= n; j++)
	  		scanf("%d", &a[i][j]);
	  for(int i = 1; i <= maxn; i++)
	  	f[i] = INF;//默认初值都是0X3F3F3F3F
	f[n] = 0;
	for(int i = n-1 ;i >=1;i--)//从终点往前逆推，计算最短路径
		for(int j= i+1;j <= n;j++)
		{
			if(a[i][j] > 0 && f[j] != INF && f[i] >a[i][j] + f[j])//INF表x->终点城市不通
			{
				f[i] = f[j] + a[i][j];//城市i到终点最短路径值
				pre[i] = j;
			}
		}	
	printf("minlong=%d\n",f[1]);//输出最短路径值
	int k = 1;
    int kk = 1;
	while(k != 0)//输出路过的各个城市
 	{
		//printf("%d ",k);
        if(k!=0) printf("%d ",a[kk][k]);
        kk = k;
		k = pre[k];
	}	
	//printf("\n");
	return 0;
}
