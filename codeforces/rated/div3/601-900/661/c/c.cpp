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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        sort(v.begin(), v.end());
        int maxW = v[n - 1];
        int nPairs = 0;
        int ans = 0;
        for (int w = 1; w <= 2 * maxW; w++)
        {
                nPairs = 0;
                int l = 0, r = n - 1;
                while (l < r)
                {
                        if (v[l] + v[r] == w)
                        {
                                nPairs++;
                                l++;
                                r--;
                        }
                        else if (v[l] + v[r] > w)
                                r--;
                        else
                                l++;
                }
                // cout << "nPairs= " << nPairs << endl;
                ans = max(ans, nPairs);
        }
        cout << ans << endl;
}

//................................
