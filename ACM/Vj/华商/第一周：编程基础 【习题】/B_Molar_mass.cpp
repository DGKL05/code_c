#include<bits/stdc++.h>
using namespace std;
using ll =long long;
map<char,double>m1;

void test()
{
    string s1;
    cin>>s1;
    int n = s1.size();
    char a = '1';
    double ans=0;
    string temp = "1";
    bool fa = false;
    for(int i=0;i<n;i++){
        if(m1.find(s1[i]) != m1.end()){
            if(i != 0) {
                // if(temp == "a") temp=1;
                if(temp.size() >= 2) temp = temp.substr(1);
                ans+=stoi(temp)*m1[a];
                // cout<<temp<<" "<<a<<"\n";
            }
            a = s1[i];
            temp = "1";
            fa = false;
        }else {
            // if(temp == "a") temp = "";
            fa = true;
            temp += s1[i];
        }
    }
    if(temp.size() >= 2) temp = temp.substr(1);
    ans+=stoi(temp)*m1[a];
    // cout << ans <<"\n";
    printf("%0.3lf\n",ans);
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    m1['C'] = 12.01;
    m1['H'] = 1.008;
    m1['O'] = 16.00;
    m1['N'] = 14.01;
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}