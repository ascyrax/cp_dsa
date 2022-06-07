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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
int lnds(vector<int> const &a)
{
        int n = a.size();
        const int INF = 1e9;
        vector<int> d(n + 1, INF);
        d[0] = -INF;

        for (int i = 0; i < n; i++)
        {
                int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
                if (d[j - 1] <= a[i] && a[i] <= d[j])
                        d[j] = a[i];
        }

        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
                if (d[i] < INF)
                        ans = i;
        }
        return ans;
}
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
        }
        int ans = lnds(v);
        cout << ans << endl;
}

//................................
