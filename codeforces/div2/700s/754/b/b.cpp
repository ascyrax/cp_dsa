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
        // ioss
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
        string s;
        cin >> s;
        string copy = s;
        sort(copy.begin(), copy.end());
        if (s == copy)
                cout << 0 << endl;
        else
        {
                cout << 1 << endl;
                int nZeros = 0, nOnes = 0;
                for (int i = 0; i < n; i++)
                {
                        if (s[i] == '0')
                                nZeros++;
                        else
                                nOnes++;
                }
                vector<int> ans;
                for (int i = 0; i < nZeros; i++)
                {
                        if (s[i] == '1')
                        {
                                ans.pb(i);
                        }
                }
                for (int i = nZeros; i < n; i++)
                {
                        if (s[i] == '0')
                        {
                                ans.pb(i);
                        }
                }
                cout << ans.size() << " ";
                for (int i : ans)
                        cout << i + 1 << " ";
                cout << endl;
        }
}

//................................
