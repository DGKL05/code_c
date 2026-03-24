#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int n;
vector<int>arr;


void test()
{
    cin>>n;
    vector<int> A(n);
    for (auto&& a : A) {
        cin >> a;
        --a; 
    }

    vector<int> ans(n);
    for (int i : views::iota(0, n) | views::reverse) { 
        if (i == A[i]) { 
            ans[i] = i;
        } else { 
            ans[i] = ans[A[i]]; 
        }
    }

    for (int a : ans) {
        cout << a + 1 << " ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}