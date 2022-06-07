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
        freopen("balancing.in", "r", stdin);
        freopen("balancing.out", "w", stdout);
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
        vector<int> vx, vy;
        vector<pair<int, int>> vCows;
        for (int i = 0; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                vx.pb(x);
                vy.pb(y);
                vCows.pb({x, y});
        }
        int ans = 1e9;
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        sort(vCows.begin(), vCows.end());

        for (int i : vx)
        {
                i++;
                for (int j : vy)
                {
                        j++;
                        // cout << i << " " << j << endl;
                        int bottomLeft = 0, bottomRight = 0, topLeft = 0, topRight = 0;
                        for (int k = 0; k < n; k++)
                        {
                                if (vCows[k].first < i)
                                { //left
                                        // cout << "outer if" << endl;
                                        if (vCows[k].second < j)
                                                bottomLeft++;
                                        else
                                                topLeft++;
                                }
                                else
                                {
                                        // cout << "outer else" << endl;
                                        if (vCows[k].second < j)
                                                bottomRight++;
                                        else
                                                topRight++;
                                }
                        }
                        int maxOfAllQuadrants = max(max(bottomLeft, bottomRight), max(topRight, topLeft));
                        // cout << topLeft << " " << topRight << " " << bottomRight << " " << bottomLeft << endl;
                        // cout << maxOfAllQuadrants << endl;
                        ans = min(ans, maxOfAllQuadrants);
                }
        }
        cout << ans << endl;
}

//................................
