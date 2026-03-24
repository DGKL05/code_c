#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1 = "he,allcornetrrwecaneacheveryGreatWintheworldAcross";
    string s2 = "he,wecanreacycornerdGreatWallintheworlAcrosshevert";
    cout<<s1.size()<<" "<<s2.size()<<"\n";
    for(int i=10;i<=18;i++){
        cout<<s2[i-1];
    }cout<<"\n";
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