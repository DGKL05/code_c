#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n=0;
    cin>>n;
    //cout<<"n="<<n<<"\n";
    vector<int>arr(10,0);
    bool fa=true;
    int index=0;
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        arr[num]++;
        //cout<<num<<" "<<arr[num]<<"\n";
        if(arr[0]>=3&&arr[1]>=1&&arr[3]>=1&&arr[5]>=1&&arr[2]>=2&&fa) {
            //cout<<i+1<<"\n";
            //for(int j=0;j<10;j++) arr[j]=0;
            fa=false;
            index=i+1;
            //return ;
        }
    }
    cout<<index<<"\n";
}

int main()
{
    //std::ios::sync_with_stdio(0);
    //std::cin.tie(0);//std::cout.tie(0);
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}