#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
 
double num[maxn];
 
double f[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; i++)
        cin >>num[i];
        double sum = 0.0;
        sort(num, num+n);
        for(int i = n-1; i >= 2; i--)
        {
            if(num[i] >= num[i-1]+num[i-2]) continue;
            double p = (num[i]+num[i-1]+num[i-2])/2.0;
            sum += sqrt(p*(p-num[i])*(p-num[i-1])*(p-num[i-2]));
            i -= 2;
        }
        printf("%.2lf\n",sum);
    }
}