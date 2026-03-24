#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n=0;int m=0;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<string>arr;

int stx,sty,enx,eny;

struct node{
    int x;int y;
};

vector<node>ans;
bool fa[105][105];

void check(int idx,int idy)
{
    int temp = 0;
    for(int i=0;i<4;i++){
        int x = idx+dx[i];
        int y = idy+dy[i];
        if(x >= n || x < 0 || y >= m || y < 0 ) {
            temp++;
            continue;
        }
        if(arr[x][y] == '#') temp++;
        // if(arr[x][y] == 'S' || arr[x][y] == 'E') return;
    }
    if(temp >= 3) arr[idx][idy] = '#';
}

void test()
{
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        arr[i] = s1;
        int n1 = s1.size();
        for(int j=0;j<n1;j++){
            char x = s1[j];
            if(x == 'S'){
                stx = i;
                sty = j;
            }
            if(x == 'E'){
                enx = i;
                eny = j;
            }
        }
    }
    int old_k = 0;
    int new_k = -1;
    for(int k=0;k<n*m && new_k != 0;k++){
        new_k = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 'S' || arr[i][j] == 'E' || arr[i][j] == '#') continue;
                check(i,j);
                if(arr[i][j] == '#') new_k++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1) cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}