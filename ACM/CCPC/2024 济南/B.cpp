#include<bits/stdc++.h>
using namespace std;

#define int long long

int T=1;

void test()
{
    int n=0;
    cin>>n;
    map<char,int>m1;
    map<char,int>p;
    p['C']=2;
    p['D']=1;
    p['H']=3;
    p['S']=4;
    m1['C']=0;m1['D']=0;m1['H']=0;m1['S']=0;
    for(int i=1;i<=13;i++){
        if(i == 1){
            p['A']=1;
        }else if(i == 10){
            p['T']=10;
        }else if(i ==11){
            p['J']=11;
        }else if(i==12){
            p['Q']=12;
        }else if(i == 13){
            p['K']=13;
        }else {
            p[i+'0']=i;
        }
    }
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        int num = p[s1[0]];
        char a=s1[1];
        // cout<<num<<" "<<a<<"\n";
        m1[a]++;
    }
    vector<int>op(6);
    for(int i=0;i<6;i++) {
        cin>>op[i];
        // cout<<op[i]<<" ";
    }
    int ans=0;int temp=0;
    for(auto &[l,r] : m1){
        // cout<<l<<" "<<r<<"\n";
        ans+= r/5;
        r%=5;
        temp+=r;
    }
    auto it=m1.begin();
    for(int i=0;i<4;i++){
        if(temp<5){
            break;
        }
        if(op[ p[(it->first)]-1 ]!=0 && (it->second)>=2 ){
            op[ p[(it->first)]-1 ]=0;
            temp-=5;
            ans++;
            it->second=0;
        }
        it++;
    }
    if(temp<5){
        // cout<<"T = "<<T<<" ";
        cout<<ans<<"\n";
        return ;
    }
    for(auto &[l,r] : m1){
        if(op[ p[(l)]-1 ]!=0){
            r+=3;
        }
        // cout<<l<<" "<<op[ p[(l)]-1 ]<<" "<<r<<"\n";
        if(r==3 &&(op[4]!=0 && op[5]!=0)){
            // ans++;
            cout<<ans+1<<"\n";
            return ;
        }else if(r==4 && (op[4]!=0 || op[5]!=0)){
            cout<<ans+1<<"\n";
            return ;
        }
        if(op[ p[(l)]-1 ]!=0){
            r-=3;
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    
    cin>>T;
    while(T--) test(); 
    return 0;
}