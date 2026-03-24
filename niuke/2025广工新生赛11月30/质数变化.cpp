#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 10005;

int ans = -1;
string a,b;

bool is_prime[N];
set<int>s1;
void p(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) is_prime[i] = true;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
        if ((long long)i * i > n) continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
}
struct node {
    string temp;
    int val;
};

void bfs()
{
    queue<node>q1;
    q1.push({a,0});
    s1.insert(stoi(a));
    while(q1.size()){
        auto [ab,num] = q1.front();q1.pop();
        // cout<<ab<<"\n";
        if(stoi(ab) == stoi(b)) {
            ans = num ;
            return ;
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                string a1 = ab;
                // if(a1[i] == j + '0') continue;
                a1[i] = j + '0';
                int k = stoi(a1);
                if(s1.find(k) != s1.end()) continue;
                // cout<<k<<"\n";
                if(!is_prime[k]) continue;
                q1.push({a1,num+1});
                s1.insert(k);
                
            }
        }
    }
}

void test()
{
    ans = -1;
    s1.clear();
    cin>>a>>b;
    while(a.size() < 4){
        a = "0" + a;
    }
    bfs();
    cout<<ans<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    p(N);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
