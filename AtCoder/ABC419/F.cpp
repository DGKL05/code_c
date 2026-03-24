#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 105;   
const int sigma = 26;   
int ch[maxn][sigma];   
int mask[maxn];       
int fail[maxn];        
int trans[maxn][sigma]; 
int cnt;               
int dp[2][maxn][1 << 8]; 
void insert(string s, int idx) 
{
    int u = 0;
    for (char c_char : s) 
    {
        int c = c_char - 'a';
        if (!ch[u][c]) ch[u][c] = cnt++;
        u = ch[u][c];
    }
    mask[u] |= (1 << idx); 
}

void build_ac() 
{
    queue<int> q;
    for (int c = 0; c < sigma; c++) 
    {
        if (ch[0][c]) 
        {
            trans[0][c] = ch[0][c];
            q.push(ch[0][c]);
        }
    }
    while (!q.empty()) 
    {
        int u = q.front(); q.pop();
        mask[u] |= mask[fail[u]];
        for (int c = 0; c < sigma; c++) 
        {
            if (ch[u][c]) 
            {
                int v = ch[u][c];
                fail[v] = trans[fail[u]][c]; 
                trans[u][c] = v;          
                q.push(v);
            } 
            else trans[u][c] = trans[fail[u]][c]; 
        }
    }
}

int main() 
{
    int n, l; cin >> n >> l;
    vector<string> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    cnt = 1;
    memset(ch, 0, sizeof(ch));
    memset(mask, 0, sizeof(mask));
    memset(fail, 0, sizeof(fail));
    memset(trans, 0, sizeof(trans));
    for (int i = 0; i < n; i++) insert(S[i], i);
    build_ac();
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int cur = 0;
    for (int i = 0; i < l; i++) 
    {
        int nxt = cur ^ 1;
        memset(dp[nxt], 0, sizeof(dp[nxt])); 
        for (int j = 0; j < cnt; j++) 
        {
            for (int k = 0; k < (1 << n); k++) 
            {
                if (dp[cur][j][k] == 0) continue;
                for (int c = 0; c < sigma; c++) 
                {
                    int nj = trans[j][c]; 
                    int nk = k | mask[nj];
                    dp[nxt][nj][nk] = (dp[nxt][nj][nk] + dp[cur][j][k]) % mod;
                }
            }
        }
        cur = nxt; 
    }
    int ans = 0;
    for (int j = 0; j < cnt; j++) ans = (ans + dp[cur][j][(1 << n) - 1]) % mod;
    cout << ans << endl;
    return 0;
}