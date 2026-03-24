#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main()
{
    string s1;
    cin>>s1;
    string s2 = s1;
    reverse(s1.begin(),s1.end());
    if(s1 == s2) cout<<"Y\n";
    else cout<<"N\n";
    return 0;
}