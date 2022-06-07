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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
pair<ll, ll> dp[251][251];
//...............................

void suraj()
{
        ll n, w;
        cin >> n >> w;

        vector<pair<double, pair<ll, ll>>> cows_by_ratio;

        for (ll i = 0; i < n; i++)
        {
                ll wi, ti;
                cin >> wi >> ti;
                double ratio = double(ti) / double(wi);
                cows_by_ratio.pb(make_pair(ratio, make_pair(ti, wi)));
        }
        sort(cows_by_ratio.rbegin(), cows_by_ratio.rend());

        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        //if the current cow was not chosen
                        if (dp[i - 1][j].first > dp[i][j].first)
                                dp[i][j] = make_pair(dp[i - 1][j].first, dp[i - 1][j].second);
                        //else
                        if (dp[i - 1][j - 1].first + cows_by_ratio[j - 1].first > dp[i][j].first)
                                dp[i][j] = make_pair(dp[i - 1][j - 1].first + cows_by_ratio[j - 1].second.first, dp[i - 1][j - 1].second + cows_by_ratio[j - 1].second.second);
                }
        }

        //binary search over all the possible ratios*1000
        // ll l = 0, r = cows_by_ratio[0].first * 1000;
        ll l = 0, r = 250 * 1000 * 1000 + 1;
        int cnt = 0;
        while (l + 1 < r)
        {
                int flag = 0;
                cnt++;
                if (cnt == 30)
                        break;
                cout << l << " " << r << endl;
                ll mid = l + (r - l) / 2;

                //if mid is achievable then search mid to r
                for (int i = 1; i <= n; i++)
                {
                        for (int j = 1; j <= n; j++)
                        {
                                if ((1000ll * dp[i][j].first) / (double)dp[i][j].second >= mid && dp[i][j].second >= w)
                                {
                                        cout << (1000ll * dp[i][j].first) / (double)dp[i][j].second << endl;
                                        l = mid;
                                        flag = 1;
                                }
                                if (flag == 1)
                                        break;
                        }
                        if (flag == 1)
                                break;
                }

                //else l to mid-1
                if (flag != 1)
                {
                        r = mid - 1;
                }
        }
        cout << l << endl;
}

//................................
