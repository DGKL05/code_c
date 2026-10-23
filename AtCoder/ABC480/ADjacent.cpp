#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void test(){
    vector<string>arr(2);
    for(int i=0;i<2;i++) cin>>arr[i];
    bool fa = false;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(arr[i][j] == 'A'){
                //check 
                
                int dx = i;int dy = j;
                dx++;
                // if(dx<0 || dx >=2 || dy < 0 || dy >=2) continue;
                if( !(dx<0 || dx >=2 || dy < 0 || dy >=2) && arr[dx][dy] == 'D') {
                    fa = true;
                    break;
                }
                dx-=2;
                if( !(dx<0 || dx >=2 || dy < 0 || dy >=2) && arr[dx][dy] == 'D') {
                    fa = true;
                    break;
                }
                dx++;dy++;
                if( !(dx<0 || dx >=2 || dy < 0 || dy >=2) && arr[dx][dy] == 'D') {
                    fa = true;
                    break;
                }
                dy-=2;
                if( !(dx<0 || dx >=2 || dy < 0 || dy >=2) && arr[dx][dy] == 'D') {
                    fa = true;
                    break;
                }
            }
        }
    }
    cout<< (fa == true ? "Yes\n" : "No\n"); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}