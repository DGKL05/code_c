#include<bits/stdc++.h>
using namespace std;
using ll =long long;

const int N = 1e6+5,inf = 0x3f3f3f3f;
ll ini=0;
ll sum[26][26];
ll nent[N][26];
struct Trie{
    ll net[1000005][26];
    ll cnt = 1;
    // bool exit[1000005];

    void insert(string s1){
        int n = s1.size();
        // cout<<n<<"\n";
        int p=0;
        for(int i=0;i<n;i++){
            int c = s1[i] - 'a';
            if(!net[p][c]) net[p][c] = cnt++;
            for(int j=0;j<26;j++){
                if(j == c) continue;
                sum[c][j]+=nent[p][j];
            }
            ++nent[p][c];
            p=net[p][c];
        }
        // exit[p]=true;
        for(int j=0;j<26;j++){
            // sum[p][j]+=net[p][c];
            ini+=nent[p][j];
        }
    }

    // bool find(string s1){
    //     int n = s1.size();
    //     int p = 0;
    //     for(int i=0;i<n;i++){
    //         int c = s1[i] - 'a';
    //         if(!net[p][c]) return false;
    //         p = net[p][c];
    //     }
    //     return exit[p];
    // }
};

void test()
{
    Trie *trie = new Trie;
    int n=0;int m=0;
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        string x;
        arr[i]=x;
        cin>>x;
        trie->insert(x);
    }
    // cout<<n<<" "<<m<<"\n";
    while(m--){
        string pos;
        cin>>pos;
        ll ans=ini;
        // cout<<ans<<"\n";
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                ans+=sum[pos[i] - 'a'][pos[j] - 'a'];
            }
        }
        cout<<ans<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}