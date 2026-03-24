#include<bits/stdc++.h>
using namespace std;
using ll =long long;
string a1="Draw";string b1="chengwins";string c1="Hongwins";
int arr[3]={2,0,1};
void test()
{
    int a=0,b=0;
    cin>>a>>b;
    if(arr[a]==b){
        cout<<b1<<"\n";
        return ;
    }
    if(arr[b]==a){
        cout<<c1<<"\n";
        return ;
    }else {
        cout<<a1<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}