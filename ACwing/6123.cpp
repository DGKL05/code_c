#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;int f=0;
    cin>>n>>f;
    string s1;
    map<string,int>m1;
    map<string,int>m2;
    cin>>s1;
    for(int k=0;k<n-2;k++){
        if(s1[k]!=s1[k+1]&&s1[k+1]==s1[k+2]){
            string temp1=s1.substr(k,3);
            m1[temp1]++;
            //temp1.clear();
        }
    }
    for(int i=0;i<n;i++){
        
        for(int j=0;j<26;j++){
            vector<string>v2;
        for(int x=i-2,j=0;j<3;x++,j++){
            if(x>=n||x<0||x+2>=n) continue;
                string temp = s1.substr(x,3);
                if(m1.find(temp)!=m1.end()){
                    m1[temp]--;
                    auto it =m1.find(temp);
                    if(it->second==0){
                        m1.erase(it);
                    }
                    v2.push_back(temp);
                }
                // if(temp=="moo"){
                //     auto itt = m1.begin();
                //     while(itt!=m1.end()){
                //         cout<<itt->first<< " " <<itt->second<<" ";
                //         itt++;
                //     }
                // }
                //cout<<"\n";
        }
            char a='a';
            char temp = s1[i];
            a+=j;
            s1[i] = a ;
            vector<string>v1;
            for(int x=i-2,b=0;b<3;x++,b++){
                if(x>=n||x<0||x+2>=n) continue;
                if(s1[x]!=s1[x+1]&&s1[x+2]==s1[x+1]){
                    string temp = s1.substr(x,3);
                    m1[temp]++;
                    //if(temp=="moo") cout<<m1[temp]<<"\n";
                    v1.push_back(temp);
                }
            }
            //cout<<a<<"\n";
            s1[i]=temp;
            auto it=m1.begin();
            while(it!=m1.end()){
                if(it->second>=f){
                    m2[it->first]++;
                }
                it++;
            }
            for(auto x:v1){
                m1[x]--;
                auto it =m1.find(x);
                if(it->second==0){
                    m1.erase(it);
                }
            }
            //m1.clear();
            for(auto x:v2){
                m1[x]++;
            }
            v2.clear();
            v1.clear();
        }
    }
    cout<<m2.size()<<"\n";
    auto it=m2.begin();
    while(it!=m2.end()){
        cout<<it->first<<"\n";
        it++;
    }
    //return 0;
}