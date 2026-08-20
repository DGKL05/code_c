#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
// X.X...X...X...X.X.X.X...X.....X.X.X.X.X
// X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
// X.X...X.X.....X...X...X.X.X...X.X.X...X
// XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
vector<string>arr;
vector<vector<char>>ans;
int b=0;
void ins(string a,int h){
    int s1 = a.size();
    int idx=0;
    
    if(s1 == 15){
        for(int i=0;i<5;i++){
            for(int j=0;j<3;j++){
                ans[h+j][i] = a[idx++];
            } 
            // cout<<"\n";
        }
    }else {
        for(int i=0;i<5;i++){
            ans[h][i] = '.';
            // cout<<'.';
        }
        // cout<<"\n";
    }
}

void test(){
    int n=0;
    cin>>n;
    string s1 = "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX";
    ans.resize(3*n + (n- 1));
    for(int i=0;i<(3*n + (n-1));i++){
        ans[i].resize(5);
    }
    string idx;
    cin>>idx;
    int h = 0;
    for(int i=0;i<n;i++){
        int num = idx[i] - '0';
        // cout<<num<<"\n";
        ins(arr[num],h);
        h+=3;
        if(i!=n-1) {
            ins(s1,h);
            h++;
        }
        
    }
    for(int j=0;j<5;j++){
        for(int i=0;i<(3*n + n -1);i++){
                cout<<ans[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    arr.resize(10);
    // cin>>T;
    arr[0] = "XXXX.XX.XX.XXXX";
    arr[1] = "..X..X..X..X..X";
    arr[2] = "XXX..XXXXX..XXX";
    arr[3] = "XXX..XXXX..XXXX";
    arr[4] = "X.XX.XXXX..X..X";
    arr[5] = "XXXX..XXX..XXXX";
    arr[6] = "XXXX..XXXX.XXXX";
    arr[7] = "XXX..X..X..X..X";
    arr[8] = "XXXX.XXXXX.XXXX";
    arr[9] = "XXXX.XXXX..XXXX";
    
    while(T--) test();
    return 0;
}