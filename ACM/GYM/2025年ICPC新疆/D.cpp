#include<bits/stdc++.h>
using namespace std;
using ll =long long;


void test()
{
    string s, t;
    cin >> s >> t;
    string s1, s2, t1, t2;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '/') {
            s1 = s.substr(0, i);
            s2 = s.substr(i + 1, s.size() - i);
        }
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '/') {
            t1 = t.substr(0, i);
            t2 = t.substr(i + 1, t.size() - i);
        }
    vector<int> ve1(10, 0), ve2(10, 0);
    int yes = 3, p = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == t1[p])
            p++;
        else
            ve1[s1[i] - '0']++;
    }
    int p2 = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == t2[p2])
            p2++;
        else
            ve2[s2[i] - '0']++;
    }
    if (p == t1.size() && p2 == t2.size() && ve1 == ve2) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}
