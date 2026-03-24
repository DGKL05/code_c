#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    map<string,int>m1;
    for(int i=0;i<n;i++){
        string s1;
        cin>>s1;
        m1[s1]=0;
    }
    int m=0;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        auto it=m1.find(s);
        if(it==m1.end()){
            cout<<"WRONG\n";
        }else if((it->second)!=0){
            cout<<"REPEAT\n";
        }else{
            cout<<"OK\n";
            it->second++;
        }
    }
	return 0;
}
