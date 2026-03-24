#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
typedef long long LL;
LL a[N],suml[N],sumr[N];
int main()
{
    int n,t;
    cin>>t;
    while (t -- )
    {
        cin>>n;
        int k=n/2+1;//贝爷的数量
        int l=n-k;//第二个人的数量
        //左方向前缀和
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            suml[i]=suml[i-1]+a[i];
        }
        //右方向前缀和
        for(int i=1;i<=n;i++)
        {
            int j=n-i+1;//实际坐标
            sumr[i]=sumr[i-1]+a[j];
        }
        //选取左右边共l个的最大数
        LL maxx=0;
        for(int i=0;i<=l;i++)
        {
            int j=l-i;
            maxx=max(suml[i]+sumr[j],maxx);
        }
        cout<<suml[n]-maxx<<" "<<maxx<<endl;

    }
    return 0;
}