#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s;
    cin>>s;
    if(s=="0"){
        cout<<"10\n";
        return ;
    }
    if (s[0] == '-') {
        string t = s.substr(1);
        for (int i = 0; i < t.size(); i++) {
            if (t[i] > '1') {
                t.insert(i, "1");
                cout<<"-"<<t<<"\n";
                return;
            }
        }
        t += '1';
        cout << '-' << t << '\n';
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '1') {
                s.insert(i, "1");
                cout<<s<<"\n";
                return ;
            }
        }
        s += '1';
        cout << s << '\n';
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