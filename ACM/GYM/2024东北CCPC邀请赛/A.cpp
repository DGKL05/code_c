#include<bits/stdc++.h>
using namespace std;
using ll =long long;
vector<ll>v1;
void test()
{
    int x, k;
	cin >> x >> k;
	if(x==1 || k==0) {
		cout << 1 << endl;
		return ;
	}
	set<int> s;
	long long sum = 0;
	while(x != 1 && k >= 0) {
		if(s.find(x*x) == s.end()) {
			sum += (1+k);
		}else{
			sum += 1;
		}
		s.insert(x);
		x = (int)sqrt(x);
		k--;
	}
	if(x == 1 && k >= 0) {
		sum++;
	}
	cout << sum << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    // cin>>T;
    while(T--) test();
    return 0;
}