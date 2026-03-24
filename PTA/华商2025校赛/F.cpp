#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(vector<string> &v1){
    // for(auto x:v1) cout<<x<<" ";
    // cout<<"\n";
    if(v1[1] == "24" || v1[1] == "00" || v1[1] == "01" || v1[1] == "02"){
        return true;
    }else if(v1[1] == "23"){
        if(v1[3] == "00" && v1[2] == "00"){
            return false;
        }else return true;
    }else return false;
}
bool fa[1050][1050];

struct node{
    string a;
    string b;
};

void test()
{
    int n=0;
    cin>>n;
    string appID;
    string time;
    set<pair<int,int>>ste;
    int ans=0;
    vector<node>arr;
    set<string>s1;
    map<string,int>cnt;
    for(int i=0;i<n;i++){
        cin>>appID>>time;
        arr.push_back({appID,time});
    }
    for(int i=0;i<n;i++){
        // cin>>appID>>time;
        appID = arr[i].a;
        time = arr[i].b;
        vector<string>temp;
        string st;
        for(auto x:time){
            if(x == ':'){
                temp.push_back(st);
                st="";
            }else st+=x;
        }
        temp.push_back(st);
        st="";
        if(check(temp)) {
            int num = stoi(temp[0]);
            int d=0;
            if(temp[1] =="00" || temp[1] == "01" || temp[1] == "02"){
                d = num-1;
            }else {
                d=num+1;
            }
            int d1 = min(d,num);
            num = max(d,stoi(temp[0]));
            d1++;
            num++;
            if(fa[d1][num] == false){
                fa[d1][num] = true;
                ans++;
            }
            // s1.insert(appID);
            cnt[(appID)]++;
        }
    }
    if(ans == 0){
        cout<<"0\n#";
        return ;
    }
    int k=0;
    for(auto [l,r]:cnt){
        k = max(k , r);
    }
    cout<<ans<<"\n";
    for(auto [l,r] : cnt){
        if(r == k) s1.insert(l);
        // if(r == k) cout<<l<<" ";
    }
    
    auto it = s1.begin();
    while(it!=s1.end()){
        cout<<*it;
        it++;
        if(it!=s1.end()) cout<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) test();
    return 0;
}