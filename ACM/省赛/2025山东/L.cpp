#include<bits/stdc++.h>
using namespace std;
using ll =long long;
//O、B、A、F、G、K、M
void test()
{
    string s1;string s2;
    cin>>s1>>s2;
    map<char,int>m1;
    m1['O'] = 1;
    m1['B'] = 2;
    m1['A'] = 3;
    m1['F'] = 4;
    m1['G'] = 5;
    m1['K'] = 6;
    m1['M'] = 7;
    int a = m1.find(s1[0])->second;
    int b = m1.find(s2[0])->second;
    // cout<<"a = "<<a<<" b = "<<b<<"\n";
    if(a == b){
        a = s1[1] - '0';
        b = s2[1] - '0';
        if(a > b){
            cout<<"cooler\n";
        }else if(a == b){
            cout<<"same\n";
        }else cout<<"hotter\n";
    }else if(a < b){
        cout<<"hotter\n";
    }else cout<<"cooler\n";
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}