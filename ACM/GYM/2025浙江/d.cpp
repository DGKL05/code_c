#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int T;
int steep[N];
int total;
vector<char> road;
bool is_true;
int n;

void dfs(int spot, int s_cnt)
{
    if (is_true)  return ;
    if (spot == 0 && s_cnt == total)
    {
        for (auto V : road) printf("%c", V);
        is_true = true;
        printf("\n");
    }

    if (s_cnt >= total) return ;

    if (steep[spot - 1] && spot - 1 >= 0)
    {
        road.push_back('L');
        steep[spot - 1] -= 1;
        dfs(spot - 1, s_cnt + 1);
        steep[spot - 1] += 1;
        road.pop_back();
    }

    if (steep[spot + 1] && spot + 1 <= n)
    {
        road.push_back('R');
        steep[spot + 1] -= 1;
        dfs(spot + 1, s_cnt + 1);
        steep[spot + 1] += 1;
        road.pop_back();
    }
    
    

}



int main()
{
    scanf("%d", &T);

    while (T -- )
    {
        scanf("%d", &n);

        is_true = false;
        total = 0;
        road.clear();
        for (int i = 0; i <= n; i ++ )
        {
            scanf("%d", &steep[i]);
            total += steep[i];
        }

        // cout << total << endl;
        if (total % 2) printf("Impossible\n");
        else 
        {
            dfs(0, 0);
            if (!is_true) printf("Impossible\n");
        }
    }

    return 0;
}
