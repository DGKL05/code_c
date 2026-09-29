#include<bits/stdc++.h> 
 
using namespace std; 
using ll = long long; 
 
void test(){ 
    ll n; 
    cin>>n; 
    if(n%2){ 
        cout<<-1<<"\n"; 
        return; 
    } 
    ll a = 1; 
    ll b = -1; 
    ll c = n/2; 
 
    cout<<a<<" "<<b<<" "<<c<<"\n"; 
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