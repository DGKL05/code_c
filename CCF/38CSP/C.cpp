#include <bits/stdc++.h>
using namespace std;
map<unsigned long long int,string> mp12,mp25;
unsigned long long int get_num(string s,int be,int len)
{
    unsigned long long int cnt=1,x=0;
    string str=s.substr(be,len);
    reverse(str.begin(),str.end());
    for(auto ch:str)
    {
        if(ch=='1')
        {
            x+=cnt;
        }
        cnt=cnt*2;
    }
    return x;
}
string low(unsigned long long int x)
{
    vector<unsigned long long int> tmp;
    unsigned long long int a,b,c,d,e;
    a=26;
    b=a*26;
    c=b*26;
    d=c*10;
    e=d*36;
    tmp.push_back(x/e);
    tmp.push_back(x%e/d);
    tmp.push_back(x%d/c);
    tmp.push_back(x%c/b);
    tmp.push_back(x%b/a);
    tmp.push_back(x%a);
    string str="";
    if(tmp[0]>=1&&tmp[0]<=10)
    {
        str+=char('0'+tmp[0]-1);
    }
    else if(tmp[0]>=11&&tmp[0]<=36)
    {
        str+=char('A'+tmp[0]-11);
    }
 
    if(tmp[1]>=0&&tmp[1]<=9)
    {
        str+=char('0'+tmp[1]);
    }
    else if(tmp[1]>=10&&tmp[1]<=35)
    {
        str+=char('A'+tmp[1]-10);
    }
 
    if(tmp[2]>=0&&tmp[2]<=9)
    {
        str+=char('0'+tmp[2]);
    }
 
    for(int i=3;i<=5;i++)
    {
        if(tmp[i]>=0&&tmp[i]<=25)
        {
            str+=char('A'+tmp[i]);
        }
    }
    return str;
}
 
void bj(string str)
{
    string pp=str;
    int len=str.size();
    if(len<11)
    {
        for(int i=1;i<=11-len;i++)
        {
            str+=" ";
        }
    }
    unsigned long long int cnt=1,x=0;
    reverse(str.begin(),str.end());
    for(auto ch:str)
    {
        if(ch>='0'&&ch<='9')
        {
            x+=(ch-'0'+1)*cnt;
        }
        else if(ch>='A'&&ch<='Z')
        {
            x+=(ch-'A'+11)*cnt;
        }
        else if(ch=='_')
        {
            x+=cnt*37;
        }
        cnt*=38;
    }
    reverse(str.begin(),str.end());
    unsigned long long int tmp=47055833459;
    unsigned long long int x1=((x*tmp)>>39);
    unsigned long long int x2=((x*tmp)>>52);
    mp25[x1]=pp;
    mp12[x2]=pp;
    //cout << x1 << " " << x2 << '\n';
}
 
string high(unsigned long long int x)
{
    string str;
    for(int i=1;i<=11;i++)
    {
        int num=x%38;
        if(num>=1&&num<=10)
        {
            str+=char('0'+num-1);
        }
        else if(num>=11&&num<=36)
        {
            str+=char('A'+num-11);
        }
        else if(num==37)
        {
            str+='_';
        }
        x/=38;
    }
    reverse(str.begin(),str.end());
    return str;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    unsigned long long int x,y,z,mx;
    mx=(1<<25);
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        if(s[0]=='0')                              //简单消息
        {
            x=get_num(s,1,28);
            y=get_num(s,29,28);
            z=get_num(s,57,15);
            if(x<mx)                               //25位散列值
            {
                if(mp25.count(x))
                {
                    cout << "#" << mp25[x] ;
                }
                else
                {
                    cout << "###" ;
                }
            }
            else                                   //短数字表示
            {
                x=x-mx;
                string tmp;
                tmp=low(x);
                bj(tmp);
                cout << tmp ;
            }
            if(y<mx)                               //25位散列值
            {
                if(mp25.count(y))
                {
                    cout << " " << "#" << mp25[y] ;
                }
                else
                {
                    cout << " " << "###" ;
                }
            }
            else                                   //短数字表示
            {
                y=y-mx;
                string tmp;
                tmp=low(y);
                bj(tmp);
                cout << " " << tmp ;
            }
            //cout << " " << z << '\n';
            //z=0;
            if(z)
            {
                cout << " " << z << '\n';
            }
            else
            {
                cout << '\n';
            }
        }
        else                                        //复杂消息
        {
            x=get_num(s,1,58);
            y=get_num(s,59,12);
            z=get_num(s,71,1);
            string ansx,ansy;
            if(z==1)
            {
                if(mp12.count(y))
                {
                    ansy+="#";
                    ansy+=mp12[y] ;
                }
                else
                {
                    ansy="###";
                }
                ansx=high(x);
                bj(ansx);
                cout << ansx << " " << ansy << '\n';
            }
            if(z==0)
            {
                if(mp12.count(y))
                {
                    ansy+="#";
                    ansy+=mp12[y] ;
                }
                else
                {
                    ansy="###";
                }
                ansx=high(x);
                bj(ansx);
                cout << ansy << " " << ansx << '\n';
            }
 
        }
    }
    return 0;
}
