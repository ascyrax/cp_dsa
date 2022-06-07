// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        string s;
        cin >> s;
        int len = s.size();
        // cout << "len = " << len << endl;
        int x;
        cin >> x;
        // vector<set<int>> v(len, set<int>());
        vector<vector<int>> v(len, vector<int>());
        vector<vector<int>> temp(len, vector<int>());
        for (int i = 0; i < len; i++)
        {
                int flag = -1;
                if (i - x >= 0)
                {
                        if (s[i] == '0')
                        {
                                v[i - x].pb(0);
                        }
                        else
                        {
                                temp[i - x].pb(1);
                        }
                        flag = 1;
                }
                if (i + x < len)
                {
                        if (s[i] == '0')
                        {
                                v[i + x].pb(0);
                        }
                        else
                        {
                                temp[i + x].pb(1);
                        }
                        flag = 1;
                }
        }
        vector<int> ans(len, -1);

        for (int i = 0; i < len; i++)
        {
                if (temp[i][0] == 1)
                {
                        if (v[i].size() == 0)
                        {
                                ans[i] = 1;
                        }
                        else if (v[i][0] == 0)
                                ans[i] = 0;
                }
                else
                {
                        ans[i] = 0;
                }
        }
        for (int i = 0; i < len; i++)
        {
                if (s[i] == '1')
                {
                        if ((i + x < len && ans[i + x] == 1) || (i - x >= 0 && ans[i - x] == 1))
                        {
                                continue;
                        }
                        else
                        {
                                cout << -1 << endl;
                                return;
                        }
                }
                else
                {
                        continue;
                }
        }
        for (int i = 0; i < len; i++)
        {
                // cout << *v[i].begin();
                cout << ans[i];
        }
        cout << endl;
}

//................................
