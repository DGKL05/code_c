#include <bits/stdc++.h>
using ll =long long;
using namespace std;
const ll num=1e8;

string mull(string a,string b)//高精度乘法a,b,均为非负整数
{
    const int L=1e5;
    string s;
    int na[L],nb[L],nc[L],La=a.size(),Lb=b.size();//na存储被乘数，nb存储乘数，nc存储积
    fill(na,na+L,0);fill(nb,nb+L,0);fill(nc,nc+L,0);//将na,nb,nc都置为0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//将字符串表示的大整形数转成i整形数组表示的大整形数
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//统一处理进位
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//判断第i+j位上的数字是不是0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//将整形数组转成字符串
    return s;
}

string sub(string a,string b)//a-b
{
    const int L=1e5;
    string ans;
    int na[L]={0},nb[L]={0};
    int la=a.size(),lb=b.size();bool fa=false;
    for(int i=0;i<la;i++) na[la-1-i]=a[i]-'0';
    for(int i=0;i<lb;i++) nb[lb-1-i]=b[i]-'0';
    if(lb>la) {fa=true;}
    else if (lb==la){
        for(int i=0;i<lb;i++){
            if(nb[i]-na[i]>0) {
                //ans='-'+ans;
                fa=true;
                break;
            }
        }
    }
    int lmax=la>lb?la:lb;
    if(fa) swap(na,nb);
    for(int i=0;i<lmax;i++)
    {
        na[i]-=nb[i];
        if(na[i]<0) na[i]+=10,na[i+1]--;
    }
    while(!na[--lmax]&&lmax>0)  ;lmax++;
    for(int i=lmax-1;i>=0;i--) ans+=na[i]+'0';
    if(fa) ans='-'+ans;
    return ans;
}

int main()
{
  // 请在此输入您的代码
    string a;string b;
    cin>>a>>b;
    //a.esear(a.find('-'));
    if(a[0]=='-') a=a.substr(1);
    if(b[0]=='-') b=b.substr(1);
    //cout<<a<<' '<<b<<"\n";
    //cout<<mull(a,a)<<"\n";
    cout<<sub(mull(a,a),mull(b,b))<<"\n";
    return 0;
}