#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int f(int x,int y,int x1,int y1){
    return max(abs(x-x1),abs(y-y1));
}

void test(){
    int n = 0;
    cin>>n;
    if(n == 1){
        cout<<"11\n";
    }else if(n == 2){
        cout<<"22\n";
    }else if(n == 3){
        cout<<"222\n";
    }else if(n == 0){
        cout<<"1\n";
    }else {
        cout<<"-1\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}