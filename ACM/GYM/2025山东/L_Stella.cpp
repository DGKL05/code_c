#include<bits/stdc++.h>
using namespace std;
using ll =long long;
map<char,int>m1;
void test()
{
    string s1;string s2;
    cin>>s1>>s2;
    if(s1==s2) {
        cout<<"same\n";
        return  ;
    }
    if(m1.find(s1[0])->second>m1.find(s2[0])->second){
        cout<<"hotter\n";
    }else if(m1.find(s1[0])->second==m1.find(s2[0])->second){
        if((s1[1]-'0')<(s2[1]-'0')){
            cout<<"hotter\n";
        }else{
            cout<<"cooler\n";
        }
    }else{
        cout<<"cooler\n";
    }
}

int main()
{
    m1.insert(pair<int,int>('O',9));
    m1.insert(pair<int,int>('B',8));
    m1.insert(pair<int,int>('A',7));
    m1.insert(pair<int,int>('F',6));
    m1.insert(pair<int,int>('G',5));
    m1.insert(pair<int,int>('K',4));
    m1.insert(pair<int,int>('M',3));
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}