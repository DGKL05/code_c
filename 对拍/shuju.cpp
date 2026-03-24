#include<bits/stdc++.h>
using namespace std;
using ll =long long;
/*
    rand() % 10 + 1; //1~10
    rand() % (100 - 33 + 1) + 33; //33~100
*/
void test()
{
    int a = rand()%100;
    int b = rand()%100;
    cout<<a<<" "<<b<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    _timeb T; _ftime(&T);
    srand(T.millitm); // 毫秒级随机种子
    int T1=1;
    // cin>>T;
    while(T1--) test(); 
    return 0;
}