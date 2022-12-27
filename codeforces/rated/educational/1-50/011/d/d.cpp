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

//...............................

void suraj()
{
        int n;
        cin >> n;
        map<pair<int, int>, int> cnt;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                vp.pb(make_pair(x, y));
        }
        for (int i = 0; i < n; i++)
        {
                for (int j = i; j < n; j++)
                {
                        int xmid = vp[i].first + vp[j].first;
                        int ymid = vp[i].second + vp[j].second;
                        cnt[make_pair(xmid, ymid)]++;
                }
        }
        int ans = 0;
        for (auto el : cnt)
        {
                ans += (el.second * (el.second - 1)) / 2;
        }
        cout << ans << endl;
}

//................................
