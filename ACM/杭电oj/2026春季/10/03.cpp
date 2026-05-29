#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(bool has[4][4])
{
    for(int i = 1;i <= 3;i++){
        if(has[i][1] && has[i][2] && has[i][3]) return true;
        if(has[1][i] && has[2][i] && has[3][i]) return true;
    }

    if(has[1][1] && has[2][2] && has[3][3]) return true;
    if(has[1][3] && has[2][2] && has[3][1]) return true;

    return false;
}

void test()
{
    int n;
    cin>>n;

    vector<pair<int,int>> mine(n);
    int board[4][4] = {};

    for(int i = 0;i < n;i++){
        int r,c;
        cin>>r>>c;
        mine[i] = {r,c};
        board[r][c] = 1;
    }

    for(int i = 0;i < n;i++){
        int r,c;
        cin>>r>>c;
        board[r][c] = 2;
    }

    if(n < 2){
        cout << "Columbina Hyposelenia\n";
        return;
    }

    for(int r = 1;r <= 3;r++){
        for(int c = 1;c <= 3;c++){
            if(board[r][c] != 0) continue;

            bool has[4][4] = {};

            for(auto [x,y] : mine){
                has[x][y] = true;
            }

            if(n == 3){
                has[mine[0].first][mine[0].second] = false;
            }

            has[r][c] = true;

            if(check(has)){
                cout << r << ' ' << c << '\n';
                return;
            }
        }
    }

    cout << "Columbina Hyposelenia\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--) test() ;
    return 0;
}