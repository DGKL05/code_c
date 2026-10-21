#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT{
    int n;
    vector<ll>tr;

    BIT(int n):n(n),tr(n+1,0){}

    int lowbit(int x){
        return x&-x;
    }

    void add(int x,ll v){
        for(int i=x;i<=n;i+=lowbit(i))
            tr[i]+=v;
    }

    ll query(int x){
        ll res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=tr[i];
        return res;
    }

    ll query(int l,int r){
        return query(r)-query(l-1);
    }

    void update(int x,ll v){
        add(x,v-query(x,x));
    }
};

void test(){
    int n;
    ll k;
    cin>>n>>k;
    BIT bit(n+1);
    vector<int>arr(n);
    vector<int>cnt(n+1,0);
    for(int i=0;i<n;i++) cin>>arr[i];

    if(k>=n){
        cout<<n<<"\n";
        return;
    }

    int ans=0;
    int j=0;
    int met=0;
    for(int i=0;i<n;i++){
        if(i>0 && i-1<j){
            int x=arr[i-1];
            cnt[x]--;
            if(cnt[x]==0){
                bit.update(x+1,0);
                met=min(met,x);
            }
        }
        j=max(j,i);
        while(j<n){
            int x=arr[j];
            cnt[x]++;
            if(cnt[x]==1){
                bit.update(x+1,1);
                if(x==met){
                    int l=met,r=n+1;
                    while(l<r){
                        int mid=(l+r+1)/2;
                        if(bit.query(mid)==mid)
                            l=mid;
                        else
                            r=mid-1;
                    }
                    met=l;
                }
            }
            if(met>k){
                cnt[x]--;
                if(cnt[x]==0){
                    bit.update(x+1,0);
                    met=min(met,x);
                }
                break;
            }
            ans=max(ans,j-i+1);
            j++;
        }
    }

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    cin>>T;
    while(T--) test();
    return 0;
}
