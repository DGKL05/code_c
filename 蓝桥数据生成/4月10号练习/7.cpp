#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int check(int num,int n)
{
    int k=pow(num,3);
    if(k==n) return 1;
    if(k>n) return 3;
    else return 2;
}

void test()
{
    int n=0;
    cin>>n;
    int l=0;int r=n;
    int k=0;
    bool fa=false;
    while(l<=r){
        //cout<<(l+r)/2<<'\n';
        k=(l+r)/2;
        int num=check((l+r)/2,n);
        if(num==1){ cout<<(l+r)/2<<".000\n";fa=true;}
        if(num==2){
            l=(l+r)/2+1;
        }else r=(l+r)/2-1;
    }
    if(!fa){
        int l1=0;int r1=1000;
        int ans=0;
        if(pow(k,3)>n) {
           ans=k-1;
        }else {
            ans=k+1;
        }
        // int kk=0;
        while(l1<=r1){
            int mid=((l1/2)+(r1/2));
            float num1=ans+(float)mid/1000;
            //cout<<(float)mid<<"\n";
            float num=(float)pow(num1,3);
            // cout<<(float)num<<"\n";
            //kk++;
            if((int)num == n){
                cout <<fixed <<setprecision(3) << num1 <<"\n";
                break;
            }else if(num<n){
                l1=mid+1;
            }else {
                r1=mid-1;
            }
        }
    }
   
}

int main()
{
    //cout<<(float)599/1000<<"\n";
    //cout<<(1+1)/2<<"\n";
    int t=0;
    cin>>t;
    while(t--) test();
    return 0;
}