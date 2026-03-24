#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int N=0;
    cin >> N;
    vector<ll> R(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i];
    }

    ll minR = *min_element(R.begin(), R.end());
    ll maxR = *max_element(R.begin(), R.end());
    ll minC = *min_element(C.begin(), C.end());
    ll maxC = *max_element(C.begin(), C.end());

    ll dx = maxR - minR;
    ll dy = maxC - minC;
    ll d = max(dx, dy);
    ll ans = (d + 1) / 2;

    cout << ans << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}