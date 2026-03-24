#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int l =1e7;
#define N 200005
 
int n,mid,m;
long long k,ans,mx1,mx2;
 
struct Node
{
	int val,b;
}a[N],c[N];
 
long long max(long long x,long long y) { return x > y ? x : y ; }
 
int cmp(Node x,Node y) { return x.val < y.val ; }
 
int check(int x)
{
	int tmp = m - mid + 1;
	int fl = m;
	for (int i = m; i ;-- i)
		if(c[i].val >= x) -- tmp,fl = i - 1;
		else break;
	if(tmp <= 0) return 1;
	int now = k;
	for (int i = fl; i ;-- i)
	{
		if(c[i].b) now -= x - c[i].val,-- tmp;
		if(now <= 0 || tmp <= 0) break;
	}
	if(now < 0) return 0;
	if(tmp <= 0) return 1;
	return 0;
}

void test()
{
    scanf("%d%lld",&n,&k),ans = a[n + 1].val = 0ll;
	mid = n / 2;
	for (int i = 1;i <= n;++ i)
	{
		scanf("%lld",&a[i].val);
		if(a[i].val >= mx1) mx2 = mx1,mx1 = a[i].val;
	}
	for (int i = 1;i <= n;++ i) scanf("%d",&a[i].b);
	sort(a + 1,a + n + 1,cmp);
	int bz = 0;
	for (int i = 1;i <= n;++ i)
		if(a[i].b)
		{
			int tp;
			if(i <= mid) tp = a[mid + 1].val;
			else tp = a[mid].val;
			ans = max(ans,a[i].val + k + tp);
		}else
		{
			bz = i;
		}
	if(bz)
	{
		m = 0;
		for (int i = 1;i <= n;++ i)
			if(i != bz) c[++ m].b = a[i].b,c[m].val = a[i].val;
		ans = max(ans,a[bz].val + c[mid].val);
		int l = c[mid].val;
		int r = 1e9;
		while (l <= r)
		{
			int md = (l + r) >> 1;
			if(check(md)) l = md + 1,ans = max(ans,a[bz].val + md);
			else r = md - 1;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
    int t=1;
    cin>>t;
    while(t--) test();
    return 0;
}