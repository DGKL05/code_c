#include<bits/stdc++.h>
using namespace std;
using ll =unsigned long long;
int a=0;string n;ll ans;
string s1;
void intToA(string &sk,int radix)
{
    ll n2 = stoll(sk);
    string str_ans="";
    do{
        ll t=n2%radix;
        if(t>=0&&t<=9) str_ans+=(t+'0');
        else str_ans+=(t-10+'a');
        n2/=radix;
    }while(n2!=0);  
    string temp = str_ans;
    reverse(str_ans.begin(),str_ans.end());
    if(temp == str_ans) ans+=stoll(sk);
    else return ;
    // cout<<sk<<"\n";
}

void dfs(int idx, int n1, bool tight_left) {
    if (idx == (n1 + 1) / 2) {
        if (n1 == n.size() && s1 > n) return;
        if (n1 > 1 && s1[0] == '0') return;
        intToA(s1,a);
        return;
    }

    
    int start = (idx == 0) ? 1 : 0; 
    int current_digit = 9; 
    
    
    if (tight_left && n1 == n.size()) {
        current_digit = n[idx] - '0';
    }

    for (int j = start; j <= current_digit; j++) {
        
        s1[idx] = j + '0';
        s1[n1 - idx - 1] = j + '0';
        
        
        bool new_tight_left = tight_left && (n1 == n.size()) && (j == (n[idx] - '0'));
        
        
        dfs(idx + 1, n1, new_tight_left);
    }
}

void test()
{
    cin>>a>>n;
    int n1=n.size();
    int max_len = n.size();
    for(int i=0;i<n1;i++) s1+="#";
    for (int L = 1; L <= max_len; L++) {
        s1 = string(L, '#'); 
        dfs(0, L, L == max_len); 
    }
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}