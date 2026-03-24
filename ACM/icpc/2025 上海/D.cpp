#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll>arr;
int n;
string s1 = "10?";
vector<ll>pw;
map<string,ll>m1;
ll num;
multiset<ll>st;

ll dfs2(string ans,int n,int idx,ll ans1,ll res ){
    if(idx == n){
        ans1 += arr[res];
        m1[ans] = ans1;
        return ans1;
    }
    if(ans[idx] != '?'){
        res = res + 1LL*(ans[idx]-'0')*pw[idx];
        ans1 = dfs2(ans,n,idx+1,ans1,res);
    }else {
        string temp = ans;
        temp[idx] = '1';
        auto it = m1.find(temp);
        if(it!=m1.end()){
            ans1 += (it->second);
        }
        temp[idx] = '0';
        it = m1.find(temp);
        if(it!=m1.end()){
            ans1 += (it->second);
        }
        // cout<<ans1<<"\n";
        m1[ans] = ans1;
        return ans1;
    }
    // m1[ans] = res;
    return ans1;
}

void dfs1(int idx,string ans){
    if(idx == n){
        num ^= dfs2(ans,n,0,0,0);
        return ;
    }else { 
        for(int i=0;i<3;i++){
            string temp = ans;
            ans = ans+s1[i];
            dfs1(idx+1,ans);
            ans = temp;
        }
    }
}

void test() {
    int n;
    cin >> n;
    int total = 1 << n;
    vector<ll> arr(total);
    for(int i = 0; i < total; i++) {
        cin >> arr[i];
    }
    
    // 计算3的幂
    vector<int> pow3(n+1, 1);
    for(int i = 1; i <= n; i++) {
        pow3[i] = pow3[i-1] * 3;
    }
    
    // DP数组：dp[mask]表示模式mask对应的和
    vector<ll> dp(pow3[n], 0);
    ll result = 0;
    
    // 预处理：先处理所有不含'?'的模式
    for(int mask = 0; mask < total; mask++) {
        int state = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                state += pow3[i]; // '1'
            }
            // else: '0'，state保持不变
        }
        dp[state] = arr[mask];
    }

    for(int i = 0; i < n; i++) {
        for(int state = 0; state < pow3[n]; state++) {
            int digit = (state / pow3[i]) % 3;
            if(digit == 2) { // 如果当前位是'?'
                // '?' = '0' + '1'
                int state0 = state - 2 * pow3[i]; // 设为'0'
                int state1 = state - 1 * pow3[i]; // 设为'1'
                dp[state] = dp[state0] + dp[state1];
            }
        }
    }
    
    // 计算所有模式的异或和
    for(int state = 0; state < pow3[n]; state++) {
        result ^= dp[state];
    }
    
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}