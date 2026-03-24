#include<bits/stdc++.h>
using namespace std;
using ll =long long;

void test()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n - 1;
    vector<int> b;
    string s1 = "";
    auto inc = [](const vector<int>& v) {
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i] >= v[i+1])
                return false;
        }
        return true;
    };
    auto dec = [](const vector<int>& v) {
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i] <= v[i+1])
                return false;
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        bool sl = true;
        bool sr = true;
        if (b.size() >= 4) {
            vector<int> c = b;
            c.push_back(a[l]);
            if (c.size() >= 5) {
                if (inc(c) || dec(c)) {
                    sl = false;
                }
            }
            c = b;
            c.push_back(a[r]);
            if (c.size() >= 5) {
                if (inc(c) || dec(c)) {
                    sr = false;
                }
            }
        }
        if (b.size() >= 3) {
            if (sl) {
                vector<int> d = b;
                if (d.size() >= 4) {
                    d.erase(d.begin());
                }
                d.push_back(a[l]);
                bool bad = true;
                if (l + 1 <= r) {
                    vector<int> e = d;
                    e.push_back(a[l+1]);
                    bool b1 = false;
                    if (e.size() >= 5) {
                        if (inc(e) || dec(e)) {
                            b1 = true;
                        }
                    }
                    if (!b1) {
                        bad = false;
                    } else {
                        if (l + 1 < r) {
                            e = d;
                            e.push_back(a[r]);
                            bool b2 = false;
                            if (e.size() >= 5) {
                                if (inc(e) || dec(e)) {
                                    b2 = true;
                                }
                            }
                            if (!b2) {
                                bad = false;
                            }
                        }
                    }
                    if (bad) {
                        sl = false;
                    }
                }
            }
            if (sr) {
                vector<int> d = b;
                if (d.size() >= 4) {
                    d.erase(d.begin());
                }
                d.push_back(a[r]);
                bool bad = true;
                if (l <= r-1) {
                    vector<int> e = d;
                    e.push_back(a[l]);
                    bool b1 = false;
                    if (e.size() >= 5) {
                        if (inc(e) || dec(e)) {
                            b1 = true;
                        }
                    }
                    if (!b1) {
                        bad = false;
                    } else {
                        if (l < r-1) {
                            e = d;
                            e.push_back(a[r-1]);
                            bool b2 = false;
                            if (e.size() >= 5) {
                                if (inc(e) || dec(e)) {
                                    b2 = true;
                                }
                            }
                            if (!b2) {
                                bad = false;
                            }
                        }
                    }
                    if (bad) {
                        sr = false;
                    }
                }
            }
        }
        if (sl) {
            s1 += 'L';
            if (b.size() >= 4) {
                b.erase(b.begin());
            }
            b.push_back(a[l]);
            l++;
        } else if (sr) {
            s1 += 'R';
            if (b.size() >= 4) {
                b.erase(b.begin());
            }
            b.push_back(a[r]);
            r--;
        } else {
            s1 += 'L';
            if (b.size() >= 4) {
                b.erase(b.begin());
            }
            b.push_back(a[l]);
            l++;
        }
    }
    cout << s1 << "\n";
    // for(auto x:b) cout<<x<<" ";
    // cout<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) test(); 
    return 0;
}