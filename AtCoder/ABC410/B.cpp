#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;int q=0;
    cin>>n>>q;
    vector<int>m1(n+1,0);
    for(int i=1;i<=q;i++){
        int num=0;
        cin>>num;
        if(num!=0){
           cout<<num<<" ";
           m1[num]++;
        }else {
            int temp = 1e8;int index=-1;
            for(int j=1;j<=n;j++){                
                if(m1[j] < temp){
                    temp=m1[j];
                    index=j;
                }
            }
            cout<<index<<" ";
            m1[index]++;
        }
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