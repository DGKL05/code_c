#include<bits/stdc++.h>
using namespace std;
using ll =long long;

struct node{
    string name;
    char timu;
    int time;
    string und;
};

struct team{
    int num;
    int time;
    int arr[26];
    bool fa[26]={false};
    vector<node>v1;//存uk
};

struct team1{
    string name;
    int num;
    int time;
};

bool cmp1(node &a,node &b){
    if(a.time==b.time) return a.name>b.name;
    return a.time<b.time;
}

bool cmp2(team1 &a, team1 &b){
    if(a.num==b.num) return a.time<b.time;
    else return a.num>b.num;
}

void test()
{
    int n=0;
    cin>>n;
    vector<node>arr(n);
    unordered_map<string,team>m1;
    for(int i=0;i<n;i++){
        string name;
        char a;
        int time;
        string und;
        cin>>name>>a>>time>>und;
        arr[i]={name,a,time,und};
    }
    sort(arr.begin(),arr.end(),cmp1);
    for(auto x:arr){
        char a1=x.und[0];
        char a=x.timu;
        if(a1=='A'&&m1[x.name].fa[a-'A']==false){
            m1[x.name].num++;
            m1[x.name].arr[a-'A']++;
            m1[x.name].time=(m1[x.name].arr[a-'A']-1)*20+x.time+m1[x.name].time;
            m1[x.name].fa[a-'A']=true;
        }else if(a1=='R'){
            m1[x.name].arr[a-'A']++;
        }else {
            m1[x.name].v1.push_back(x);
        }
    }
    vector<team1>v1;
    for(auto [l,r] : m1) {
        team1 a;
        a.name=l;
        a.num=r.num;
        a.time=r.time;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end(),cmp2);
    vector<string>ans;
    ans.push_back(v1[0].name);
    int num=v1[0].num;
    int min_time=v1[0].time;

    for(auto x:m1){
        if(x.first==ans[0]) continue;
        int ans_num=x.second.num;
        int ans_time=x.second.time;
        for(auto k:x.second.v1){
            string name = k.name;
            char a=k.timu;
            int time=k.time;
            // cout<<a<<" "<<time<<" "<<name<<"\n";
            if(x.second.fa[a-'A'] == true) continue;
            x.second.arr[a-'A']++;
            ans_num++;
            ans_time+=(x.second.arr[a-'A']-1)*20+time;
            x.second.fa[a-'A']=true;
            // cout<<"2 : "<<a<<" "<<time<<" "<<name<<"\n";
        }
        if(ans_num>num){
            // cout<<x.first<<" ";
            ans.push_back(x.first);
        }else if(ans_num==num){
            if(ans_time<=min_time){
                // cout<<x.first<<" ";
                ans.push_back(x.first);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}