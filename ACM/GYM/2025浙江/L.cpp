#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int species[N];
int p[N];

int find(int u)
{
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    
}