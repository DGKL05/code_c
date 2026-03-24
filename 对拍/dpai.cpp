#include<bits/stdc++.h>
using namespace std;
using ll =long long;

/*
    _timeb T; _ftime(&T);
    srand(T.millitm);
    rand() % 10 + 1; //1~10
    rand() % (100 - 33 + 1) + 33; //33~100
*/

void test()
{
    int t=0;
    do{
        system("shuju.exe > shuju.txt && A.exe < shuju.txt > A.txt && baoli.exe < shuju.txt > baoli.txt");
        cout<<"AC : "<<++t<<"\n";
    }while(!system("fc A.txt baoli.txt > nul"));

    cout<<"=== fined WA_in stop === \n";
    cout<<"========= in.txt =========\n";
    system("TYPE shuju.txt");
    cout<<"========= baoli.out =======\n";
    system("TYPE baoli.txt");
    cout<<"========= A.out =======\n";
    system("TYPE A.txt");
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test(); 
    return 0;
}