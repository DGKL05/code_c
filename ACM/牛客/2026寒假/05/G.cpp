#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    string s1 = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int k = 0;
    string ans;
    int st = 0;
    for (char c : s1) {
        if(c == '0'){
            if(st == 0) ans+="3",st = 3;
            else if(st == 3) ans+="0",st=0;
            else if(st == 1) ans+="2",st=2;
            else ans+="1",st = 1;
        }else if(c == '1'){
            if(st == 0) ans+="0",st = 0;
            else if(st == 3) ans+="1",st=1;
            else if(st == 1) ans+="3",st=3;
            else ans+="2",st = 2;
        }else if(c == '2'){
            if(st == 0) ans+="1",st = 1;
            else if(st == 3) ans+="2",st=2;
            else if(st == 1) ans+="0",st=0;
            else ans+="3",st = 3;
        }else if(c == '3'){
            if(st == 0) ans+="2",st = 2;
            else if(st == 3) ans+="3",st=3;
            else if(st == 1) ans+="1",st=1;
            else ans+="0",st = 0;
        }else if(c == '4'){
            if(st == 0) ans+="1",st = 1;
            else if(st == 3) ans+="0",st=0;
            else if(st == 1) ans+="2",st=2;
            else ans+="3",st = 3;
        }else {
            if(st == 0) ans+="3",st = 3;
            else if(st == 3) ans+="2",st=2;
            else if(st == 1) ans+="0",st=0;
            else ans+="1",st = 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}