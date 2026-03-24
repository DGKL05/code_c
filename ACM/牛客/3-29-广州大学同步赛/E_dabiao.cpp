#include<bits/stdc++.h>
using namespace std;
int arr[1000005];
bool f(int num){
    string s1;
    string s2=to_string(num);
    int n=s2.size();
    for(int i=0;i<n;i++){
        s1+=(i+'0');
    }
    do{
        string temp;
        for(int i=0;i<n;i++){
            temp+=s2[s1[i]-'0'];
        }
        int num1=stoi(temp);
        if(num%num1==0&&num!=num1) return true;
    }while(next_permutation(s1.begin(),s1.end()));
    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 1;i<=100000;++i){
        if(f(i)==true&&i%10!=0) cout<<i<<",";
    }

}