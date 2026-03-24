#include<bits/stdc++.h>
using namespace std ;
using ll=long long;

void test(){
    int n ;
    cin >> n ;
    int flag = 0 ;
    for(int i = 1 ; i * i <= n ; i ++)
    {
        if(n % i == 0)
        {
            int j = n / i ;
            if(min(i , j) * 2 >= max(i , j))  flag = 1 ;
        }
    }
    cout << flag << '\n' ;
}

int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;
    int T ;
    cin >> T ;
    while(T --)
    {
        test();
    }
    return 0 ;
}