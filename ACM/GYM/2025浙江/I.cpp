#include<bits/stdc++.h>

using namespace std;

int T;

int main()
{
    cin >> T;
    
    while (T -- )
    {
        string a, b;
        cin >> a >> b;

        // cout << a << ' ' << b << endl;
        int a_idx = 0, b_idx = 0;
        int a_len = a.size(), b_len = b.size();
        // cout << a_len << ' ' << b_len << endl;
        bool is_true = false;
        while (a_idx < a_len || b_idx < b_len)
        {
            // cout << T << endl;
            int a_val = 0, b_val = 0;

            while (a[a_idx] != '.' && a_idx + 1 < a_len)
                a_val = a_val * 10 + (a[a_idx ++ ] - '0');
            while (b[b_idx] != '.' && b_idx + 1 < b_len)
                b_val = b_val * 10 + (b[b_idx ++ ] - '0');

            if (a_idx + 1 < a_len && b_idx + 1 < b_len)
                a_idx ++, b_idx ++ ;
            else
            {
                a_val = a_val * 10 + (a[a_idx] - '0');
                b_val = b_val * 10 + (b[b_idx] - '0');
                a_idx ++ , b_idx ++ ;
            }

            // cout << a_idx << ' ' << b_idx << endl;
            // cout << a_val << ' ' << b_val << endl;
            if (a_val < b_val) 
            {
                cout << "B" << "\n";
                is_true = true;
                break;
            }
            else if (a_val > b_val)
            {
                cout << "A" << "\n";
                is_true = true;
                break;
            }
            
        }
        if (!is_true) cout << "Equal" << "\n";
    }

    return 0;

}
