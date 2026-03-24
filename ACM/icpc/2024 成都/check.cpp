#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int arr[100];
    int a=0;int b=0;int c=0;
    for(int i=0;i<100;i++){
        int num=0;
        cin>>num;
        if(num == 3) a++;
        else if( num == 95) b++;
        else if(num == 99) c++;
    }
    cout<<a<<" "<<b<<" "<<c<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}