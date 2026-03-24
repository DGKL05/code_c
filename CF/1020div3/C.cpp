#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int k=0;int max_a=0;int min_a=1e9;
    cin>>n>>k;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        max_a=max(max_a,a[i]);
        min_a=min(min_a,a[i]);
    }
    int n1=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(b[i]==-1) n1++;
    }
    if(n1!=n){
        ll num=0;
        for(int i=0;i<n;i++){
            if(b[i]!=-1){
                num=a[i]+b[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]!=-1&&(a[i]+b[i])!=num){
                cout<<"0\n";
                return ;
            }else{
                if((num-a[i])>k||(num-a[i])<0){
                    cout<<"0\n";
                    return ;
                }

            }
        }
        cout<<"1\n";
    }else{
        int ans=0;
        int low = 0, high = k;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((max_a + mid - min_a) <= k) {
                ans = mid + 1;  // mid 满足条件，累计到 mid+1 个
                low = mid + 1;  // 继续向右找更大的可能值
            } else {
                high = mid - 1; // 不满足条件，向左缩小范围
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}