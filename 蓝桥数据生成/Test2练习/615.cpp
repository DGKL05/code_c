#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int n;
    while (cin>>n)
    {
        cout<<bitset<8>(n);
        int x;
        cin>>x;
        cout<<bitset<8>(x)<<endl;
    }
    
    //cout<<9*9*9*9*9*9*9*9*9;
    return 0;
}