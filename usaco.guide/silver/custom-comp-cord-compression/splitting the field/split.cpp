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
        // freopen("split.in", "r", stdin);
        // freopen("split.out", "w", stdout);
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
        ll n;
        cin >> n;
        ll minX = 1e9 + 1, minY = 1e9 + 1, maxX = 0, maxY = 0;
        vector<pair<ll, ll>> locX, locY;
        int hor = 1, ver = 1;
        for (ll i = 0; i < n; i++)
        {
                ll x, y;
                cin >> x >> y;
                locX.pb(make_pair(x, y));
                locY.pb(make_pair(y, x));

                minX = min(minX, x);
                minY = min(minY, y);
                maxX = max(maxX, x);
                maxY = max(maxY, y);
        }
        sort(locX.begin(), locX.end());
        sort(locY.begin(), locY.end());

        vector<ll> leftMax(n, 0), leftMin(n, 1e9 + 1);
        leftMax[0] = locX[0].second;
        leftMin[0] = locX[0].second;
        for (ll i = 1; i < n; i++)
        {
                leftMax[i] = max(leftMax[i - 1], locX[i].second);
                leftMin[i] = min(leftMin[i - 1], locX[i].second);
        }

        vector<ll> rightMax(n, 0), rightMin(n, 1e9 + 1);
        rightMax[n - 1] = locX[n - 1].second;
        rightMin[n - 1] = locX[n - 1].second;
        for (ll i = n - 2; i >= 0; i--)
        {
                rightMax[i] = max(rightMax[i + 1], locX[i].second);
                rightMin[i] = min(rightMin[i + 1], locX[i].second);
        }
        vector<ll> bottomMax(n, 0), bottomMin(n, 1e9 + 1);
        bottomMax[0] = locY[0].second;
        bottomMin[0] = locY[0].second;
        for (ll i = 1; i < n; i++)
        {
                bottomMax[i] = max(bottomMax[i - 1], locY[i].second);
                bottomMin[i] = min(bottomMin[i - 1], locY[i].second);
        }
        vector<ll> topMax(n, 0), topMin(n, 1e9 + 1);
        topMin[n - 1] = locY[n - 1].second;
        topMax[n - 1] = locY[n - 1].second;
        for (ll i = n - 2; i >= 0; i--)
        {
                topMax[i] = max(topMax[i + 1], locY[i].second);
                topMin[i] = min(topMin[i + 1], locY[i].second);
        }
        //////
        // for (ll i : leftMax)
        //         cout << i << " ";
        // cout << endl;
        // for (ll i : leftMin)
        //         cout << i << " ";
        // cout << endl;

        ll area = (maxY - minY) * (maxX - minX); //area for one enclosure
        ll areaSum = 2e18;
        // cout << "area = " << area << endl;
        //vertical lining between enclosures
        for (ll i = 0; i <= n - 2; i++)
        {
                ll areaBoxLeft = (locX[i].first - locX[0].first) * (leftMax[i] - leftMin[i]);
                // cout << locX[n - 1].first - locX[i + 1].first << endl
                //      << rightMax[i + 1] - rightMin[i + 1] << endl;
                ll areaBoxRight = (locX[n - 1].first - locX[i + 1].first) * (rightMax[i + 1] - rightMin[i + 1]);
                // cout << "areaBoxLeft = " << areaBoxLeft << " areaBoxRight = " << areaBoxRight << endl;
                areaSum = min(areaSum, areaBoxLeft + areaBoxRight);
        }
        // cout << "areaSum = " << areaSum << endl;
        // horizontal line between enclosures
        for (ll i = 0; i <= n - 2; i++)
        {
                ll areaBoxBottom = (locY[i].first - locY[0].first) * (bottomMax[i] - bottomMin[i]);
                ll areaBoxTop = (locY[n - 1].first - locY[i + 1].first) * (topMax[i + 1] * topMax[i + 1]);
        }

        cout << area - areaSum << endl;
}

//................................
