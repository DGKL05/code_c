#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1;
    cin>>s1;
    string a = s1.substr(0,3);
    string b = s1.substr(3);
    int num1=0;int num2=0;
    for(int i=0;i<3;i++) num1+=a[i] - '0';
    for(int i=0;i<3;i++) num2+=b[i] - '0';
    if(num1 == num2){
        cout<<"You are lucky!\n";
    }else cout<<"Wish you good luck.\n";
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