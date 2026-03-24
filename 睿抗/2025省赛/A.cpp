#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    // int n=0;
    // cin>>n;
    int m=0;int d=0;int num=0;
    cin>>m>>d>>num;
    if(m<6){
        if(num>1800){
               cout<<"^_^\n";
               return ;
           }else if(num==1800){
               cout<<"Ok!\n";
               return ;
           }else {
               cout<<"Need more!\n";
               return ;
           }
    }
    if(m==6){
        if(d<=20){
            if(num>1800){
                cout<<"^_^\n";
                return ;
            }else if(num==1800){
                cout<<"Ok!\n";
                return ;
            }else {
                cout<<"Need more!\n";
                return ;
            }
        }else {
            if(num>2000){
                cout<<"^_^\n";
                return ;
            }else if(num==2000){
                cout<<"Ok!\n";
                return ;
            }else {
                cout<<"Need more!\n";
                return ;
            }
        }
    }else if(m==7){
        if(d<=11){
             if(num>2000){
                cout<<"^_^\n";
                return ;
            }else if(num==2000){
                cout<<"Ok!\n";
                return ;
            }else {
                cout<<"Need more!\n";
                return ;
            }
        }else cout<<"Too late!\n";
    }else cout<<"Too late!\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}