#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    vector<ll>arr(n,0);
    for(auto &x:arr) cin>>x;
    sort(arr.begin() , arr.end());
    vector<ll>ans;
    vector<bool>arrfa(n,false);
    map<ll,queue<int>>m1;
    bool fa = true;
    for(int i=n-1;i>=0;i--){
        // if(arr[i] == arr[n-1]) continue;
        m1[arr[i]].push(i);
    }
    for(int i=n-2;i>=0;i--){
        if(arrfa[i] || arr[i] == arr[n-1]) continue;
        // cout<<" de = "<<arr[n-1] - arr[i]<<"\n";
        if(m1.find(arr[n-1] - arr[i]) == m1.end() || m1.find(arr[n-1] - arr[i])->second.size() <= 0){
            fa = false;
            break;
        }else{
            if(arr[n-1] - arr[i] == arr[i]){
                if(m1.find(arr[n-1] - arr[i])->second.size() >= 2){
                    int idx = m1[arr[i]].front();
                    arrfa[idx] = true;
                    m1[arr[i]].pop();
                    idx = m1[arr[i]].front();
                    arrfa[idx] = true;
                    m1[arr[i]].pop();
                }else {
                    fa = false;
                }
            }else{
                int idx = m1[arr[i]].front();
                arrfa[idx] = true;
                m1[arr[i]].pop();
                idx = m1[arr[n-1] - arr[i]].front();
                arrfa[idx] = true;
                m1[arr[n-1] - arr[i]].pop();
            }
        }
    }
    bool fa1 = true;
    if(n&1){
        fa1 = false;
    }else {
        int i=0;int j=n-1;
        ll num = arr[j] + arr[i];
        j--;
        i++; 
        // cout<<i<<" "<<j<<"\n";
        while(j >= i){
            // cout<<i<<" "<<j<<"\n";
            if(arr[j] + arr[i] != num){
                fa1 = false;
                break;
            }
            j--;i++;
        }
    }
    if(!fa && !fa1) {
        cout<<"-1\n";
        return ;
    }
    if(fa) cout<< arr[n-1] <<" ";
    if(fa1) cout<< arr[n-1] + arr[0] <<" ";
    cout<<"\n";
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}