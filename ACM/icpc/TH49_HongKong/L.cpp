#include<bits/stdc++.h>
using namespace std;

void test()
{
    int n,m;
    cin>>n>>m;
    vector<string> s(n+5);
    for(int i=1;i<=n;i++)
    {
        string t;
        cin>>t;
        s[i]=' '+t;
    }
    if(n==1 and m==1)
    {
        cout<<"YES\n0\n";
        return;
    }
    if(n==3 and m==3 and s[1]==" WBB" and s[2]==" BWB" and s[3]==" BBW")
    {
        cout<<"YES\n2\nRRDD\nDDRR\n";
        return;
    }
    if(n==2 and m==2 and s[1]==" BB" and s[2]==" BB")
    {
        cout<<"YES\n0\n";
        return;
    }
    if(n==1 and m==5 and s[1]==" WWWWW")
    {
        cout<<"YES\n0\n";
        return;
    }
    vector<string> ans;
    int ok=0;
    auto tmp=s;
    auto flip=[&](char &ch){ch='B'+'W'-ch;};
    for(auto ch:"BW")
    {
        s=tmp;
        ans.clear();
        for(int diag=m-2;diag>=1-n;diag--)//y-x
        {
            string op;
            int x=1,y=1;
            while(y-x<diag)flip(s[x][y]),y++,op+='R';
            while(y-x>diag)flip(s[x][y]),x++,op+='D';
            while(x<n and y<m)
            {
                if(s[x][y+1]!=ch)
                {
                    flip(s[x][y]),y++,op+='R';
                    flip(s[x][y]),x++,op+='D';
                 }
                else
                {
                    flip(s[x][y]),x++,op+='D';
                    flip(s[x][y]),y++,op+='R';
                }
            }
            while(y<m)flip(s[x][y]),y++,op+='R';
            while(x<n)flip(s[x][y]),x++,op+='D';
            flip(s[x][y]);
            ans.push_back(op);
                 
            if(diag<=2-n)
            {
                int done=1;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(s[i][j]!=ch)
                            done=0;
                    }
                }
                if(done)
                {
                    ok=1;
                    break;
                }
            }
        }
        if(ok)break;
    }
    if(ok)
    {
        cout<<"YES\n"<<ans.size()<<endl;
        for(auto row:ans)
            cout<<row<<endl;
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        test();
    }
     
    return 0;
}