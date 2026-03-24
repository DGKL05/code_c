#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0 ;int s=0;
    cin >> n >> s;
    vector<int> v1(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        num += v1[i];
    }
    if (s < num) {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << v1[i];
        }
        cout << '\n';
    } else if (s == num) {
        cout << -1 << '\n';
    } else {
        if (s - num == 1) {
            int zero=0;int one=0;int tow=0;
            for (int x : v1) {
                if (x == 0) zero++;
                else if (x == 1) one++;
                else tow++;
            }
            for(int i=0;i<zero;i++) cout<<"0 ";
            for(int i=0;i<tow;i++) cout<<"2 ";
            for(int i=0;i<one;i++) cout<<"1 ";
            cout<<"\n";
        } else {
            cout << -1 << '\n';
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}