#include <bits/stdc++.h>
using namespace std;
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
string g[8];
bool sum[15], dif[15], c[8];
int ans = 0;

void dfs(int r)
{ // place queen in r-th row
        if (ans % 1000000 == 0)
        {
                cout << "ans = " << ans << endl;
        }
        if (r == 8)
        {
                ++ans; // found valid placement
                return;
        }
        for (int i = 0; i < 8; ++i)
        {
                if (g[r][i] == '.' && !c[i] && !sum[i + r] && !dif[i - r + 7])
                {
                        c[i] = sum[i + r] = dif[i - r + 7] = true;
                        dfs(r + 1);
                        c[i] = sum[i + r] = dif[i - r + 7] = false;
                }
        }
}

int main()
{
        ioss
            // hello
            for (int i = 0; i < 8; ++i)

                cin >>
            g[i];
        dfs(0);
        cout << ans;
}