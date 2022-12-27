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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        ll n;
        cin >> n;

        vector<vector<ll>> grid(n, vector<ll>(5, 0));
        for (ll i = 0; i < n; i++)
        {
                for (ll j = 0; j < 5; j++)
                {
                        cin >> grid[i][j];
                }
        }

        vector<ll> colSum(5);
        for (ll j = 0; j < 5; j++)
        {
                for (ll i = 0; i < n; i++)
                {
                        colSum[j] += grid[i][j];
                }
        }
        vector<ll> goodDays;
        for (ll i = 0; i < 5; i++)
        {
                if (colSum[i] >= n / 2)
                        goodDays.pb(i);
        }
        // for (ll i : goodDays)
        //         cout << i << " ";
        // cout << endl;
        ll len = goodDays.size();
        // cout << "len = " << len << endl;
        for (ll i = 0; i < len; i++)
        {
                for (ll j = i + 1; j < len; j++)
                {
                        ll cnta = 0, cntb = 0, cntab = 0;
                        for (ll k = 0; k < n; k++)
                        {
                                if (grid[k][goodDays[i]] == 1 && grid[k][goodDays[j]] == 1)
                                {
                                        cntab++;
                                }
                                else if (grid[k][goodDays[i]] == 1)
                                {
                                        cnta++;
                                }
                                else if (grid[k][goodDays[j]] == 1)
                                {
                                        cntb++;
                                }
                        }
                        // cout << cnta << " " << cntb << " " << cntab << endl;
                        if (cnta <= n / 2 && cntb <= n / 2)
                        {
                                if ((n / 2 - cnta) + (n / 2 - cntb) == cntab)
                                {
                                        cout << "YES" << endl;
                                        return;
                                }
                                // else
                                //         flag = 0;
                        }
                        // else if (cnta > n / 2 || cntb > n / 2)
                        // {
                        //         flag = 0;
                        // }
                        // else if ()
                }
        }
        cout << "NO" << endl;
}

//................................
